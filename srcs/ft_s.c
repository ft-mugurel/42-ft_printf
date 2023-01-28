/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	s(char *str, t_printf *ps)
{
	int	slen;

	if (!str)
	{
		s2(str, ps);
	}
	else
	{
		slen = ft_strlen(str);
		s3(str, ps, slen);
		s4(str, ps, slen);
	}
	return (ps->retlen);
}

void	s2(char *str, t_printf *ps)
{
	if (ps->dotToken && ps->Number2 >= 6)
	{
		ps->retlen += putnc(ps->Number - 6, ' ');
		ps->retlen += ft_putstr_n("(null)", ps->Number2);
		ps->printed = True;
	}
	if (!ps->dotToken)
	{
		if (ps->minusToken)
		{
			ps->retlen += putnc(ps->Number - 6, ' ');
			ft_putstr_fd("(null)", 1);
			ps->retlen += 6;
			ps->printed = True;
		}
		if (!ps->minusToken)
		{
			ps->retlen += putnc(ps->Number - 6, ' ');
			ft_putstr_fd("(null)", 1);
			ps->retlen += 6;
			ps->printed = True;
		}
	}
}

void	s3(char *str, t_printf *ps, int slen)
{
	if (ps->dotToken)
	{
		if (ps->minusToken)
		{
			slen = ft_putstr_n(str, ps->Number2);
			ps->retlen += putnc(ps->Number - slen, ' ');
			ps->retlen += slen;
			ps->printed = True;
		}
		if (!ps->minusToken)
		{
			if (ps->numberToken2)
				ps->Number -= 1;
			ps->retlen += putnc(ps->Number, ' ');
			ps->retlen += ft_putstr_n(str, ps->Number2);
			ps->printed = True;
		}
	}
}

void	s4(char *str, t_printf *ps, int slen)
{
	if (!ps->dotToken)
	{
		if (ps->minusToken)
		{
			ft_putstr_fd(str, 1);
			ps->retlen += putnc(ps->Number - slen, ' ');
			ps->retlen += ft_strlen(str);
			ps->printed = True;
		}
		if (!ps->minusToken)
		{
			ps->retlen += putnc(ps->Number - slen, ' ');
			ft_putstr_fd(str, 1);
			ps->retlen += ft_strlen(str);
			ps->printed = True;
		}
	}
}
