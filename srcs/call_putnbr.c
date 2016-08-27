/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:04:16 by                   #+#    #+#             */
/*   Updated: 2016/08/27 19:48:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			help_putnbr(long long n)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_putnbr_ll(922337203685477580);
		write(1, "8", 1);
	}
	else
		ft_putnbr_ll(ft_absll(n));
}

void			call_putnbr(t_data *data)
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
	spec->nb_len = ft_nblen_ll(n) - (n < 0 ? 1 : 0);
	data->ret += spec->nb_len;
	before_printing_d(data, spec, n);
	help_putnbr(n);
	after_printing_d(data, spec);
}

/*
** valid flags :
** h hh z ll l
*/
