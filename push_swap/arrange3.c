/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front_stack(t_record *r, t_stack **a, t_stack **b, char c)
{
	t_stack *t;

	t = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (t == 0)
	{
		while (r->a_rest != 0)
		{
			t = r->a_rest;
			r->a_rest = r->a_rest->next;
			free(t);
		}
		while (r->b_rest != 0)
		{
			t = r->b_rest;
			r->b_rest = r->b_rest->next;
			free(t);
		}
		print_error(a, b, 0);
	}
	t->value = c == 'a' ? r->rra_num : r->rrb_num;
	t->next = c == 'a' ? r->a_rest : r->b_rest;
	if (c == 'a')
		r->a_rest = t;
	else
		r->b_rest = t;
}

void	rotation_in_b(t_record *r, t_stack **a, t_stack **b, int mid)
{
	t_stack *p;

	while (r->b_num > 0)
	{
		p = *b;
		if (p->value <= mid)
		{
			pa(a, b, 0);
			r->pa_num--;
			r->a_num++;
		}
		else
		{
			rb(b, 0, 0);
			r->rrb_num++;
		}
		r->b_num--;
	}
}

void	rotation_in_a(t_record *r, t_stack **a, t_stack **b, int mid)
{
	t_stack *p;

	while (r->a_num > 0)
	{
		p = *a;
		if (p->value <= mid)
		{
			pb(a, b, 0);
			r->pa_num++;
			r->b_num++;
		}
		else
		{
			ra(a, 0, 0);
			r->rra_num++;
		}
		r->a_num--;
	}
}
