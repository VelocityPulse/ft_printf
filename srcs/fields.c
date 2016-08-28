/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 17:14:01 by                   #+#    #+#             */
/*   Updated: 2016/08/28 17:43:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	calculate_fields(t_specify *spec, int nblen, int *nd, int *nf)
{
	*nd = spec->dot_value - nblen;
	if (*nd < 0)
		*nd = 0;
	*nf = (spec->field_width - nblen) - spec->sign - *nd;
}
