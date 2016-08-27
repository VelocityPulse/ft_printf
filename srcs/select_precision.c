/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 23:22:23 by                   #+#    #+#             */
/*   Updated: 2016/08/27 03:44:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		select_dot(t_specify *spec, char *format, int *i)
{
	int		index1;

	index1 = 0;
	spec->dot = true;
	if (format[index1] == '0')
	{
		index1++;
		*i += 1;
	}
	if (ft_isdigit(format[index1]))
	{
		spec->dot_value = ft_atoi(&format[index1]);
		*i += ft_nblen(spec->dot_value) - index1;
		return ;
	}
	spec->dot_value = 0;
}

static void		select_field_width(t_specify *spec, char *format, int *i)
{
	if (*format == '0')
		spec->zero_pad = true;
	else if (*format >= '1' && *format <= '9')
	{
		spec->field_width = ft_atoi(format);
		if (spec->field_width > 9)
			*i += ft_nblen(spec->field_width) - 1;
	}
}

int				select_precision(t_specify *spec, char *format, int *i)
{
	if (*format == '.' && format[1] != 0)
		select_dot(spec, &format[1], i);
	else if (ft_isdigit(*format))
		select_field_width(spec, format, i);
	else
		return (_ERROR_);
	return (_SUCCESS_);
}
