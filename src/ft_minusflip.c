/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minusflip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:51:37 by asbai-el          #+#    #+#             */
/*   Updated: 2019/12/24 10:42:55 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_minusflip(char convertion, char *str)
{
	int i;
	int j;

	if (convertion == 'd' || convertion == 'i')
	{
		i = 0;
		j = 0;
		while (str[i++])
			if (str[i] == '-' && i > 0)
			{
				while (str[j] && str[j] == ' ')
					j++;
				if (str[j] == '0')
				{
					str[j] = '-';
					str[i] = '0';
					break ;
				}
			}
	}
	return (str);
}
