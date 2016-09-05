/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lenght.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:24:39 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:24:40 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	va_arg_l(va_list *ap)
{
	return (va_arg(*ap, long));
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

long long	va_arg_h(va_list *ap)
{
	return ((short)va_arg(*ap, long long));
}
