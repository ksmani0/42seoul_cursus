/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrange_five_digits2(t_stack **a)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *a;
	second = top->next;
	bottom = top->next;
	while (bottom->next != 0)
		bottom = bottom->next;
	if (top->value > bottom->value && bottom->value > second->value)
		ra(a, 0, 0);
	else if (bottom->value > top->value && top->value > second->value)
		sa(a, 0, 0);
	else if (second->value > top->value && top->value > bottom->value)
		sa(a, 0, 0);
	else if (top->value > second->value && second->value > bottom->value)
	{
		ra(a, 0, 0);
		sa(a, 0, 0);
	}
	else
	{
		rra(a, 0, 0);
		sa(a, 0, 0);
	}
}

void	arrange_five_digits(t_record *r, t_stack **a, t_stack **b)
{
	t_stack *p;

	r->pa_num = 0;
	while (1)
	{
		p = *a;
		if (p->value == r->max && (is_arranged(&p->next)) == 1)
			ra(a, 0, 0);
		else if (*b != 0 && (is_arranged(a)) == 1)
		{
			pa(a, b, 0);
			r->pa_num--;
		}
		else if (p->value == r->min || p->value == r->max)
		{
			pb(a, b, 0);
			r->pa_num++;
		}
		else if (r->pa_num < 2)
			ra(a, 0, 0);
		else
			arrange_five_digits2(a);
		if (*b == 0 && (is_arranged(a)) == 1)
			return ;
	}
}

int		is_descending(t_record *r, t_stack **a)
{
	int		before;
	t_stack *p;

	p = *a;
	if (p->value != r->max)
		return (0);
	before = p->value;
	p = p->next;
	while (p != 0)
	{
		if (before < p->value)
			return (0);
		before = p->value;
		p = p->next;
	}
	return (1);
}

int		arrange_descending(t_record *r, t_stack **a, t_stack **b)
{
	int i;

	i = r->ac;
	pb(a, b, 0);
	while (--i > 0)
	{
		pb(a, b, 0);
		rb(b, 0, 0);
	}
	i = r->ac;
	while (i-- > 0)
		pa(a, b, 0);
	return (1);
}

void	arrange_many_digits(t_record *r, t_stack **a, t_stack **b)
{
	r->a_num = r->ac;
	if ((is_arranged(a)) == 1)
		return ;
	if ((is_descending(r, a)) == 1 && (arrange_descending(r, a, b)) == 1)
		return ;
	while (r->a_num != 0)
	{
		a_to_b(r, a, b);
		if (r->pa_num == 0)
			continue ;
		b_to_a(r, a, b);
	}
}
