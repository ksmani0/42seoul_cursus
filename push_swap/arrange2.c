/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_mid(t_stack **p, int num)
{
	int		max;
	int		min;
	t_stack	*t;

	t = *p;
	max = t->value;
	min = t->value;
	while (num-- > 0)
	{
		if (max < t->value)
			max = t->value;
		else if (min > t->value)
			min = t->value;
		t = t->next;
	}
	return (max + min) / 2;
}

void	arrange_a_digits(t_record *r, t_stack **a)
{
	t_stack *p;

	p = r->b_rest;
	if (p != 0)
	{
		r->b_num = r->b_rest->value;
		r->b_rest = r->b_rest->next;
	}
	free(p);
	if (r->a_num == 1)
	{
		ra(a, 0, 0);
		r->a_num = 0;
		return ;
	}
	p = *a;
	if (p->value > (p->next)->value)
		sa(a, 0, 0);
	ra(a, 0, 0);
	ra(a, 0, 0);
	r->a_num = 0;
}

void	arrange_b_digits(t_record *r, t_stack **a, t_stack **b)
{
	t_stack *p;

	r->pa_num -= r->b_num;
	r->a_num = r->a_rest->value;
	p = r->a_rest;
	r->a_rest = r->a_rest->next;
	free(p);
	if (r->b_num == 1)
	{
		pa(a, b, 0);
		ra(a, 0, 0);
		r->b_num = 0;
		return ;
	}
	p = *b;
	if (p->value > (p->next)->value)
		sb(b, 0, 0);
	pa(a, b, 0);
	ra(a, 0, 0);
	pa(a, b, 0);
	ra(a, 0, 0);
	r->b_num = 0;
}

void	b_to_a(t_record *r, t_stack **a, t_stack **b)
{
	int mid;

	if (r->b_num < 3)
	{
		arrange_b_digits(r, a, b);
		return ;
	}
	mid = get_mid(b, r->b_num);
	rotation_in_b(r, a, b, mid);
	add_front_stack(r, a, b, 'b');
	while (r->b_rest->next != 0 && r->rrb_num > 0)
	{
		rrb(b, 0, 0);
		r->rrb_num--;
	}
	r->rrb_num = 0;
}

void	a_to_b(t_record *r, t_stack **a, t_stack **b)
{
	int		mid;
	t_stack	*p;

	if (r->a_num < 3)
	{
		arrange_a_digits(r, a);
		return ;
	}
	mid = r->a_num == r->ac ? (r->min + r->max) / 2 : get_mid(a, r->a_num);
	rotation_in_a(r, a, b, mid);
	add_front_stack(r, a, b, 'a');
	p = *a;
	while (r->rra_num > 0 && (r->a_rest->next != 0 || p->value == r->min))
	{
		rra(a, 0, 0);
		r->rra_num--;
	}
	r->rra_num = 0;
}
