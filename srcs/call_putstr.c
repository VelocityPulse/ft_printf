/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:29:34 by                   #+#    #+#             */
/*   Updated: 2016/08/29 14:50:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putstr(t_data *data)
{
	char	*str;

	str = va_arg(*data->ap, char *);
	if (!str)
		str = "(null)";
	data->spec.nb_len = ft_strlen(str);
	data->ret += data->spec.nb_len;
	before_printing_s(data, &data->spec);
	ft_putstr(str);
	after_printing_s(data, &data->spec);
}
