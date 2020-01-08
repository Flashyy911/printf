/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:09:33 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/03 22:02:24 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

char	*ft_char_to_string(int c)
{
	char *str;

	str = malloc(sizeof(c) * 1);
	str[0] = c;
	if (c == 0)
		g_zero_check++;
	str[1] = '\0';
	return (str);
}
