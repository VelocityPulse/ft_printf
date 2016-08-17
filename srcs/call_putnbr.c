/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:04:16 by                   #+#    #+#             */
/*   Updated: 2016/08/17 16:57:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putnbr(t_data *data)
{
	long long	n;

	if (data->spec.lenght != LENGHT_DEFAULT)
		n = get_arg_lenght(data->ap, data->spec.lenght);
	else
		n = get_arg_conv(data->ap, data->spec.)
}
