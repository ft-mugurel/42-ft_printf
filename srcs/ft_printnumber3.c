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

void	printnumber11(t_printf *ps, char *pthis, int nlen, int number)
{
	ps->retlen += putnc(ps->Number2 - nlen, '0');
	if (number != 0 || ps->Number2 != 0)
	{
		ft_putstr_fd(ps->After, 1);
		ps->retlen += ft_strlen(ps->After);
	}
}

int	printnumber12(t_printf *ps, char *pthis, int nlen, int number)
{
	if (ps->numberToken && ps->numberToken2)
		printnumber9(ps, pthis, nlen, number);
	else if (ps->numberToken && !ps->numberToken2)
		printnumber10(ps, pthis, nlen, number);
	else if (!ps->numberToken && ps->numberToken2)
		printnumber11(ps, pthis, nlen, number);
	else if (!ps->numberToken && !ps->numberToken2 && number == 0)
	{
		free(ps->After);
		return (0);
	}
	else
	{
		ft_putstr_fd(ps->After, 1);
		ps->retlen += ft_strlen(ps->After);
	}
	return (1);
}

int	printfsetup(char *pthis, t_printf *ps, int number)
{
	if (!ps->dotToken && ps->zeroToken)
		*pthis = '0';
	else
		*pthis = ' ';
	if ((ps->dotToken || ps->zeroToken) && number == -2147483648)
		ps->After = ft_strdup("2147483648");
	else if ((ps->zeroToken || ps->dotToken) && number < 0)
		ps->After = ft_itoa(-number);
	else
		ps->After = ft_itoa(number);
	return (ft_strlen(ps->After));
}

void	dpc(t_printf *ps, char c)
{
	ps->retlen += putnc(1, c);
	ps->Number -= 1;
}

int	porz(int n)
{
	if (n < 0)
		n = 0;
	return (n);
}
