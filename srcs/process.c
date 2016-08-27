/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 19:39:38 by                   #+#    #+#             */
/*   Updated: 2016/08/27 17:49:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		process_spec(t_specify *spec, char *format)
{
	int		i;

	i = 0;
	while (!select_conversion(spec, format[i]))
	{
		if (!select_lenght(spec, &format[i], &i))
		{
			if (!select_flags(spec, format[i]))
			{
				if (!select_precision(spec, &format[i], &i))
				{
					spec->fault = format[i];
					return (i);
				}
			}
		}
		i++;
	}
	return (i);
}
