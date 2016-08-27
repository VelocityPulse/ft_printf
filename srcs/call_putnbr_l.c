/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:15:32 by                   #+#    #+#             */
/*   Updated: 2016/08/27 19:57:19 by                  ###   ########.fr       */
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
	spec->nb_len += ft_nblen_ll(n) - (n < 0 ? 1 : 0);
	data->ret += spec->nb_len;
	before_printing_d(data, spec, n);
	help_putnbr(n);
	after_printing_d(data, spec);
}

/*
** valid flags :
** ll z
*/
