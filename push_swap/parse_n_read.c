/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_integer(char *av, t_stack **a, char **s)
{
	int		minus;
	long	num;

	num = 0;
	minus = 1;
	if (*av == '+' || *av == '-')
		minus = *av++ == '+' ? 1 : -1;
	if (*av < '0' || *av > '9')
		print_error(a, 0, s);
	while (*av >= '0' && *av <= '9')
	{
		num = num * 10 + (*av++ - '0');
		if (num < 0 || num > 2147483648)
			print_error(a, 0, s);
	}
	if (*av != 0 || (minus == 1 && num > 2147483647))
		print_error(a, 0, s);
	return (num * minus);
}

int		is_overlap(t_stack **a, t_stack *p, int num)
{
	t_stack *comp;

	comp = *a;
	while (comp != p)
	{
		if (comp->value == num)
			return (1);
		comp = comp->next;
	}
	return (0);
}

void	ft_split_free(char **s)
{
	int i;

	i = -1;
	while (s[++i] != 0)
		free(s[i]);
	free(s[i]);
	free(s);
}

void	add_stack_list(t_record *r, t_stack **a, t_stack **p, char **arr)
{
	t_stack *t;

	t = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (t == 0)
		print_error(a, 0, arr);
	t->value = r->b_num;
	r->min = r->min > r->b_num ? r->b_num : r->min;
	r->max = r->max < r->b_num ? r->b_num : r->max;
	t->next = 0;
	if (*a == 0)
	{
		*a = t;
		*p = t;
		return ;
	}
	(*p)->next = t;
	*p = t;
}

void	fill_a_stack(t_record *r, char **av, t_stack **a, int num)
{
	int		i;
	int		j;
	char	**arr;
	t_stack *p;

	i = 0;
	p = 0;
	while (++i < r->ac)
	{
		arr = ft_split(av[i], ' ');
		if (arr == 0)
			print_error(a, 0, 0);
		j = -1;
		while (arr[++j] != 0)
		{
			r->b_num = (int)get_integer(arr[j], a, arr);
			add_stack_list(r, a, &p, arr);
			if ((is_overlap(a, p, r->b_num)) == 1)
				print_error(a, 0, arr);
			num++;
		}
		ft_split_free(arr);
	}
	r->b_num = 0;
	r->ac = num;
}
