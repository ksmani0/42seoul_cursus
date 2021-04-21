/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, char is_ss, char is_checker)
{
	t_stack *p;
	t_stack *top;
	t_stack *second;

	second = *a;
	if (second->next != 0)
	{
		top = second->next;
		p = top->next;
		*a = top;
		top->next = second;
		second->next = p;
	}
	if (is_ss == 0 && is_checker == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, char is_ss, char is_checker)
{
	t_stack *p;
	t_stack *top;
	t_stack *second;

	second = *b;
	if (second != 0 && second->next != 0)
	{
		top = second->next;
		p = top->next;
		*b = top;
		top->next = second;
		second->next = p;
	}
	if (is_ss == 0 && is_checker == 0)
		write(1, "sb\n", 3);
	else if (is_checker == 0)
		write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b, char is_checker)
{
	t_stack *b_top;
	t_stack *a_second;

	if (*b != 0)
	{
		b_top = *b;
		*b = b_top->next != 0 ? b_top->next : 0;
		a_second = *a;
		*a = b_top;
		b_top->next = a_second;
	}
	if (is_checker == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, char is_checker)
{
	t_stack *a_top;
	t_stack *b_second;

	a_top = *a;
	*a = a_top->next != 0 ? a_top->next : 0;
	b_second = *b;
	*b = a_top;
	a_top->next = b_second;
	if (is_checker == 0)
		write(1, "pb\n", 3);
}

void	free_stack(t_stack **a_or_b)
{
	t_stack *p;
	t_stack *t;

	if (*a_or_b == 0)
		return ;
	p = *a_or_b;
	while (p != 0)
	{
		t = p->next;
		free(p);
		p = t;
	}
}
