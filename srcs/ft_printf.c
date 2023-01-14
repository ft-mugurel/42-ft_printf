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

  va_start(args, str);
  parsing((char *)str, args, printfstruck);
  va_end(args);
  return (printfstruck.returnThis);
}

int	main()
{
	char c = 'q';
	char v = '5';
	char b = '4';
	char n = '1';
	char *f = "test";
	int i = 21335;
	int d = 21335;


	//ft_printf("%c%c%c%c %s",c,v,b,n,f);
	ft_printf("%i\n%d\n",i,d);
}
