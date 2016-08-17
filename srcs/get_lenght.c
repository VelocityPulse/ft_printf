/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lenght.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 16:45:52 by                   #+#    #+#             */
/*   Updated: 2016/08/17 16:53:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	va_arg_l(va_list *ap)
{
	return (va_arg(*ap, long));
}

long long	va_arg_j(va_list *ap)
{
	return (va_arg(*ap, long long));
}

long long	va_arg_z(va_list *ap)
{
	return (va_arg(*ap, size_t));
}

long long	va_arg_ll(va_list *ap)
{
	return (va_arg(*ap, long long));
}

long long	va_arg_hh(va_list *ap)
{
	return ((char)va_arg(*ap, long long));
}
