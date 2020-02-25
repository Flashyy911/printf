/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:09:34 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:09:37 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(unsigned long int n, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->flags == 'q' && f->width > len_pointer(n))
		cnt += write_space(f->width - len_pointer(n));
	write(1, "0x", 2);
	write_pointer(n);
	cnt += len_pointer(n);
	if (f->flags == '-' && f->width > len_pointer(n))
		cnt += write_space(f->width - len_pointer(n));
	return (cnt);
}

int	print_pointer(t_flags *f, va_list p)
{
	int					cnt;
	unsigned long int	a;

	cnt = 0;
	a = va_arg(p, unsigned long int);
	if (f->point == 0)
		cnt += print_p(a, f);
	else
	{
		if (f->precision_len == 0)
			cnt += print_p(a, f);
	}
	return (cnt);
}
