/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress_to_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:36:33 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/02 19:14:53 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

char	*ft_adress_to_string(unsigned long nbr)
{
	char	*charn;
	int		i;

	i = 0;
	charn = ft_size_t_to_hex(nbr);
	if (charn[0] == '0' && charn[1] != '\0')
	{
		while (charn[i++])
			charn[i - 1] = charn[i];
		charn[i - 1] = '\0';
	}
	return (charn);
}
