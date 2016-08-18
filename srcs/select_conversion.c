/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:45:18 by                   #+#    #+#             */
/*   Updated: 2016/08/18 19:43:13 by                  ###   ########.fr       */
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
		call_putbase(data, 10, NO_CASE);
	else if (type == 'U')
		call_putbase_l(data, 10, NO_CASE);
	else if (type == 'c' && data->spec.lenght == LENGHT_DEFAULT)
		call_putstr(data);
	else if (type == 'x')
		call_putbase(data, 16, LO_CASE);
	else
		return (_FAULT_);
	return (_SUCCES_);
}

static int		conversion_b(t_data *data, char type)
{
	if (type == 'X')
		call_putbase(data, 16, UP_CASE);
	else if (type == 'o')
		call_putbase(data, 8, NO_CASE);
	else if (type == 'O')
		call_putbase_l(data, 8, NO_CASE);
	else if ((type == 'S') || (type == 's' && data->spec.lenght == LENGHT_L))
	else if (type == 'C' || (type == 'c' && data->spec.lenght == LENGHT_L))
	else if (type == '%')
		data->ret += write(1, "%", 1);
	else if (type == 'p' && data->spec.lenght == LENGHT_DEFAULT)
		call_putpointer(data);
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

