/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:04:16 by                   #+#    #+#             */
/*   Updated: 2016/08/22 23:48:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putnbr(t_data *data)
{
	long long	n;
	t_specify	*spec;

	spec = &data->spec;
	if (spec->lenght_h == true)
		n = va_arg_h(data->ap);
	else if (spec->lenght_hh == true)
		n = va_arg_hh(data->ap);
	else if (spec->lenght_z == true)
		n = va_arg_z(data->ap);
	else if (spec->lenght_ll == true)
		n = va_arg_ll(data->ap);
	else if (spec->lenght_l == true)
		n = va_arg_l(data->ap);
	else
		n = va_arg(*data->ap, int);
	data->ret += ft_nblen_ll(n);
	ft_putnbr_ll(n);
}

/*
** valid flags :
** h hh z ll l
*/
