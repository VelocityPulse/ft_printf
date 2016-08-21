/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 19:09:31 by                   #+#    #+#             */
/*   Updated: 2016/08/21 02:09:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putbase_l(t_data *data)
{
	unsigned long long	n;
	t_specify			*spec;
	char				*str;

	spec = &data->spec;
	if (spec->lenght_ll == true)
		n = va_arg_ll(data->ap);
	else if (spec->lenght_hh == true)
		n = va_arg_hh(data->ap);
	else if (spec->lenght_h == true)
		n = va_arg_h(data->ap);
	else
		n = va_arg(*data->ap, unsigned long int);
	str = ft_itoa_base_ll(n, spec->base);
	if (spec->caps == LO_CASE)
		ft_lowerstr(str);
	data->ret += ft_strlen(str);
	ft_putstr(str);
	ft_memdel((void **)&str);
}
