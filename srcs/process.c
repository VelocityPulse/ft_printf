/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 19:39:38 by                   #+#    #+#             */
/*   Updated: 2016/08/25 21:24:09 by                  ###   ########.fr       */
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
		if ((ret = select_lenght(spec, &format[i])) == 0)
			return (i);
		else if (ret == 2)
			i++;
		i++;
	}
	return (i);
}
