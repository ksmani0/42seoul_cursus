/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_record
{
	int				ac;
	int				min;
	int				max;
	int				pa_num;
	int				rra_num;
	int				rrb_num;
	int				a_num;
	int				b_num;
	t_stack			*a_rest;
	t_stack			*b_rest;
}					t_record;

/*
**push_swap.c**
*/
int					is_arranged(t_stack **a);
void				arrange_three_digits(t_record *r, t_stack **a);
void				arrage_n_print(t_record *record, t_stack **a,
					t_stack **b);
void				set_record(int ac, t_record *r);

/*
**parse_n_read.c**
*/
long				get_integer(char *av, t_stack **a, char **s);
int					is_overlap(t_stack **a, t_stack *p, int num);
void				ft_split_free(char **s);
void				add_stack_list(t_record *r, t_stack **a,
					t_stack **p, char **arr);
void				fill_a_stack(t_record *r, char **av, t_stack **a,
					int num);

/*
**arrange.c**
*/
void				arrange_five_digits2(t_stack **a);
void				arrange_five_digits(t_record *r, t_stack **a,
					t_stack **b);
int					is_descending(t_record *r, t_stack **a);
int					arrange_descending(t_record *r, t_stack **a,
					t_stack **b);
void				arrange_many_digits(t_record *r, t_stack **a,
					t_stack **b);

int					get_mid(t_stack **p, int num);
void				arrange_a_digits(t_record *r, t_stack **a);
void				arrange_b_digits(t_record *r, t_stack **a,
					t_stack **b);
void				b_to_a(t_record *r, t_stack **a, t_stack **b);
void				a_to_b(t_record *r, t_stack **a, t_stack **b);

void				add_front_stack(t_record *r, t_stack **a,
					t_stack **b, char c);
void				rotation_in_b(t_record *r, t_stack **a,
					t_stack **b, int mid);
void				rotation_in_a(t_record *r, t_stack **a,
					t_stack **b, int mid);

/*
**instruction.c**
*/
void				sa(t_stack **a, char is_ss, char is_checker);
void				sb(t_stack **b, char is_ss, char is_checker);
void				pa(t_stack **a, t_stack **b, char is_checker);
void				pb(t_stack **a, t_stack **b, char is_checker);
void				free_stack(t_stack **a_or_b);

void				ra(t_stack **a, char is_rr, char is_checker);
void				rb(t_stack **b, char is_rr, char is_checker);
void				rra(t_stack **a, char is_rrr, char is_checker);
void				rrb(t_stack **b, char is_rrr, char is_checker);
void				print_error(t_stack **a, t_stack **b, char **s);

#endif
