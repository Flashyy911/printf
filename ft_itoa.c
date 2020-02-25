/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:16:20 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:16:24 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_lentnbr(int nbr)
{
	int i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		k;

	k = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && (k = 1))
		n = -n;
	i = ft_lentnbr(n);
	if (!(str = (char *)malloc(i + k + 1)))
		return (NULL);
	str[i + k] = '\0';
	(k == 1) ? str[0] = '-' : 0;
	while (n != 0)
	{
		str[i + k - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
