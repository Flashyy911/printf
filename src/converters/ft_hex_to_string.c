/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 02:26:01 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/02 19:10:17 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

char	*ft_hex_to_char(unsigned int nbr)
{
	char	*charnbr;
	int		mod;
	char	*hex;

	hex = ft_size_t_itoa(nbr);
	charnbr = malloc(ft_strlen(hex) * sizeof(char));
	charnbr[0] = '\0';
	hex = ft_strdupfree(hex, " ABCDEF");
	while (nbr != 0)
	{
		mod = nbr % 16;
		nbr = nbr / 16;
		if (mod <= 9)
			charnbr = ft_strjoinfree(ft_itoa(mod), charnbr);
		else if (mod > 9)
			charnbr = ft_strjoinfree(allocnchar(hex[mod - 9], 1), charnbr);
	}
	if (charnbr[0] == '\0')
	{
		charnbr[0] = '0';
		charnbr[1] = '\0';
	}
	free(hex);
	return (charnbr);
}
