/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:15:32 by                   #+#    #+#             */
/*   Updated: 2016/08/22 19:57:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putnbr_l(t_data *data)
{
	long long	n;
	t_specify	*spec;

	spec = &data->spec;
	if (spec->lenght_h == true)
		n = va_arg_h(data->ap);
	else if (spec->lenght_ll == true)
		n = va_arg_ll(data->ap);
	else
		n = (long long)va_arg(*data->ap, long);
	data->ret += ft_nblen_ll(n);
//	ft_putnbr_ll(n);
}
