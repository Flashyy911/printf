/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagstructinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 01:45:11 by asbai-el          #+#    #+#             */
/*   Updated: 2019/12/24 10:45:18 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

t_flag_list	*ft_flagstructinit(void)
{
	t_flag_list *l1;

	if (!(l1 = malloc(sizeof(t_flag_list))))
		return (NULL);
	l1->convertion = ' ';
	l1->i = 0;
	l1->minus = 0;
	l1->point = 0;
	l1->precision = 0;
	l1->width = 0;
	l1->zero = 0;
	return (l1);
}
