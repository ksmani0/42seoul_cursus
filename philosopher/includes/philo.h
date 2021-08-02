/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/07/01 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE		1
# define FALSE		0
# define FORK		2
# define EAT		3
# define SLEEP		4
# define THINK		5
# define DIE		6

# define S_FORK		"\e[32mhas taken a fork\e[39m\n"
# define S_EAT		"\e[33mis eating\e[39m\n"
# define S_SLEEP	"\e[96mis sleeping\e[39m\n"
# define S_THINK	"\e[0;35mis thinking\e[39m\n"
# define S_DIE		"\033[0;31mdied\e[39m\n"

typedef struct		s_info
{
	int				philo_nums;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	long			time_to_sleep;
	int				minimul_eat;
	unsigned long	start_time;//프로그램 시작 시간. 화면에 계속 출력
	int				all_alive;//다 살아있으면 TURE, 하나라도 죽었으면 FALSE
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_state;//이게 있어야 동시 출력 막는다
	pthread_mutex_t first_die;//이걸로 동시에 죽어 die 여러 번 출력 막음
}					t_info;

typedef struct		s_philo
{//얘가 t_info를 품어야 pthread_create() 작동시키기 좋다
	int				id;
	int				r_fork;
	int				l_fork;
	int				eat_nums;
	unsigned long	last_eat;//식사 끝난 시간
	pthread_t		thread;
	t_info			*info;
}					t_philo;

int					ft_atoi(const char *s);
int					ft_isdigit(int c);

/**utils.c**/
void				free_philos(t_philo *philos);
void				philo_thread_init(t_philo *philos, t_info *info);

/**routine.c**/
void				*daed_or_alive(void *ptr);
void				print_state(t_philo *philo, int state);
void				philo_eat_or_sleep(unsigned long time);
void				pickup_forks_to_eat(t_philo *philo);
void				*do_routine(void *ptr);

/**main.c**/
int					error_exit(char *str);
unsigned long		get_ms_time(void);
int					fill_info(int ac, char **av, t_info *info);
int					philo_mutex_malloc(t_philo **philos, t_info *info);

#endif
