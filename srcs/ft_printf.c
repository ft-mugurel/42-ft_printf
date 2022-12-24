/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:48:33 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/24 04:27:19 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	parsing()
	va_arg(args, int);
	return (0);
}
