/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 17:21:38 by                   #+#    #+#             */
/*   Updated: 2016/08/21 03:03:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		select_lenght(t_data *data, t_specify *spec, char *format)
{
	int		i;

	i = -1;
	while (!select_conversion(data, format[++i]))
	{
		if (!ft_strncmp(&format[i], "ll", 2))
			spec->lenght_ll = true;
		else if (!ft_strncmp(&format[i], "hh", 2))
			spec->lenght_hh = true;
		else
		{
			if (!ft_strncmp(&format[i], "l", 1))
				spec->lenght_l = true;
			else if (!ft_strncmp(&format[i], "h", 1))
				spec->lenght_h = true;
			else if (!ft_strncmp(&format[i], "j", 1))
				spec->lenght_j = true;
			else if (!ft_strncmp(&format[i], "z", 1))
				spec->lenght_z = true;
			else
				return (_ERROR_);
		}
		i++;
	}
	return (i);
}
