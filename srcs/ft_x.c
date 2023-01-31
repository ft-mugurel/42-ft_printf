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

int	x(unsigned int number, t_printf *ps)
{
	int nlen;
	char c;
	
	if (ps->zeroToken)
		c = '0';
	else
		c= ' ';
	nlen = 0;
	hex_len(number, "0123456789abcdef", &nlen);
	if (ps->hastagToken && number != 0)
	{
		nlen += 2;
		write(1, "0x", 2);
	}
	if (ps->dotToken)
		x2(number, ps, &nlen, c);
	if (!ps->dotToken)
		x3(number, ps, &nlen, c);
	ps->printed = True;
	ps->retlen += nlen;
	return (ps->retlen);
}

void	x2(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (number == 0)
		*nlen = 0;
	if (ps->minusToken)
	{
		ps->retlen += putnc(ps->Number2 - *nlen, '0');
		if (number != 0	)
			ft_putnbr_base(number, "0123456789abcdef");
		ps->retlen += putnc((ps->Number - *nlen) - porz(ps->Number2 - *nlen), ' ');
		ps->printed = True;
	}
	if (!ps->minusToken)
	{
		ps->retlen += putnc((ps->Number - *nlen) - porz(ps->Number2 - *nlen), ' ');
		ps->retlen += putnc(ps->Number2 - *nlen, '0');
		if (number != 0)
			ft_putnbr_base(number, "0123456789abcdef");
		ps->printed = True;
	}
}

void	x3(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (ps->minusToken)
	{
		ft_putnbr_base(number, "0123456789abcdef");
		ps->retlen += putnc(ps->Number - *nlen, c);
		ps->printed = True;
	}
	if (!ps->minusToken)
	{
		ps->retlen += putnc(ps->Number - *nlen, c);
		ft_putnbr_base(number, "0123456789abcdef");
		ps->printed = True;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hex_len(unsigned int nbr, char *base, int *nlen)
{
	int	basel;
	unsigned int	n;

	n = nbr;
	basel = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (base[basel] != '\0')
		basel++;
	if (nbr >= basel)
	{
		hex_len(n / basel, base, nlen);
		hex_len(n % basel, base, nlen);
	}
	else
	{
		*nlen = *nlen + 1;
	}
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	basel;
	unsigned int	n;

	n = nbr;
	basel = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (base[basel] != '\0')
		basel++;
	if (nbr >= basel)
	{
		ft_putnbr_base(n / basel, base);
		ft_putnbr_base(n % basel, base);
	}
	else
	{
		ft_putchar(base[n]);
	}
}
