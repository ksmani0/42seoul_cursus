/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:05:30 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*initial_malloc(t_format **list)
{
	t_format *temp;

	if ((temp = (t_format*)malloc(sizeof(t_format) * 1)) == 0)
		return ((void*)0);
	temp->str = 0;
	ft_bzero(temp->flag, (sizeof(char) * 7));
	temp->spec = 0;
	ft_bzero(temp->num, (sizeof(char) * 21));
	temp->len = 0;
	temp->wid = 0;
	temp->prec = 0;
	temp->size = 0;
	temp->nums = 0;
	*list = temp;
	return (temp);
}

void		print_char(t_format *list)
{
	list->nums++;
	write(1, list->str++, 1);
}

void		initial_part(t_format *list)
{
	int i;

	i = 0;
	while (i < 7)
		list->flag[i++] = 0;
	list->spec = 0;
	i = 0;
	while (i < 21)
		list->num[i++] = 0;
	list->len = 0;
	list->wid = 0;
	list->prec = 0;
	list->size = 0;
}

int			str_or_format(t_format *list)
{
	while (*list->str != 0)
	{
		if (*list->str != '%')
			print_char(list);
		else if (*list->str++ == '%')
		{
			initial_part(list);
			if_flag_check(list);
			check_width_star(list, 0);
			check_prec_star(list);
			check_length(list);
			if ((check_spec(list)) == -1 || (output_spec(list)) == -1)
				return (-1);
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_format	*list;
	int			ret;

	if (format == 0 || (initial_malloc(&list)) == 0)
		return (-1);
	list->str = (char*)format;
	va_start(list->ap, format);
	if ((str_or_format(list)) == -1)
		list->nums = -1;
	va_end(list->ap);
	ret = list->nums;
	free(list);
	return (ret);
}
