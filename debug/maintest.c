/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 21:58:22 by                   #+#    #+#             */
/*   Updated: 2016/08/22 23:42:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/ft_printf.h"
#include "blibft.h"
#include <wchar.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/debug.h"

int main()
{
	int n1;
	int n2;


	n1 = ft_printf("%hhO, %O", 0, USHRT_MAX + 2);
	BN
	n2 = printf("%hhO, %O", 0, USHRT_MAX + 2);
	printf("\n\n%d\n%d\n", n1, n2);
	return (0);
}

