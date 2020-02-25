/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsint2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:11:23 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:11:25 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsi_p_q(char *str, t_flags *f)
{
	int	x;

	x = 0;
	x += write_space(f->width - ft_max(ft_strlen(str), f->precision_len));
	x += write_zero(f->precision_len - ft_strlen(str));
	x += write(1, str, ft_strlen(str));
	return (x);
}

int	ft_unsi_p_m(char *str, t_flags *f)
{
	int	x;

	x = 0;
	x += write_zero(f->precision_len - ft_strlen(str));
	x += write(1, str, ft_strlen(str));
	x += write_space(f->width - ft_max(ft_strlen(str), f->precision_len));
	return (x);
}
