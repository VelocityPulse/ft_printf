/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 01:11:06 by                   #+#    #+#             */
/*   Updated: 2016/08/16 01:11:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_fct_conv(t_data *data)
{
	data->fct_conv[CONV_LO_S] = &call_putstr;
	data->fct_conv[CONV_LO_D] = &call_putnbr;
//	data->fct_conv[CONV_UP_D] = // a faire
	data->fct_conv[CONV_LO_U] = &call_putbase;
//	data->fct_conv[CONV_UP_U] = &call_putbase_long;
/*	data->fct_conv[CONV_LO_C] = 
	data->fct_conv[CONV_LO_X] = 
	data->fct_conv[CONV_UP_X] = 
	data->fct_conv[CONV_LO_O] = 
	data->fct_conv[CONV_UP_O] = 
	data->fct_conv[CONV_UP_S] = 
	data->fct_conv[CONV_UP_C] = 
	data->fct_conv[CONV_PERCENT] = 
	data->fct_conv[CONV_P] = 
*/
}
