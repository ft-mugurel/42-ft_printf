/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	u(unsigned int number, t_printf *ps)
{
	int		nlen;
	char	c;

	if (ps->zeroToken)
		c = '0';
	else
		c = ' ';
	nlen = 0;
	num_len(number, &nlen);
	if (ps->dotToken)
		u2(number, ps, &nlen, c);
	if (!ps->dotToken)
		u3(number, ps, &nlen, c);
	ps->retlen += nlen;
	ps->printed = True;
	return (ps->retlen);
}

void	u2(unsigned int number, t_printf *p, int *nlen, char c)
{
	if (number == 0)
		*nlen = 0;
	if (p->minusToken)
	{
		p->retlen += putnc(p->Number2 - *nlen, '0');
		if (number != 0)
			unsigned_base(number);
		p->retlen += putnc((p->Number - *nlen) - porz(p->Number2 - *nlen), ' ');
		p->printed = True;
	}
	if (!p->minusToken)
	{
		p->retlen += putnc((p->Number - *nlen) - porz(p->Number2 - *nlen), ' ');
		p->retlen += putnc(p->Number2 - *nlen, '0');
		if (number != 0)
			unsigned_base(number);
		p->printed = True;
	}
}

void	u3(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (ps->minusToken)
	{
		unsigned_base(number);
		ps->retlen += putnc(ps->Number - *nlen, c);
		ps->printed = True;
	}
	if (!ps->minusToken)
	{
		ps->retlen += putnc(ps->Number - *nlen, c);
		unsigned_base(number);
		ps->printed = True;
	}
}

void	num_len(unsigned int nb, int *nlen)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		num_len(nb / 10, nlen);
	*nlen = *nlen + 1;
}

void	unsigned_base(unsigned int nb)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		unsigned_base(nb / 10);
	ft_putchar_fd(base[nb % 10], 1);
}
