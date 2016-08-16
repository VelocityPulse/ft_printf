/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:45:18 by                   #+#    #+#             */
/*   Updated: 2016/08/16 18:35:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conversion_a(t_data *data, char type)
{
	if (type == 's')
		BN
	else if (type == 'd' || type == 'i')
		call_putnbr(data);
	else if (type == 'D')
	else if (type == 'u')
	else if (type == 'U')
	else if (type == 'c')
	else if (type == 'x')
	else
		return (0);
	return (1);
}

static int		conversion_b(t_data *data, char type)
{
	if (type == 'X')
	else if (type == 'o')
	else if (type == 'O')
	else if (type == 'S')
	else if (type == 'C')
	else if (type == '%')
	else if (type == 'p')
	else
		return (0);
	return (1);
}

int		parse_conversion(t_data *data, char type)
{
	if (conversion_a(data, type) || conversion_b(data, type))
		return (1);
	return (0);
}

