/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:45:18 by                   #+#    #+#             */
/*   Updated: 2016/08/21 03:14:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conversion_a(t_specify *spec, char type)
{
	if (type == 'u')
	{
		spec->fct_call = &call_putbase;
		spec->base = 10;
		spec->caps = NO_CASE;
	}
	else if (type == 'U')
	{
		spec->fct_call = &call_putbase_l;
		spec->base = 10;
		spec->caps = NO_CASE;
	}
	else if (type == 'o')
	{
		spec->fct_call = &call_putbase;
		spec->base = 10;
		spec->caps = NO_CASE;
	}
	else
		return (_FAULT_);
	return (_SUCCESS_);
}

static int		conversion_b(t_specify *spec, char type)
{
	if (type == 's' && spec->lenght_l == false)
		spec->fct_call = &call_putstr;
	else if (type == 'd' || type == 'i')
		spec->fct_call = &call_putnbr;
	else if (type == 'D')
		spec->fct_call = &call_putnbr_l;
	else if (type == 'c' && spec->lenght_l == false)
		spec->fct_call = &call_putchar;
	else if (type == 'x')
	{
		spec->fct_call = &call_putbase;
		spec->base = 16;
		spec->caps = LO_CASE;
	}
	else if (type == 'X')
	{
		spec->fct_call = &call_putbase;
		spec->base = 16;
		spec->caps = UP_CASE;
	}
	else
		return (_FAULT_);
	return (_SUCCESS_);
}

static int		conversion_c(t_data *data, t_specify *spec, char type)
{
//	if ((type == 'S') || (type == 's' && spec->lenght_l == true))
//		spec->fct_call = &call_putwstr;
//	else if (type == 'C' || (type == 'c' && spec->lenght_ll == true))
//		spec->fct_call = &call_putwchar;
	if (type == '%')
		data->ret += write(1, "%", 1);
	else if (type == 'p')
		spec->fct_call = &call_putpointer;
	else if (type == 'O')
	{
		spec->fct_call = &call_putbase_l;
		spec->base = 8;
		spec->caps = NO_CASE;
	}
	else
		return (_FAULT_);
	return (_SUCCESS_);
}

int		select_conversion(t_data *data, char type)
{
	if (conversion_a(&data->spec, type) ||
		conversion_b(&data->spec, type) ||
		conversion_c(data, &data->spec, type))
	{
		data->spec.type = type;
		return (_SUCCESS_);
	}
	return (_FAULT_);
}
