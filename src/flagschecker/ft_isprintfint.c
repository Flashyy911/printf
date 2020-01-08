/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintfint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:09:35 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/02 19:13:12 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

int	ft_isprintfint(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}
