/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 17:21:38 by                   #+#    #+#             */
/*   Updated: 2016/08/25 21:19:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		select_lenght_help(t_specify *spec, char t)
{
	if (t == 'l')
		spec->lenght_l = true;
	else if (t == 'h')
		spec->lenght_h = true;
	else if (t == 'j')
		spec->lenght_ll = true;
	else if (t == 'z')
		spec->lenght_z = true;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

int				select_lenght(t_specify *spec, char *format)
{
	if (!ft_strncmp(format, "ll", 2))
	{
		spec->lenght_ll = true;
		return (2);
	}
	else if (!ft_strncmp(format, "hh", 2))
	{
		spec->lenght_hh = true;
		return (2);
	}
	else if (select_lenght_help(spec, *format))
		return (1);
	return (_ERROR_);
}
