/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_special_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:31:36 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/05 21:39:55 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_char_special_case(t_flag_list *fs, char *arg)
{
	char	padding;

	free(arg);
	padding = (fs->zero) ? '0' : ' ';
	arg = allocnchar(padding, fs->width);
	if (!fs->minus)
	{
		arg[fs->width] = '\0';
		arg[fs->width - 1] = 0;
	}
	else
		arg[0] = 0;
	return (arg);
}
