/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:15:32 by                   #+#    #+#             */
/*   Updated: 2016/08/26 01:16:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putnbr_l(t_data *data)
{
	long long	n;
	t_specify	*spec;

	spec = &data->spec;
	if (spec->lenght_z == true)
		n = va_arg_z(data->ap);
	else if (spec->lenght_ll == true)
		n = va_arg_ll(data->ap);
	else
		n = va_arg(*data->ap, long);
	data->ret += ft_nblen_ll(n);
	if (spec->positive_sign == true && n >= 0)
		data->ret += write(1, "+", 1);
	ft_putnbr_ll(n);
}

/*
** valid flags :
** ll z
*/
