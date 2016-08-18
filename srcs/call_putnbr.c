/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:04:16 by                   #+#    #+#             */
/*   Updated: 2016/08/18 17:14:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putnbr(t_data *data)
{
	long long	n;
	int			lenght;

	lenght = data->spec.lenght;
	if (lenght != LENGHT_DEFAULT)
		n = va_arg(*data->ap, int);
	else
		n = data->fct_lenght[lenght](data);
	data->ret = ft_nblen(n);
	ft_putnbr(n);
}
