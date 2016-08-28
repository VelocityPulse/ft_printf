/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 19:27:12 by                   #+#    #+#             */
/*   Updated: 2016/08/28 17:54:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putpointer(t_data *data)
{
	long long	n;
	char		*str;

	n = (long long)va_arg(*data->ap, void *);
	str = ft_itoa_base_ll(n, 16);
	ft_lowerstr(str);
	data->spec.nb_len = ft_strlen(str);
	data->ret += data->spec.nb_len;
	before_printing_p(data, &data->spec);
	if (data->spec.dot == true && data->spec.dot_value == 0 && n == 0)
		data->ret--;
	else
		ft_putstr(str);
	after_printing_d(data, &data->spec);
	ft_memdel((void **)&str);
}
