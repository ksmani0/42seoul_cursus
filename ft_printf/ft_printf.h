/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:06:17 by seungmki          #+#    #+#             */
/*   Updated: 2020/12/02 16:41:38 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

extern char						g_hex_b[17];
extern char						g_hex_s[17];

typedef unsigned short int		t_usint;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef short int				t_sint;
typedef long int				t_lint;
typedef long long int			t_llint;

/*
***flag: +-O()*#. | spec: diuxXcsp%onfge | prec: precision***
***wid: width | len: hHlL(signed char~sigend long long)***
*/

typedef struct					s_format
{
	char						*str;
	char						flag[7];
	char						spec;
	char						num[21];
	char						len;
	va_list						ap;
	int							wid;
	int							prec;
	int							size;
	int							nums;
}								t_format;

/*
***m:mantissa e:exponent s:sign***
*/

typedef union					u_dble
{
	double						value;
	struct
	{
		size_t					m : 52;
		size_t					e : 11;
		size_t					s : 1;
	}							s_int;
}								t_dble;

typedef struct					s_dble
{
	double						dv;
	char						sign;
	char						*s_div;
	char						d_bit[1024];
	char						*s_mod;
	char						m_bit[1076];
	int							d_len;
	int							m_len;
	char						*out;
	int							d_idx;
	int							m_idx;
	char						*e;
	char						esign;
	int							e_int;

}								t_sble;

typedef struct					s_deci
{
	char						s[1076];
	int							len;
}								t_deci;

/*
*****ft_printf.c*****
*/

t_format						*initial_malloc(t_format **list);
void							print_char(t_format *list);
void							initial_part(t_format *list);
int								str_or_format(t_format *list);
int								ft_printf(const char *format, ...);

/*
*****check_func.c*****
*/

void							if_flag_check(t_format *list);
void							check_width_star(t_format *list, char c);
void							check_prec_star(t_format *list);
void							check_length(t_format *list);
int								check_spec(t_format *list);

/*
*****check_length.c*****
*/

t_llint							check_llint(t_format *list);
t_ullint						check_ullint(t_format *list);
size_t							ft_llint_to_s(t_llint num, t_format *list);
size_t							ft_ullint_to_s(t_ullint num, t_format *list);

/*
*****print_di.c*****
*/

void							fill_space_or_zero(int *i, int limit, char *out,
								char s_or_z);
void							big_width_not_ngf(char *out, t_format *list,
								int len, int *i);
void							output_di(char *out, t_format *list, int len,
								int i);
int								print_di(t_format *list);
int								output_spec(t_format *list);

/*
*****print_u.c*****
*/

void							output_u(char *out, t_format *list, int len,
								int i);
int								print_u(t_format *list);
void							g_meet_sharp(t_format *list,
								t_sble *sble);
int								get_e_int(t_format *list, t_sble *tp,
								int i);
int								find_e_x(t_format *list, t_sble tp,
								int *x);

/*
*****print_x.c*****
*/

int								hex_to_str(t_ullint x, t_format *list);
void							x_big_width_not_ngf(char *out, t_format *list,
								int len, int *i);
int								print_sharp_x(char *out, t_format *list,
								int len, int i);
void							output_x(char *out, t_format *list, int len,
								int i);
int								print_x(t_format *list);

/*
*****print_o.c*****
*/

int								octal_to_str(t_ullint o, t_format *list);
void							o_big_width_not_ngf(char *out, t_format *list,
								int len, int *i);
int								print_sharp_o(char *out, t_format *list,
								int len, int i);
void							output_o(char *out, t_format *list, int len,
								int i);
int								print_o(t_format *list);

/*
*****print_npper.c*****
*/

int								print_percent(t_format *list);
int								print_n(t_format *list, t_lint *lint,
								int *o_int, t_sint *sint);
size_t							ft_arr_to_s(t_ulint adrr, t_format *list);
void							output_p(char *out, t_format *list,
								int len, int i);
int								print_p(t_format *list);

/*
*****print_c.c*****
*/

void							output_lc(t_format *list, t_uchar *out,
								t_uchar *lc_s, int len);
int								input_lc_s(wint_t lc, t_uchar *lc_s);
int								print_lc(t_format *list);
void							output_c(t_format *list, t_uchar *out,
								t_uchar c);
int								print_c(t_format *list);

/*
*****print_s.c*****
*/

void							output_s(t_format *list, t_uchar *s, int len);
void							make_nul_s(t_uchar *nul_s);
int								print_null(t_format *list);
int								print_s(t_format *list);

/*
*****print_ls.c*****
*/

int								count_lsw_size(t_format *list, wchar_t ls,
								t_uchar *new);
int								input_ls_to_us(t_format *list, wchar_t ls,
								t_uchar **out, int total);
int								count_out_num(t_format *list, wchar_t *ls,
								t_uchar **out, int *bytes);
void							output_ls(t_format *list, t_uchar *out,
								int bytes);
int								print_ls(t_format *list);

/*
*****print_f.c*****
*/

int								get_div_decimal(t_sble *sble, int i,
								char is_one);
int								parse_div(t_dble *dble, t_sble *sble);
int								check_inf_nan(t_dble *db, t_format *list,
								int i, int len);
int								free_sble(int error_or_not, t_sble *sble);
int								print_feg(t_format *list);

/*
*****parse_mod.c*****
*/

int								add_zero_to_prec(t_sble *sble, int prec,
								int i);
void							input_div_pow(t_deci *pow, char *is_one);
void							input_div_sum(char bit, t_deci *pow,
								t_deci *sum, int i);
int								get_mod_decimal(t_sble *sble, int blen,
								int i, char is_one);
int								parse_mod(t_dble *dble, t_sble *sble,
								int i, int j);

/*
*****get_e_str.c*****
*/

void							input_mod_pow(t_deci *pow, char *is_one);
void							input_mod_sum(char bit, t_deci *pow,
								t_deci *sum);
void							fill_e_num(t_sble *sble, int e, int elen);
int								move_point(t_sble *sble, int i, int elen);
int								get_e_str(t_format *list, t_sble *sble,
								int elen);

/*
*****get_f_str.c*****
*/

void							round_up(t_sble *sble, int prec);
void							rounding_meet_five(t_sble *sble, int prec);
int								round_feg(t_format *list, t_sble *sble);
int								make_out_str(t_sble *sble);
int								get_f_str(t_format *list, t_sble *sble);

/*
*****output_feg.c*****
*/

int								change_e_num(t_sble *sble, int elen,
								char *tp);
void							output_feg_sign(t_format *list,
								t_sble *sble, int *i);
void							output_decimal(t_format *list, t_sble *sble,
								int *i, int j);
void							output_feg(t_format *list, t_sble *sble,
								int i, int temp);
int								get_g_str(t_format *list, t_sble *sble,
								int p, char *is_f);

#endif
