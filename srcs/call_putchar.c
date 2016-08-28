/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 19:13:18 by                   #+#    #+#             */
/*   Updated: 2016/08/28 16:22:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putchar(t_data *data)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*data->ap, int);
	before_printing_c(data, &data->spec);
	data->ret += write(1, &c, 1);
	after_printing_c(data, &data->spec);
}
