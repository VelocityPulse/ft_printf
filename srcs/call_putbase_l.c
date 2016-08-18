/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 19:09:31 by                   #+#    #+#             */
/*   Updated: 2016/08/18 19:11:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putbase_l(t_data *data, int base, int caps)
{
	unsigned long int	n;
	char				*str;

	n = va_arg(*data->ap, unsigned long int);
	str = ft_itoa_base_l(n, base);
	if (caps == UP_CASE)
		ft_upperstr(str);
	data->ret += ft_strlen(str);
	ft_putstr(str);
	ft_memdel((void **)&str);
}
