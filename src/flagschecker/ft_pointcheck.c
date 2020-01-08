/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 04:51:39 by asbai-el          #+#    #+#             */
/*   Updated: 2019/12/24 10:47:42 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

void	ft_pointcheck(const char **format, t_flag_list *fs, va_list *va)
{
	if (**(format) == '.')
	{
		if (ft_isdigit(*(*format + 1)) || *(*format + 1) == '*')
		{
			(*format)++;
			if (ft_isdigit(**format))
			{
				fs->precision = ft_atoi((*format)++);
				while (ft_isdigit((int)**format))
					(*format)++;
			}
			else if (**(format) == '*')
			{
				fs->precision = va_arg(*va, int);
				(*format)++;
			}
		}
		fs->point = 1;
	}
}
