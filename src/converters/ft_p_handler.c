/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:07:28 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/02 19:14:36 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_printf.h"

char	*ft_p_handler(t_flag_list fs, char *arg)
{
	if (fs.precision >= 0 && ft_strlen(arg) < (size_t)fs.precision)
		arg = ft_strjoinfree(allocnchar('0', fs.precision
						- ft_strlen(arg)), arg);
	return (ft_strjoin(ft_strdup("0x"), arg));
}
