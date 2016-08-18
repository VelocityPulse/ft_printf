/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:15:32 by                   #+#    #+#             */
/*   Updated: 2016/08/18 18:10:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putnbr_l(t_data *data)
{
	long long	n;
	int			lenght;

	lenght = data->spec.lenght;
	if (lenght != LENGHT_DEFAULT)
		n = va_arg(*data->ap, long);
	else
		n = data->fct_lenght[lenght](data);
	data->ret += ft_nblen_l(n);
	ft_putnbr_l(n);
}
