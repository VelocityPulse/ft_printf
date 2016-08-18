/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:45:18 by                   #+#    #+#             */
/*   Updated: 2016/08/18 18:08:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conversion_a(t_data *data, char type)
{
	if (type == 's' && data->spec.lenght == LENGHT_DEFAULT)
		call_putstr(data);
	else if (type == 'd' || type == 'i')
		call_putnbr(data);
	else if (type == 'D')
		call_putnbr_l(data);
	else if (type == 'u')
	else if (type == 'U')
	else if (type == 'c')
	else if (type == 'x')
	else
		return (_FAULT_);
	return (_SUCCES_);
}

static int		conversion_b(t_data *data, char type)
{
	if (type == 'X')
	else if (type == 'o')
	else if (type == 'O')
	else if ((type == 'S') || (type == 's' && data->spec.lenght == LENGHT_L))
	else if (type == 'C')
	else if (type == '%')
	else if (type == 'p')
	else
		return (_FAULT_);
	return (_SUCCES_);
}

int		parse_conversion(t_data *data, char type)
{
	if (conversion_a(data, type) || conversion_b(data, type))
		return (_SUCCES_);
	return (_FAULT_);
}

