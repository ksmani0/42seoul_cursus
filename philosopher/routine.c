/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/07/01 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_or_alive(void *ptr)
{//여기서 현재 철학자 스레드의 생존 여부 검사
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo*)ptr;
	info = philo->info;
	while (TRUE)
	{
		if (info->all_alive == FALSE ||
		philo->eat_nums == philo->info->minimul_eat)
			break ;//최소 식사에 도달하면 상태 검사 필요 없음
		pthread_mutex_lock(&info->first_die);
		if (get_ms_time() - philo->last_eat > info->time_to_die)
		{
			info->all_alive = FALSE;//여기서 철학자 죽음 표시. 다른 모니터 스레드도 감지 가능
			pthread_mutex_unlock(&info->fork[philo->r_fork]);//철학자가 1명뿐이면 pickup_forks_to_eat()에서 r_fork 잡고 lock으로
			print_state(philo, DIE);//l_fork 못 잡음. 두 포크 색인이 같고 이미 r_fork에서 lock 걸었으니까. 그래서 죽이기 전 여기서 푼다
			return (NULL);//철학자 죽음 기록하고 탈출. 한 스레드라도 죽어 탈출하면 다른 스레드 다 죽어서 끝
		}
		pthread_mutex_unlock(&info->first_die);//이거 안 하면 die가 여러 번 출력
		usleep(20);//50->20밀리세컨드씩 쉬며 검사. 시간이 길어지면 딜레이 커져서 죽는다
	}
	return (NULL);
}

void	print_state(t_philo *philo, int state)
{//이 함수에서 잡아야 dead_or_alive()에서 죽음을 기록해도 다른 상태 출력되는 걸 막을 수 있다
	unsigned long	now;
	t_info			*info;

	pthread_mutex_lock(&philo->info->print_state);//출력에도 뮤텍스 걸어 동시 출력 방지
	now = get_ms_time() - philo->info->start_time;
	info = philo->info;
	if (info->all_alive == TRUE && state == FORK)//죽은 철학자
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_FORK);
	else if (info->all_alive == TRUE && state == EAT)//없을 때만
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_EAT);
	else if (info->all_alive == TRUE && state == SLEEP)//출력
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_SLEEP);
	else if (info->all_alive == TRUE && state == THINK)
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_THINK);
	else if (state == DIE)
		printf("\e[33m%lums \e[96m%d %s", now, philo->id, S_DIE);
	pthread_mutex_unlock(&(philo->info->print_state));
}

void	philo_eat_or_sleep(unsigned long time)
{
	unsigned long end;

	end = get_ms_time() + time;
	while (end > get_ms_time())
		usleep(100);
}

void	pickup_forks_to_eat(t_philo *philo)
{
	t_info *info;

	info = philo->info;//들어온 철학자의 색인과 전 색인의 포크를 든다. 즉 해당 뮤텍스를 건다
	if ((philo->id % 2 == 0 && !pthread_mutex_lock(&info->fork[philo->l_fork]))
	|| !pthread_mutex_lock(&info->fork[philo->r_fork]))
		print_state(philo, FORK);//짝수 색인은 왼쪽, 홀수는 오른쪽 포크 집는다
	if ((philo->id % 2 == 0 && !pthread_mutex_lock(&info->fork[philo->r_fork]))
	|| !pthread_mutex_lock(&info->fork[philo->l_fork]))//철학자가 1명뿐이면 포크 색인이 [0]뿐이라
		print_state(philo, FORK);//여기서 걸려버림
	philo->last_eat = get_ms_time();//먹은 시간 기록
	print_state(philo, EAT);//모니터링에서 die된 상태로 여기 들어갈 수 있음
	philo_eat_or_sleep(info->time_to_eat);//먹는 시간동안 usleep
	pthread_mutex_unlock(&info->fork[philo->r_fork]);
	pthread_mutex_unlock(&info->fork[philo->l_fork]);
	philo->eat_nums++;//먹은 횟수 기록
}

void	*do_routine(void *ptr)
{//각 철학자 스레드가 여기로 들어옴
	t_info		*info;
	t_philo		*philo;
	pthread_t	monitor;//죽은 철학자가 있는지 검사하는 애

	philo = (t_philo*)ptr;//여기서 전달된 스레드를 알아보려면 역시 t_info를 t_philo가 포함해야 함
	info = philo->info;
	pthread_create(&monitor, NULL, dead_or_alive, philo);//감시 스레드 생성. 얘가 죽음이나 기아 감시
	while (TRUE)
	{
		if (info->all_alive == FALSE)
			break ;
		pickup_forks_to_eat(philo);
		if (info->minimul_eat != -1 &&
		info->minimul_eat == philo->eat_nums)
			break ;//최소 식사수에 도달하면 철학자는 루틴 그만둠
		print_state(philo, SLEEP);//먹고 나면 잘 시간
		philo_eat_or_sleep(info->time_to_sleep);//자는 시간 동안 usleep
		print_state(philo, THINK);//일정 시간 자고 일어나 생각. state는 항상 현 시간도 같이 출력
	}
	pthread_join(monitor, NULL);//모니터 스레드 종료되면 리소스 해제
	return (NULL);
}
