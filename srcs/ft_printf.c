/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/12 22:35:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	ft_putnbr(va_arg(ap, int)); BN
	ft_putnbr(va_arg(ap, int)); BN
	ft_putnbr(va_arg(ap, int)); BN
	va_end(ap);
	return (0);
}
