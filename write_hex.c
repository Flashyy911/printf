/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:11:37 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:11:39 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printnbrhex(unsigned int n)
{
	if (n >= 16)
		printnbrhex(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}

void	printnbrhexup(unsigned int n)
{
	if (n >= 16)
		printnbrhexup(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'A' - 10;
	write(1, &n, 1);
}

int		write_hex(unsigned int p, t_flags *f)
{
	if (f->specifier == 'x')
		printnbrhex(p);
	else if (f->specifier == 'X')
		printnbrhexup(p);
	return (0);
}
