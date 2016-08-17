/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 16:19:43 by                   #+#    #+#             */
/*   Updated: 2016/08/17 16:59:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_fct_lenght(t_data *data)
{
	data->fct_lenght[LENGHT_L] = &va_arg_l;
	data->fct_lenght[LENGHT_J] = &va_arg_j;
	data->fct_lenght[LENGHT_Z] = &va_arg_z;
	data->fct_lenght[LENGHT_LL] = &va_arg_ll;
	data->fct_lenght[LENGHT_HH] = &va_arg_hh;
}
