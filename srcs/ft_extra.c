/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:48:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:23 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	putnc(int sc, char c)
{
	int	putn;

	putn = 0;
	while (sc > 0)
	{
		ft_putchar_fd(c, 1);
		sc--;
		putn++;
	}
	return (putn);
}

int	ft_putstr_n(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && n > i)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
