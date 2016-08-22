/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 17:21:38 by                   #+#    #+#             */
/*   Updated: 2016/08/22 23:28:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		select_lenght_help(t_specify *spec, char *format, int i)
{
	if (!ft_strncmp(&format[i], "l", 1))
		spec->lenght_l = true;
	else if (!ft_strncmp(&format[i], "h", 1))
		spec->lenght_h = true;
	else if (!ft_strncmp(&format[i], "j", 1))
		spec->lenght_ll = true;
		//spec->lenght_j = true;
	else if (!ft_strncmp(&format[i], "z", 1))
		spec->lenght_z = true;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

int				select_lenght(t_data *data, t_specify *spec, char *format)
{
	int		i;

	i = 0;
	while (!select_conversion(data, format[i]))
	{
		if (!ft_strncmp(&format[i], "ll", 2))
		{
			spec->lenght_ll = true;
			i++;
		}
		else if (!ft_strncmp(&format[i], "hh", 2))
		{
			spec->lenght_hh = true;
			i++;
		}
		else
		{
			if (!select_lenght_help(spec, format, i))
				return (i);
		}
		i++;
	}
	return (i);
}

/*
** select_conversion() return :
** 1 : conversion find
** 0 : conversion not find
*/

