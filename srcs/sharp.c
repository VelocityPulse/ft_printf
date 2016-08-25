/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 00:29:59 by                   #+#    #+#             */
/*   Updated: 2016/08/26 00:45:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sharp(t_specify *spec)
{
	if (spec->sharp == true)
	{
		if (spec->base == 16)
		{
			if (spec->caps == UP_CASE)
				return (write(1, "0X", 2));
			else
				return (write(1, "0x", 2));
		}
		else if (spec->base == 8)
			return (write(1, "0", 1));
	}
	return (0);
}
