/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:05:18 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:05:21 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		ft_lentnbr(unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char					*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_lentnbr(n);
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (n != 0)
	{
		str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
