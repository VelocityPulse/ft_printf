/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 00:29:59 by                   #+#    #+#             */
/*   Updated: 2016/08/30 17:31:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sharp_specify(t_specify *spec, unsigned long long n)
{
	if (spec->sharp == true)
	{
		if (n == 0)
			return (SHARP_NONE);
		else if (spec->base == 16)
		{
			if (spec->caps == UP_CASE)
				return (SHARP_HEXA_UP);
			else
				return (SHARP_HEXA_LO);
		}
		else if (spec->base == 8)
			return (SHARP_OCTAL);
	}
	return (SHARP_NONE);
}
