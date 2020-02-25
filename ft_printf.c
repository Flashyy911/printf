/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:02:43 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:15:18 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_depspe(t_flags *f, va_list r)
{
	int	ret;

	ret = 0;
	if (f->specifier == 'c')
		ret = print_car(f, r);
	if (f->specifier == 's')
		ret = print_string(f, r);
	if (f->specifier == 'p')
		ret = print_pointer(f, r);
	if (f->specifier == 'd' || f->specifier == 'i')
		ret = print_int(f, r);
	if (f->specifier == 'u')
		ret = print_unsint(f, r);
	if (f->specifier == 'x' || f->specifier == 'X')
		ret = print_hex(f, r);
	if (f->specifier == '%')
		ret = print_percent(f);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		countprint;
	t_flags	f;
	va_list	ap;
	int		a;
	int		sp;

	countprint = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			a = parse_flags((char*)format, &f, ap);
			sp = print_depspe(&f, ap);
			format += a;
			countprint += sp;
		}
		else
		{
			write(1, format++, 1);
			countprint++;
		}
	}
	va_end(ap);
	return (countprint);
}
