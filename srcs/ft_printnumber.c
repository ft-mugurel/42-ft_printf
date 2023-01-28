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

int	printnumber(int number, t_printf *ps)
{
	char	pthis;
	int		nlen;

	nlen = printfsetup(&pthis, ps, number);
	printnumber2(ps, &pthis, ps->After, nlen);
	if (!ps->minusToken && !ps->dotToken)
		printnumber3(ps, &pthis, nlen, number);
	if (ps->dotToken && !ps->minusToken)
		printnumber8(ps, &pthis, nlen, number);
	else if (ps->dotToken && ps->minusToken)
	{
		if (number < 0)
		{
			ps->retlen += putnc(1, '-');
			ps->Number -= 1;
		}
		if (!printnumber12(ps, &pthis, nlen, number))
			return (0);
	}
	ps->printed = True;
	free(ps->After);
	return (ps->retlen);
}

void	printnumber2(t_printf *ps, char *pthis, char *str, int nlen)
{
	if (ps->minusToken && !ps->dotToken)
	{
		if (ps->numberToken)
		{
			ft_putstr_fd(str, 1);
			ps->retlen += ft_strlen(str);
			ps->retlen += putnc(ps->Number - nlen, *pthis);
		}
		else
		{
			ft_putstr_fd(str, 1);
			ps->retlen += ft_strlen(str);
		}
	}
}

void	printnumber3(t_printf *ps, char *pthis, int nlen, int number)
{
	if (ps->plusToken && number >= 0)
		dpc(ps, '+');
	if (ps->spaceToken && number >= 0)
		dpc(ps, ' ');
	if (ps->zeroToken && number < 0)
		dpc(ps, '-');
	if (ps->numberToken)
	{
		ps->retlen += putnc(ps->Number - nlen, *pthis);
		ft_putstr_fd(ps->After, 1);
		ps->retlen += ft_strlen(ps->After);
	}
	else
	{
		ft_putstr_fd(ps->After, 1);
		ps->retlen += ft_strlen(ps->After);
	}
}

void	printnumber4(t_printf *ps, int nlen)
{
	ps->retlen += putnc((ps->Number - nlen) - (ps->Number2 - nlen), '0');
	ps->retlen += putnc(ps->Number2, '0');
}

void	printnumber5(t_printf *ps, char *pthis, int nlen, int number)
{
	int	temp;

	if (number < 0)
		ps->Number -= 1;
	temp = putnc(porz(ps->Number - nlen) - porz(ps->Number2 - nlen), ' ');
	ps->retlen += temp;
	if (number < 0)
		ps->retlen += putnc(1, '-');
	ps->retlen += putnc(ps->Number2 - nlen, '0');
	ft_putstr_fd(ps->After, 1);
	ps->retlen += ft_strlen(ps->After);
}
