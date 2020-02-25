/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:03:13 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/22 23:15:53 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *s)
{
	int		signe;
	long	nbr;
	long	over;

	signe = 1;
	nbr = 0;
	while (ft_isspace(*s) == 1)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		over = nbr;
		nbr = (nbr * 10) + (signe * (*s - 48));
		if (signe == 1 && over > nbr)
			return (-1);
		if (signe == -1 && over < nbr)
			return (0);
		s++;
	}
	return (nbr);
}
