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

void	parsing(char *str, va_list args, t_printf printfstruc)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			printfstruc.percentageFound = True;
			if (!printfstruc.percentageFound)
				printfstruc.start = i;
			i++;
			printfstruc.firstAfter = str[i];
			pars0(args, printfstruc);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			printfstruc.returnThis += 1;
		}
		i++;
	}
}

void	pars0(va_list args, t_printf printfstruc)
{
	if (printfstruc.firstAfter == '+')
	{
		printfstruc.plusToken = True;
	}
	else if (printfstruc.firstAfter == '-')
	{
	  printfstruc.minusToken = True;
	}
	pars1(args, printfstruc);
}

void	pars1(va_list args, t_printf printfstruc)
{
	if (printfstruc.firstAfter == '#')
	{
		printfstruc.hastagToken = True;	
	}
	else if (printfstruc.firstAfter == '.')
	{
		printfstruc.dotToken = True;
	}
	pars2(args, printfstruc);
}
void	pars2(va_list args, t_printf printfstruc)
{
	if (printfstruc.firstAfter == ' ')
	{
		printfstruc.spaceToken = True;
	}
	else if (ft_isdigit(printfstruc.firstAfter))
	{
		printfstruc.numberToken = True;
	}
	pars3(args, printfstruc);
}
void	pars3(va_list args, t_printf printfstruc)
{
	if (printfstruc.firstAfter == 'c')
	{
		char	c;
		c = va_arg(args, int);
		ft_putchar_fd(c, 1);
		printfstruc.returnThis += 1;
	}
	else if (printfstruc.firstAfter == 's')
	{
		char	*str;

		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			printfstruc.returnThis += 6;
			return ;
		}
		ft_putstr_fd(str, 1);
		printfstruc.returnThis += ft_strlen(str);
	}
	pars4(args, printfstruc);
}
void	pars4(va_list args, t_printf printfstruc)
{
	if (printfstruc.firstAfter == 'i')
		printfstruc.returnThis = printnumber(va_arg(args, int));
	else if (printfstruc.firstAfter == 'd')
		printfstruc.returnThis = printnumber(va_arg(args, int));
	else if (printfstruc.firstAfter == 'x')
		printfstruc.returnThis = printhex(args, False);
	else if (printfstruc.firstAfter == 'X')
		printfstruc.returnThis = printhex(args, True);
	else if (printfstruc.firstAfter == 'X')
		printfstruc.returnThis = printhex(args, True);
}

size_t	digit_count(long n)
{
	size_t	c;

	c = 1;
	while (n >= 10)
	{
		n /= 10;
		c += 1;
	}
	return (c);
}

size_t	get_square(long n)
{
	size_t	square;

	square = 1;
	while (n > 1)
	{
		square *= 10;
		n--;
	}
	return (square);
}

char	*min_int(void)
{
	char	*res;
	char	*temp;
	int		i;

	i = 0;
	temp = "-2147483648";
	res = malloc(sizeof(char) * 12);
	while (i < 11)
	{
		res[i] = temp[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*convert(int n, int neg, size_t count, size_t square)
{
	char	*res;

	if (neg == 1)
	{
		res = ft_calloc(count + 2,sizeof(char));
		if (!res)
			return (0);
		res[0] = '-';
		res[1] = (n / square) + 48;
		neg = 2;
	}
	else
	{
		res = ft_calloc(count + 1,sizeof(char));
		if (!res)
			return (0);
		res[0] = (n / square) + 48;
		neg = 1;
	}
	while (square >= 10)
	{
		res[neg++] = ((n % square) / (square / 10)) + 48;
		square /= 10;
	}
	return (res);
}

int	printnumber(int n)
{
	size_t	count;
	size_t	square;
	int		neg;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	count = digit_count(n);
	square = get_square(count);
	ft_putstr_fd(convert(n, neg, count, square), 1);
	return (count);
}

int	printhex(va_list args, Bool X)
{
}
