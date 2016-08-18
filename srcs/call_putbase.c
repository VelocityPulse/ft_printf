/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 18:14:24 by                   #+#    #+#             */
/*   Updated: 2016/08/18 19:11:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putbase(t_data *data, int base, int caps)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*data->ap, unsigned int);
	str = ft_itoa_base(n, base);
	if (caps == UP_CASE)
		ft_upperstr(str);
	data->ret += ft_strlen(str);
	ft_putstr(str);
	ft_memdel((void **)&str);
}
