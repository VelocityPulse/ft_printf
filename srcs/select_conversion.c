/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:45:18 by                   #+#    #+#             */
/*   Updated: 2016/08/16 01:08:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conversion_a(t_data *data, char type)
{
	if (type == 's')
		data->fct_conv[CONV_LO_S](data);
	else if (type == 'd' || type == 'i')
		data->fct_conv[CONV_LO_D](data);
	else if (type == 'D')
		data->fct_conv[CONV_UP_D](data);
	else if (type == 'u')
		data->fct_conv[CONV_LO_U](data, 8);
	else if (type == 'U')
		data->fct_conv[CONV_UP_U](data, 8);
	else if (type == 'c')
		data->fct_conv[CONV_LO_C](data);
	else if (type == 'x')
		data->fct_conv[CONV_LO_X](data);
	else
		return (0);
	return (1);
}

static int		conversion_b(t_data *data, char type)
{
	if (type == 'X')
		data->fct_conv[CONV_UP_X](data);
	else if (type == 'o')
		data->fct_conv[CONV_LO_O](data);
	else if (type == 'O')
		data->fct_conv[CONV_UP_O](data);
	else if (type == 'S')
		data->fct_conv[CONV_UP_S](data);
	else if (type == 'C')
		data->fct_conv[CONV_UP_C](data);
	else if (type == '%')
		data->fct_conv[CONV_PERCENT](data);
	else if (type == 'p')
		data->fct_conv[CONV_P](data);
	else
		return (0);
	return (1);
}

int		parse_conversion(t_data *data, char type)
{
	if (conversion_a(data, type) || conversion_b(data, type))
		return (1);
	return (0);
}

