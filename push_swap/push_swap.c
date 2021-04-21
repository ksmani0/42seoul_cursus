/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_arranged(t_stack **a)
{
	int		before;
	t_stack *p;

	p = *a;
	before = p->value;
	p = p->next;
	while (p != 0)
	{
		if (before > p->value)
			return (0);
		before = p->value;
		p = p->next;
	}
	return (1);
}

void	arrange_three_digits(t_record *r, t_stack **a)
{
	int		before;
	t_stack *p;

	p = *a;
	before = p->value;
	p = p->next;
	if ((before == r->min && p->value == r->max) ||
	(before == r->max && p->value != r->min) ||
	(before != r->max && p->value == r->min))
		sa(a, 0, 0);
	p = *a;
	before = p->value;
	p = p->next;
	if (before == r->max && p->value == r->min)
		ra(a, 0, 0);
	else if (before != r->min && p->value == r->max)
		rra(a, 0, 0);
}

void	arrage_n_print(t_record *record, t_stack **a, t_stack **b)
{
	if (record->ac == 1 || ((is_arranged(a)) == 1))
		return ;
	else if (record->ac == 2)
	{
		if ((*a)->value == record->min)
			return ;
		else
			sa(a, 0, 0);
	}
	else if (record->ac == 3)
		arrange_three_digits(record, a);
	else if (record->ac == 5)
		arrange_five_digits(record, a, b);
	else
		arrange_many_digits(record, a, b);
}

void	set_record(int ac, t_record *r)
{
	r->ac = ac;
	r->max = -2147483648;
	r->min = 2147483647;
	r->pa_num = 0;
	r->rra_num = 0;
	r->rrb_num = 0;
	r->b_num = 0;
	r->a_rest = 0;
	r->b_rest = 0;
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
		set_record(ac, &record);
		fill_a_stack(&record, av, &a, 0);
		arrage_n_print(&record, &a, &b);
		free_stack(&a);
	}
	return (0);
}
