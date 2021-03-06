/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:17:41 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/08 22:45:28 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <wchar.h>
# include <fcntl.h>

typedef unsigned char			t_uchar;
typedef unsigned short int		t_usint;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef unsigned long long int	t_ullint;
typedef short int				t_sint;
typedef long int				t_lint;
typedef long long int			t_llint;

typedef struct					s_flt
{
	char						d_bit[129];
	int							d_len;
	char						m_bit[179];
	int							m_len;
	char						m_num[11];
	int							i_mod;
	char						sign;
}								t_sflt;

typedef union					u_flt
{
	float						value;
	struct
	{
		t_uint					m : 23;
		t_uint					e : 8;
		t_uint					s : 1;
	}							s_uint;
}								t_uflt;

typedef struct					s_list
{
	void						*content;
	struct s_list				*next;
}								t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

void							*ft_memset(void *b, int c, size_t len);
void							ft_bzero(void *s, size_t n);
void							*ft_memcpy(void *dst, const void *src,
								size_t n);
void							*ft_memccpy(void *dst, const void *src, int c,
								size_t n);
void							*ft_memmove(void *dst, const void *src,
								size_t len);
void							*ft_memchr(const void *s, int c, size_t n);
int								ft_memcmp(const void *s1, const void *s2,
								size_t n);

size_t							ft_strlen(const char *s);
size_t							ft_strlcpy(char *dst, const char *src,
								size_t dstsize);
size_t							ft_strlcat(char *dst, const char *src,
								size_t dstsize);
char							*ft_strchr(const char *s, int c);
char							*ft_strrchr(const char *s, int c);
char							*ft_strnstr(const char *big, const char *little,
								size_t len);
int								ft_strncmp(const char *s1, const char *s2,
								size_t n);

int								ft_atoi(const char *s);
int								ft_isalpha(int c);
int								ft_isdigit(int c);
int								ft_isalnum(int c);
int								ft_isascii(int c);
int								ft_isprint(int c);
int								ft_tolower(int c);
int								ft_toupper(int c);

void							*ft_calloc(size_t count, size_t size);
char							*ft_strdup(const char *s);

char							*ft_substr(char const *s, unsigned int start,
								size_t len);
char							*ft_strjoin(char const *s1, char const *s2);
char							*ft_strtrim(char const *s1, char const *set);
char							**ft_split(char const *s, char c);
char							*ft_itoa(int n);
char							*ft_strmapi(char const *s,
								char (*f)(unsigned int, char));

void							ft_putchar_fd(char c, int fd);
void							ft_putstr_fd(char *s, int fd);
void							ft_putendl_fd(char *s, int fd);
void							ft_putnbr_fd(int n, int fd);

t_list							*ft_lstnew(void *content);
void							ft_lstadd_front(t_list **lst, t_list *new);
int								ft_lstsize(t_list *lst);
t_list							*ft_lstlast(t_list *lst);
void							ft_lstadd_back(t_list **lst, t_list *new);
void							ft_lstdelone(t_list *lst, void (*del)(void *));
void							ft_lstclear(t_list **lst, void (*del)(void *));
void							ft_lstiter(t_list *lst, void (*f)(void *));
t_list							*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));

/*
****circle1 get next line****
*/
int								line_str_nline(char **line, char **store,
								int w_num);
int								line_just_str(char **line, char **store);
int								get_next_line(int fd, char **line);
int								find_nline(char *store);
int								free_store(int rbytes, char **store,
								char **line);
int								paste_malloc(char **store, char *buf,
								char **line, int rbytes);

/*
****circle_one ft_printf****
*/
size_t							ft_wcharlen(const wchar_t *s);
size_t							ft_ustrlen(const t_uchar *s);
size_t							ft_intlen(int n);

/*
****circle_2 miniRT****
*/
char							*ft_strstr(char *s1, char *s2);
int								ft_strcmp(char *s1, char *s2);
char							*ft_strrev(char *str);
float							ft_atof(char *s, char *p);
double							ft_double_abs(double n);

#endif
