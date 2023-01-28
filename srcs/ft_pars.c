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
			printfstruct->retlen += 1;
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
	if (printfstruct->minusToken)
		printfstruct->Number = change_sine(ft_atoi(number + 1));	
	if (!printfstruct->minusToken)
		printfstruct->Number = change_sine(ft_atoi(number));	
	while (number[i] != '.' && number[i])
		i++;
	printfstruct->Number2 = change_sine(ft_atoi(number + i + 1));	
	if (printfstruct->Number > 0)
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
	if (printfstruct->firstAfter == 's')
		printfstruct->retlen = s(va_arg(args, char *), printfstruct);
	else if (printfstruct->firstAfter == 'c')
		printfstruct->retlen = c(va_arg(args, int), printfstruct);
	else if (printfstruct->firstAfter == 'i')
		printfstruct->retlen = printnumber(va_arg(args, int), printfstruct);
	else if (printfstruct->firstAfter == 'd')
		printfstruct->retlen = printnumber(va_arg(args, int), printfstruct);
	else if (printfstruct->firstAfter == 'x')
		printfstruct->retlen = printhex(args, False);
	else if (printfstruct->firstAfter == 'X')
		printfstruct->retlen = printhex(args, True);
	else if (printfstruct->firstAfter == 'X')
		printfstruct->retlen = printhex(args, True);
	pars4(args, printfstruct);
}

void	pars4(va_list args, t_printf *printfstruct)
{
}

int	printhex(va_list args, Bool X)
{
}
