/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:29:34 by                   #+#    #+#             */
/*   Updated: 2016/08/21 01:59:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putstr(t_data *data)
{
	char	*str;

	str = va_arg(*data->ap, char *);
	if (!str)
	{
		data->ret += write(1, "(null)", 6);
		return ;
	}
	data->ret += ft_strlen(str);
	ft_putstr(str);
}
