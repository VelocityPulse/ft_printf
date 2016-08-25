/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 19:39:38 by                   #+#    #+#             */
/*   Updated: 2016/08/25 23:49:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		process_spec(t_data *data, t_specify *spec, char *format)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (!select_conversion(data, format[i]))
	{
		if (!select_lenght(spec, &format[i], &i))
		{
			if (!select_flags(spec, format[i]))
				;
		}
		i++;
	}
	return (i);
}