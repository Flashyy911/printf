/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:32:37 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/05 21:39:14 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_getargs(const char **format, va_list *va)
{
	t_flag_list *fs;

	fs = ft_flagstructinit();
	while (ft_isflag(**(format)))
	{
		if (fs->minus == 0)
			fs->minus = ft_minuscheck(**(format));
		if (fs->zero == 0)
			fs->zero = ft_zerocheck(**(format));
		if (fs->point == 0)
			ft_pointcheck(format, fs, va);
		if (((ft_isdigit(**format)) && **(format) != '0') || **(format) == '*')
		{
			if (ft_isdigit(**format))
				fs->width = ft_atoi(*(format));
			else if (**(format) == '*')
				fs->width = va_arg(*va, int);
			while (ft_isdigit(*(*format + 1)))
				(*format)++;
		}
		if (ft_isflag(**(format)))
			(*format)++;
	}
	fs->convertion = **(format);
	return (setstr(fs, ft_gettype(fs->convertion, va)));
}

char	*allocnchar(char c, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(c) * n + 1);
	while ((size_t)i < n)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*setstr(t_flag_list *fs, char *arg)
{
	char	padding;

	if (fs->convertion == 'c' && arg[0] == 0)
	{
		arg = ft_char_special_case(fs, arg);
		free(fs);
		return (arg);
	}
	if (!fs->precision && fs->point && !fs->width && !ft_strcmp("0", arg)
			&& (fs->convertion == 'd' || fs->convertion == 'i'))
		arg = ft_strdupfree(arg, "");
	padding = ft_specialcases(fs, arg);
	if (fs->convertion == 'p')
		arg = ft_p_handler(*fs, arg);
	else if ((fs->precision >= 0 && (size_t)fs->precision > ft_strlen(arg)))
		arg = (ft_isprintfint(fs->convertion)) ? ft_strjoinfree(allocnchar('0',
				fs->precision - ft_strlen(arg)), arg) : ft_strjoinfree(
			allocnchar(' ', fs->precision - ft_strlen(arg)), arg);
	fs->width = (fs->width >= 0 && ft_strlen(arg) < (size_t)fs->width) ?
		((size_t)fs->width - ft_strlen(arg)) : 0;
	arg = (fs->minus) ? ft_strjoinfree(arg, allocnchar(padding, fs->width)) :
		ft_strjoinfree(allocnchar(padding, fs->width), arg);
	ft_minusflip(fs->convertion, arg);
	free(fs);
	return (arg);
}
