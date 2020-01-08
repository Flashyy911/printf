/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:24:37 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/08 20:12:55 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

void	*ft_gettype(char flag, va_list *va)
{
	char *str;

	if (flag == 'c')
		return (ft_char_to_string(va_arg(*va, int)));
	if (flag == 's')
	{
		str = va_arg(*va, char*);
		if (str == NULL)
			return (ft_strdup("(null)"));
		return (ft_strdup(str));
	}
	else if (flag == 'p')
		return (ft_adress_to_string(va_arg(*va, size_t)));
	else if (flag == 'd' || flag == 'i')
		return (ft_itoa(va_arg(*va, int)));
	else if (flag == 'u')
		return (ft_size_t_itoa(va_arg(*va, unsigned int)));
	else if (flag == 'x')
		return (ft_min_hex_to_char(va_arg(*va, unsigned int)));
	else if (flag == 'X')
		return (ft_hex_to_char(va_arg(*va, unsigned int)));
	else if (flag == '%')
		return (ft_strdup("%"));
	return (ft_strdup("null"));
}
