/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/07/01 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			free_philos(t_philo *philos)
{
	int		i;
	t_info	*info;

	i = -1;
	info = philos->info;
	while (++i < info->philo_nums)
		pthread_mutex_destroy(&info->fork[i]);//뮤텍스 개체 파괴
	pthread_mutex_destroy(&info->print_state);
	pthread_mutex_destroy(&info->first_die);
	free(info->fork);
	free(philos);
}

void			philo_thread_init(t_philo *philos, t_info *info)
{
	int i;

	i = 0;
	while (i < info->philo_nums)
	{//철학자 수만큼 반복문 돌면서 변수 채울 거 채우고 뮤텍스 초기화, 스레드 생성
		philos[i].id = i + 1;
		philos[i].r_fork = i;//오른쪽 포크는 색인대로
		if (i == 0)//왼쪽 포크는 현재 철학자 전 순서의 철학자 색인 대입
			philos[i].l_fork = info->philo_nums - 1;
		else//그럼 0번 철학자는 n-1번 색인이 왼쪽 포크가 된다
			philos[i].l_fork = i - 1;
		philos[i].eat_nums = 0;
		philos[i].last_eat = get_ms_time();//처음에는 스레드 생성 시간을 대입
		philos[i].info = info;
		pthread_create(&philos[i].thread, NULL, do_routine, &philos[i]);//스레드 생성
		//pthread_detach(philos[i].thread);//생성된 스레드가 종료되면 자동으로 자원 해제되게 한다. detach 옵션 붙기 전에 스레드가 죽어도 아래 join()이 해제 담당
		//usleep(20);//잠깐씩 간격 주며 스레드 생성
		i++;
	}
	i = -1;
	while (++i < info->philo_nums)
		pthread_join(philos[i].thread, NULL);//스레드가 종료되면 자원 해제. do_routine() 반환값이 없으면 null
}
