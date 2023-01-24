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

void	parsing(char *str, va_list args, t_printf *printfstruct)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			printfstruct->After = (str + i + 1);
			i += pars(args, printfstruct);
			makeallfalse(printfstruct);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			printfstruct->returnThis += 1;
		}
		i++;
	}
}

int pars(va_list args, t_printf *printfstruct)
{
	int	i;
	Bool dontzero;

	i = 0;
	dontzero = False;
	while(printfstruct->After[i] && !printfstruct->printed)
	{
	  printfstruct->firstAfter = printfstruct->After[i];
		numberflag1(printfstruct->After, printfstruct);
		if (printfstruct->firstAfter >= '1' && printfstruct->firstAfter <= '9')
			dontzero = True;
		if (printfstruct->firstAfter == '.')
			printfstruct->dotToken = True;
		if (printfstruct->firstAfter == '0' && !dontzero)
			printfstruct->zeroToken = True;
	  pars0(args, printfstruct);
	  i++;
	}
	return (i);
}

void	numberflag1(char *number, t_printf *printfstruct)
{
	int i;

	i = 0;
	printfstruct->theNumber = change_sine(ft_atoi(number));	
	while (number[i] != '.' && number[i])
		i++;
	printfstruct->theNumber2 = change_sine(ft_atoi(number + i + 1));	
	if (printfstruct->theNumber > 0)
		printfstruct->numberToken = True;
	if (ft_isdigit(number[i + 1]))
		printfstruct->numberToken2 = True;
}

int change_sine(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

void	pars0(va_list args, t_printf *printfstruct)
{
	if (printfstruct->firstAfter == '+')
	{
		printfstruct->plusToken = True;
	}
	else if (printfstruct->firstAfter == '-')
	{
	  printfstruct->minusToken = True;
	}
	pars1(args, printfstruct);
}

void	pars1(va_list args, t_printf *printfstruct)
{
	if (printfstruct->firstAfter == '#')
	{
		printfstruct->hastagToken = True;	
	}
	pars2(args, printfstruct);
}
void	pars2(va_list args, t_printf *printfstruct)
{
	if (printfstruct->firstAfter == ' ')
	{
		printfstruct->spaceToken = True;
	}
	pars3(args, printfstruct);
}
void	pars3(va_list args, t_printf *printfstruct)
{
	if (printfstruct->firstAfter == 'c')
	{
		char	c;
		c = va_arg(args, int);
		ft_putchar_fd(c, 1);
		printfstruct->returnThis += 1;
        printfstruct->printed = True;                   
	}
	else if (printfstruct->firstAfter == 's')
	{
		char	*str;

		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			printfstruct->returnThis += 6;
			printfstruct->printed = True;                   
		}
		else
		{
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += ft_strlen(str);
			printfstruct->printed = True;                   
		}
	}
	pars4(args, printfstruct);
}

void	pars4(va_list args, t_printf *printfstruct)
{
	if (printfstruct->firstAfter == 'i')
		printfstruct->returnThis = printnumber(va_arg(args, int), printfstruct);
	else if (printfstruct->firstAfter == 'd')
		printfstruct->returnThis = printnumber(va_arg(args, int), printfstruct);
	else if (printfstruct->firstAfter == 'x')
		printfstruct->returnThis = printhex(args, False);
	else if (printfstruct->firstAfter == 'X')
		printfstruct->returnThis = printhex(args, True);
	else if (printfstruct->firstAfter == 'X')
		printfstruct->returnThis = printhex(args, True);
}

int	printhex(va_list args, Bool X)
{
}
