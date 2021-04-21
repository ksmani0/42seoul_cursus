/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:48:57 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/04 18:14:29 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *p;

	if (lst == 0 || new == 0)
		return ;
	else if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != 0)
		p = p->next;
	p->next = new;
}
