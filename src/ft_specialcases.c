/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specialcases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:54:41 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/02 19:04:12 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	ft_specialcases(t_flag_list *fs, char *arg)
{
	char padding;

	if (fs->precision == 0 && ft_isprintfstring(fs->convertion) && fs->point)
		arg[0] = '\0';
	if (fs->point && fs->convertion == 'p' && arg[0] == '0' && arg[1] == '\0')
		arg[0] = '\0';
	fs->minus = fs->width < 0 ? 1 : fs->minus;
	fs->zero = fs->width < 0 ? 0 : fs->zero;
	if (fs->width < 0)
		fs->width *= -1;
	if (arg[0] == '-' && (fs->convertion == 'd' || fs->convertion == 'i')
			&& fs->precision > 0)
		fs->precision += 1;
	if (fs->point == 1 && fs->convertion == 's')
		if ((size_t)fs->precision <= ft_strlen(arg) && fs->precision != 0)
			arg[fs->precision] = '\0';
	fs->precision = ((fs->convertion == 's' || fs->convertion == 'c')
			&& (size_t)fs->precision > ft_strlen(arg)) ? 0 : fs->precision;
	padding = (fs->zero == 1 && fs->precision <= 0 && !fs->minus) ? '0' : ' ';
	padding = ((fs->zero && fs->precision >= 0
				&& fs->point)) ? ' ' : padding;
	padding = (fs->convertion == 's' && fs->zero && !fs->minus) ? '0' : padding;
	return (padding);
}
