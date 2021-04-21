/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, char is_rr, char is_checker)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *a;
	if (top->next != 0)
	{
		second = top->next;
		bottom = top->next;
		while (bottom->next != 0)
			bottom = bottom->next;
		bottom->next = top;
		top->next = 0;
		*a = second;
	}
	if (is_rr == 0 && is_checker == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, char is_rr, char is_checker)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *b;
	if (top != 0 && top->next != 0)
	{
		second = top->next;
		bottom = top->next;
		while (bottom->next != 0)
			bottom = bottom->next;
		bottom->next = top;
		top->next = 0;
		*b = second;
	}
	if (is_rr == 0 && is_checker == 0)
		write(1, "rb\n", 3);
	else if (is_checker == 0)
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, char is_rrr, char is_checker)
{
	t_stack *top;
	t_stack *pre_bottom;
	t_stack *bottom;

	top = *a;
	if (top->next != 0)
	{
		bottom = top;
		while ((bottom->next)->next != 0)
			bottom = bottom->next;
		pre_bottom = bottom;
		bottom = bottom->next;
		pre_bottom->next = 0;
		*a = bottom;
		bottom->next = top;
	}
	if (is_rrr == 0 && is_checker == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, char is_rrr, char is_checker)
{
	t_stack *top;
	t_stack *pre_bottom;
	t_stack *bottom;

	top = *b;
	if (top != 0 && top->next != 0)
	{
		bottom = top;
		while ((bottom->next)->next != 0)
			bottom = bottom->next;
		pre_bottom = bottom;
		bottom = bottom->next;
		pre_bottom->next = 0;
		*b = bottom;
		bottom->next = top;
	}
	if (is_rrr == 0 && is_checker == 0)
		write(1, "rrb\n", 4);
	else if (is_checker == 0)
		write(1, "rrr\n", 4);
}

void	print_error(t_stack **a, t_stack **b, char **s)
{
	int i;

	if (a != 0)
		free_stack(a);
	if (b != 0)
		free_stack(b);
	if (s != 0)
	{
		i = -1;
		while (s[++i] != 0)
			free(s[i]);
		free(s[i]);
		free(s);
	}
	write(2, "Error\n", 6);
	exit(0);
}
