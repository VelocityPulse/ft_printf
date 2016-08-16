/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 17:21:38 by                   #+#    #+#             */
/*   Updated: 2016/08/16 17:57:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		select_lenght(t_specify *spec, char *format)
{
	spec->lenght = LENGHT_DEFAULT;
	if (!ft_strncmp(format, "l", 1))
		spec->lenght = LENGHT_L;
	else if (!ft_strncmp(format, "h", 1))
		spec->lenght = LENGHT_H;
	else if (!ft_strncmp(format, "j", 1))
		spec->lenght = LENGHT_J;
	else if (!ft_strncmp(format, "z", 1))
		spec->lenght = LENGHT_Z;
	else
	{
		if (!ft_strncmp(format, "ll", 2))
			spec->lenght = LENGHT_LL;
		else if (!ft_strncmp(format, "hh", 2))
			spec->lenght = LENGHT_HH;
		else
			return (0);
		return (2);
	}
	return (1);
}
