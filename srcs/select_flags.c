/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 23:10:57 by                   #+#    #+#             */
/*   Updated: 2016/08/25 23:44:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		select_flags(t_specify *spec, char type)
{
	if (type == '#')
		spec->sharp = true;
	else if (type == '+')
		spec->positive_sign = true;
	else if (type == '-')
		spec->negative_sign = true;
	else if (type == ' ')
		spec->space = true;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}
