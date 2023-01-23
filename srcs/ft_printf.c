/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:48:33 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:41:34 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf(const char *str, ...)
{
  va_list args;
  t_printf printfstruck;

  makeallfalse(&printfstruck);
	printfstruck.returnThis = 0;
  va_start(args, str);
  parsing((char *)str, args, &printfstruck);
  va_end(args);
  return (printfstruck.returnThis);
}

void	makeallfalse(t_printf *printfstruck)
{
	printfstruck->numberToken = False;
	printfstruck->numberToken2 = False;
	printfstruck->minusToken = False;
	printfstruck->plusToken = False;
	printfstruck->zeroToken = False;
	printfstruck->hastagToken = False;
	printfstruck->dotToken = False;
	printfstruck->spaceToken = False;
	printfstruck->printed = False;
}
/*
#include <stdio.h>

int	main()
{
	printf("TEST1\n");
	ft_printf("-------%d-------\n",			15);
	printf("-------%d-------\n",			15);
	ft_printf("-----------------------\n\n");
	
	printf("TEST2\n");
	ft_printf("-------%5d-------\n", 		15);
	printf("-------%5d-------\n", 		15);
	ft_printf("-----------------------\n\n");

	printf("TEST3\n");
	ft_printf("-------%3d-------\n", 		12345);
	printf("-------%3d-------\n", 		12345);
	ft_printf("-----------------------\n\n");
	
	printf("TEST4\n");
	ft_printf("-------%d-------\n",			15);
	printf("-------%d-------\n",			15);
	ft_printf("-----------------------\n\n");

	printf("TEST5\n");
	ft_printf("-------%-5d-------\n",		15);
	printf("-------%-5d-------\n",		15);
	ft_printf("-----------------------\n\n");
	
	printf("TEST6\n");
	ft_printf("-------%05d-------\n",		15);
	printf("-------%05d-------\n",		15);
	ft_printf("-----------------------\n\n");
	
	printf("TEST7\n");
	ft_printf("-------%03d-------\n",		12345);
	printf("-------%03d-------\n",		12345);
	ft_printf("-----------------------\n\n");
	
	printf("TEST8\n");
	ft_printf("-------%d-------\n",		15);
	printf("-------%d-------\n",		15);
	ft_printf("-----------------------\n\n");
	
	printf("TEST9\n");
	ft_printf("-------%+d-------\n",		15);
	printf("-------%+d-------\n",		15);
	ft_printf("-----------------------\n\n");
	
	printf("TEST10\n");
	ft_printf("-------%d-------\n",		-15);
	printf("-------%d-------\n",		-15);
	ft_printf("-----------------------\n\n");
	
	printf("TEST11\n");
	ft_printf("-------%+d-------\n",		-15);
	printf("-------%+d-------\n",		-15);
	ft_printf("-----------------------\n\n");

	printf("TEST12\n");
	ft_printf("-------% d-------\n",			15);
	printf("-------% d-------\n",			15);
	ft_printf("-----------------------\n\n");

	printf("TEST13\n");
	ft_printf("-------% d-------\n",			-15);
	printf("-------% d-------\n",			-15);
	ft_printf("-----------------------\n\n");

	printf("TEST14\n");
	ft_printf("-------%5d-------\n",			755);
	printf("-------%5d-------\n",			755);
	ft_printf("-----------------------\n\n");

	printf("TEST15\n");
	ft_printf("-------%.5d-------\n",			15);
	printf("-------%.5d-------\n",			15);
	ft_printf("-----------------------\n\n");

	printf("TEST16\n");
	ft_printf("-------%.2d-------\n",			755);
	printf("-------%.2d-------\n",			755);
	ft_printf("-----------------------\n\n");

	printf("TEST17\n");
	ft_printf("-------%.5d-------\n",			-15);
	   printf("-------%.5d-------\n",			-15);
	ft_printf("-----------------------\n\n");

	printf("TEST18\n");
	ft_printf("-------%7.5d-------\n",			15);
	printf("-------%7.5d-------\n",			15);
	ft_printf("-----------------------\n\n");

	printf("TEST19\n");
	ft_printf("-------% 5d-------\n",			15);
	printf("-------% 5d-------\n",			15);
	ft_printf("-----------------------\n\n");

	printf("TEST18\n");
	ft_printf("-------% 7.5d-------\n",			15);
	printf("-------% 7.5d-------\n",			15);
	ft_printf("-----------------------\n\n");

	printf("TEST18\n");
	ft_printf("-------%7.5 d-------\n",			15);
	printf("-------%7.5 d-------\n",			15);
	ft_printf("-----------------------\n\n");
}

*/
