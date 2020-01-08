/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:10:13 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/05 21:34:53 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	char		*output;
	va_list		va;
	int			i;
	int			len;

	g_zero_check = 0;
	len = 0;
	va_start(va, format);
	while (*format)
		if (*format == '%')
		{
			format++;
			output = ft_getargs(&format, &va);
			ft_help(&i, &len, output);
			format++;
		}
		else
		{
			ft_putchar(*(format++));
			len++;
		}
	va_end(va);
	return (len);
}

void	ft_help(int *i, int *len, char *output)
{
	*i = 0;
	while (*(output + *i) || g_zero_check)
	{
		g_zero_check = *(output + *i) == 0 ? g_zero_check - 1 : g_zero_check;
		ft_putchar(*(output + (*i)++));
	}
	*len += *i;
	free(output);
	g_zero_check = 0;
}
