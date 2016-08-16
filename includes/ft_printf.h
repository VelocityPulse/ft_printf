/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/16 17:02:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "debug.h"

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_specify
{
	int		sharp;
}				t_specify;

typedef struct	s_data
{
	va_list		*ap;
	int			ret;
	char		*format;
	t_specify	spec;
}				t_data;

int				ft_printf(const char *format, ...);
int				parse_conversion(t_data *data, char type);

#endif
