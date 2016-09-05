/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:23:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:23:15 by cchameyr         ###   ########.fr       */
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
	help_putnbr(data, n);
	after_printing_d(data, spec);
}

/*
** valid flags :
** ll z
*/
