/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 19:27:12 by                   #+#    #+#             */
/*   Updated: 2016/08/21 02:17:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putpointer(t_data *data)
{
	long long	n;
	char		*str;

	n = (long long)va_arg(*data->ap, void *);
	data->ret += write(1, "0x", 2);
	str = ft_itoa_base_ll(n, 16);
	ft_lowerstr(str);
	data->ret += ft_strlen(str);
	ft_putstr(str);
	ft_memdel((void **)&str);
}
