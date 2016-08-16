/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:18:25 by                   #+#    #+#             */
/*   Updated: 2016/08/16 01:07:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putbase(t_data *data, int base)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*data->ap, unsigned int);
	str = ft_itoa_base(n, base);
	data->ret += ft_strlen(str);
	ft_putstr(str);
	ft_memdel((void **)&str);
}
