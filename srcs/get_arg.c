/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:57:03 by                   #+#    #+#             */
/*   Updated: 2016/08/16 19:08:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	get_arg_nbr(va_list *ap, int lenght)
{
	long long	n;

	if (lenght == LENGHT_L)
		n = (long long)va_arg(*ap, long);
	else if (lenght == LENGHT_H)
		n = va_arg(*ap, long long);

	// condition "DEFAULT" a prendre en compte soit ici soit dans le call_putnbr
	return (n);
}
