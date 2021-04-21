/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_n_arrage2(t_stack **a, t_stack **b, char *line)
{
	if ((ft_strcmp("ra", line)) == 0)
		ra(a, 0, 1);
	else if ((ft_strcmp("rb", line)) == 0)
		rb(b, 0, 1);
	else if ((ft_strcmp("rr", line)) == 0)
	{
		ra(a, 1, 1);
		rb(b, 1, 1);
	}
	else if ((ft_strcmp("rra", line)) == 0)
		rra(a, 0, 1);
	else if ((ft_strcmp("rrb", line)) == 0)
		rrb(b, 0, 1);
	else if ((ft_strcmp("rrr", line)) == 0)
	{
		rra(a, 1, 1);
		rrb(b, 1, 1);
	}
	else
	{
		free(line);
		print_error(a, b, 0);
	}
}

void	read_n_arrage(t_stack **a, t_stack **b, char *line)
{
	int rbytes;

	while ((rbytes = get_next_line(0, &line)) > 0)
	{
		if ((ft_strcmp("sa", line)) == 0)
			sa(a, 0, 1);
		else if ((ft_strcmp("sb", line)) == 0)
			sb(b, 0, 1);
		else if ((ft_strcmp("ss", line)) == 0)
		{
			sa(a, 1, 1);
			sb(b, 1, 1);
		}
		else if ((ft_strcmp("pa", line)) == 0)
			pa(a, b, 1);
		else if ((ft_strcmp("pb", line)) == 0)
			pb(a, b, 1);
		else
			read_n_arrage2(a, b, line);
		free(line);
	}
	free(line);
	if (rbytes == -1)
		print_error(a, b, 0);
}

void	print_result(t_stack **a, t_stack **b)
{
	int		before;
	t_stack	*p;

	p = *a;
	before = p->value;
	p = p->next;
	while (p != 0)
	{
		if (before >= p->value || *b != 0)
		{
			write(1, "KO\n", 3);
			free_stack(b);
			return ;
		}
		before = p->value;
		p = p->next;
	}
	write(1, "OK\n", 3);
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_record	record;

	if (ac >= 2)
	{
		a = 0;
		b = 0;
		record.ac = ac;
		record.max = -2147483648;
		record.min = 2147483647;
		fill_a_stack(&record, av, &a, 0);
		read_n_arrage(&a, &b, 0);
		print_result(&a, &b);
		free_stack(&a);
	}
	return (0);
}
