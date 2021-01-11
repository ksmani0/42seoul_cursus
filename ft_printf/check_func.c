/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:53:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_flag_check(t_format *list)
{
	while (1)
	{
		if (*list->str == '+')
			list->flag[0] = 1;
		else if (*list->str == '-')
			list->flag[1] = 1;
		else if (*list->str == '0')
			list->flag[2] = 1;
		else if (*list->str == ' ')
			list->flag[3] = 1;
		else if (*list->str == '*')
			list->flag[4] = 1;
		else if (*list->str == '#')
			list->flag[5] = 1;
		else
			return ;
		list->str++;
	}
}

void	check_width_star(t_format *list, char c)
{
	c = *list->str;
	if (c != '.' && !(c >= '0' && c <= '9') && !(c >= 'c' && c <= 'g')
	&& c != '%' && c != 'i' && c != 'n' && c != 'o' && c != 'p' &&
	c != 's' && c != 'u' && c != 'x' && c != 'X' && c != 'l' && c != 'h')
		return ;
	list->flag[6] = c == '.' ? 1 : 0;
	if (list->flag[4] == 0 && c == '.')
	{
		list->str++;
		return ;
	}
	else if (list->flag[4] == 1)
	{
		list->wid = va_arg(list->ap, int);
		list->flag[1] = list->wid < 0 ? 1 : list->flag[1];
		list->wid = list->wid < 0 ? list->wid * -1 : list->wid;
		list->str = *list->str == '.' ? list->str + 1 : list->str;
		return ;
	}
	while (*list->str >= '0' && *list->str <= '9')
		list->wid = list->wid * 10 + (*list->str++ - '0');
	list->flag[6] = *list->str == '.' ? 1 : 0;
	list->str = *list->str == '.' ? list->str + 1 : list->str;
}

void	check_prec_star(t_format *list)
{
	int p;

	p = 0;
	if (*list->str != '*' && !(*list->str >= '0' && *list->str <= '9'))
		return ;
	if (*list->str == '*')
	{
		list->flag[4] = 1;
		p = va_arg(list->ap, int);
		list->prec = p < 0 ? 0 : p;
		list->flag[6] = p < 0 ? 0 : list->flag[6];
		list->num[0] = p < 0 ? '-' : list->num[0];
		list->str++;
		return ;
	}
	while (*list->str >= '0' && *list->str <= '9')
		p = p * 10 + (*list->str++ - '0');
	list->prec = p;
}

void	check_length(t_format *list)
{
	t_format *lp;

	lp = list;
	if (lp->flag[1] == 1)
		lp->flag[2] = 0;
	if (lp->flag[0] == 1)
		lp->flag[3] = 0;
	if (*lp->str == 'h' && *(lp->str + 1) == 'h')
		lp->len = 'H';
	else if (*lp->str == 'h' && *(lp->str + 1) != 'h')
		lp->len = 'h';
	else if (*lp->str == 'l' && *(lp->str + 1) != 'l')
		lp->len = 'l';
	else if (*lp->str == 'l' && *(lp->str + 1) == 'l')
		lp->len = 'L';
	else
		return ;
	lp->str = (lp->len == 'h' || lp->len == 'l') ? lp->str + 1 : lp->str + 2;
}

int		check_spec(t_format *list)
{
	char c;

	c = *list->str;
	if ((c >= 'c' && c <= 'g') || c == '%')
		list->spec = c;
	else if (c == 'i' || c == 'n' || c == 'o' || c == 'p'
	|| c == 's' || c == 'u' || c == 'x' || c == 'X')
		list->spec = c;
	else
		return (-1);
	list->str++;
	return (1);
}
