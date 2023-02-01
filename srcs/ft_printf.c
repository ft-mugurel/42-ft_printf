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
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_printf	printfstruck;

	makeallfalse(&printfstruck);
	printfstruck.retlen = 0;
	va_start(args, str);
	parsing((char *)str, args, &printfstruck);
	va_end(args);
	return (printfstruck.retlen);
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
