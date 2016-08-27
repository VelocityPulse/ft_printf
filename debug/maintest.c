/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 21:58:22 by                   #+#    #+#             */
/*   Updated: 2016/08/27 04:04:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include "blibft.h"
#include <wchar.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/debug.h"

int main()
{
	int n1;
	int n2;
	char mask[32];

	n1 = ft_printf("|%4.hd|\n", 12345);
	
	n2 =    printf("|%4.hd|\n", 12345);

//	printf("|%+010.5d|\n", 4);
	BN

	printf("%d\n%d\n", n1, n2);
	return (0);
}


//	ft_printf("%S\n", L"😆 😎 😵 😗 😈 🐻 💓 🌼");

