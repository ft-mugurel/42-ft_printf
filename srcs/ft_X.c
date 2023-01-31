/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	X(unsigned int number, t_printf *ps)
{
	int nlen;
	char c;
	
	if (ps->zeroToken)
		c = '0';
	else
		c= ' ';
	nlen = 0;
	hex_len(number, "0123456789ABCDEF", &nlen);
	if (ps->hastagToken && number != 0)
	{
		nlen += 2;
		write(1, "0x", 2);
	}
	if (ps->dotToken)
		X2(number, ps, &nlen, c);
	if (!ps->dotToken)
		X3(number, ps, &nlen, c);
	ps->printed = True;
	ps->retlen += nlen;
	return (ps->retlen);
}

void	X2(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (number == 0)
		*nlen = 0;
	if (ps->minusToken)
	{
		ps->retlen += putnc(ps->Number2 - *nlen, '0');
		if (number != 0	)
			ft_putnbr_base(number, "0123456789ABCDEF");
		ps->retlen += putnc((ps->Number - *nlen) - porz(ps->Number2 - *nlen), ' ');
		ps->printed = True;
	}
	if (!ps->minusToken)
	{
		ps->retlen += putnc((ps->Number - *nlen) - porz(ps->Number2 - *nlen), ' ');
		ps->retlen += putnc(ps->Number2 - *nlen, '0');
		if (number != 0)
			ft_putnbr_base(number, "0123456789ABCDEF");
		ps->printed = True;
	}
}

void	X3(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (ps->minusToken)
	{
		ft_putnbr_base(number, "0123456789ABCDEF");
		ps->retlen += putnc(ps->Number - *nlen, c);
		ps->printed = True;
	}
	if (!ps->minusToken)
	{
		ps->retlen += putnc(ps->Number - *nlen, c);
		ft_putnbr_base(number, "0123456789ABCDEF");
		ps->printed = True;
	}
}
