/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:10:21 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/05 21:42:12 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

int						g_zero_check;
typedef struct			s_flag_list
{
	char				convertion;
	int					zero;
	int					point;
	int					minus;
	int					width;
	int					precision;
	int					i;
}						t_flag_list;
void					ft_help(int *i, int *len, char *output);
char					*ft_char_special_case(t_flag_list	*fs, char	*arg);
int						ft_isprintfchar(char c);
int						ft_isprintfint(char c);
int						ft_isprintfstring(char c);
char					*ft_size_t_to_hex(unsigned long nbr);
char					*ft_char_to_string(int c);
char					*ft_min_hex_to_char(unsigned int nbr);
char					ft_specialcases(t_flag_list *fs, char *arg);
char					*ft_adress_to_string(unsigned long nbr);
char					*ft_hex_to_char(unsigned int nbr);
t_flag_list				*ft_flagstructinit(void);
char					*ft_minusflip(char convertion, char *str);
int						ft_minuscheck(char format);
int						ft_zerocheck(char format);
void					ft_pointcheck(const char **format, t_flag_list *fs
										, va_list *va);
int						ft_isflag(char format);
int						ft_printf(const char *format, ...);
char					*ft_getargs(const char **format, va_list *va);
void					*ft_gettype(char flag, va_list *va);
char					*allocnchar(char c, size_t n);
char					*setstr(t_flag_list *fs, char *arg);
char					*ft_strjoinfree(char *s1, char *s2);
char					*ft_minusflip(char convertion, char *str);
char					*ft_p_handler(t_flag_list fs, char *arg);
#endif
