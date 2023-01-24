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
#include <stdio.h>

int	printnumber(int number, t_printf *printfstruct)
{
	char	*str;
	char	printthis;
	int numberlen;
	if (!printfstruct->dotToken && printfstruct->zeroToken)
		printthis = '0';
	else
		printthis = ' ';
	if ((printfstruct->dotToken || printfstruct->zeroToken) && number == -2147483648)
		str = ft_strdup("2147483648");
	else if ((printfstruct->zeroToken || printfstruct->dotToken) && number < 0)
		str = ft_itoa(-number);
	else
		str = ft_itoa(number);
	numberlen = ft_strlen(str);
	if (printfstruct->minusToken && !printfstruct->dotToken)
	{
		if (printfstruct->numberToken)
		{
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += ft_strlen(str);
			printfstruct->returnThis += putnchar(printfstruct->theNumber - numberlen, printthis);
		}
		else
		{
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += ft_strlen(str);
		}
	}
	else if (!printfstruct->minusToken && !printfstruct->dotToken)
	{
		if (printfstruct->zeroToken && number < 0)
		{
			printfstruct->returnThis += putnchar(1, '-');
			printfstruct->theNumber -= 1;
		}
		if (printfstruct->numberToken)
		{
			printfstruct->returnThis += putnchar(printfstruct->theNumber - numberlen, printthis);
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += ft_strlen(str);
		}
		else
		{
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += ft_strlen(str);
		}
	}
	else if (printfstruct->dotToken && !printfstruct->minusToken)
	{
		if (number < 0 && !(printfstruct->numberToken && printfstruct->numberToken2))
			printfstruct->returnThis += putnchar(1, '-');
		if (printfstruct->numberToken && printfstruct->numberToken2 && !(printfstruct->theNumber2 == 0) && number == 0)
		{
			printfstruct->returnThis += putnchar((printfstruct->theNumber - numberlen) - (printfstruct->theNumber2 - numberlen), '0');
			printfstruct->returnThis += putnchar(printfstruct->theNumber2, '0');
		}
		else if ((printfstruct->numberToken || printfstruct->theNumber2 == 0) && number == 0)
		{
			printfstruct->returnThis += putnchar(positiveorzero(printfstruct->theNumber + 1 - numberlen), ' ');
		}
		else if (!printfstruct->numberToken && !printfstruct->numberToken2 && number == 0)
		{
		}
		else if (printfstruct->numberToken && printfstruct->numberToken2)
		{
			if (number < 0)
				printfstruct->theNumber -= 1;
			printfstruct->returnThis += putnchar(positiveorzero(printfstruct->theNumber - numberlen) - positiveorzero(printfstruct->theNumber2 - numberlen), ' ');
			if (number < 0)
				printfstruct->returnThis += putnchar(1, '-');
			printfstruct->returnThis += putnchar(printfstruct->theNumber2 - numberlen, '0');
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += ft_strlen(str);
		}
		else if (printfstruct->numberToken && !printfstruct->numberToken2 && number != 0)
		{
			printfstruct->returnThis += putnchar(printfstruct->theNumber - numberlen, '0');
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += ft_strlen(str);
		}
		else if (!printfstruct->numberToken && printfstruct->numberToken2)
		{
			printfstruct->returnThis += putnchar(printfstruct->theNumber2 - numberlen, '0');
			if (number != 0 || printfstruct->theNumber2 != 0)
			{
				ft_putstr_fd(str, 1);
				printfstruct->returnThis += ft_strlen(str);
			}
		}
		else
		{
				ft_putstr_fd(str, 1);
				printfstruct->returnThis += ft_strlen(str);
		}
	}
	else if (printfstruct->dotToken && printfstruct->minusToken)
	{
		if (number < 0)
		{
			printfstruct->returnThis += putnchar(1, '-');
			printfstruct->theNumber -= 1;
		}
		if (printfstruct->numberToken && printfstruct->numberToken2)
		{
			printfstruct->returnThis += putnchar(printfstruct->theNumber2 - numberlen, '0');
			ft_putstr_fd(str, 1);
			printfstruct->returnThis += putnchar((printfstruct->theNumber - numberlen) - positiveorzero(printfstruct->theNumber2 - numberlen), printthis);
			printfstruct->returnThis += ft_strlen(str);
		}
		else if (printfstruct->numberToken && !printfstruct->numberToken2)
		{
			printfstruct->returnThis += putnchar(printfstruct->theNumber, printthis);
			if (number != 0 || printfstruct->theNumber2 != 0)
			{
				ft_putstr_fd(str, 1);
				printfstruct->returnThis += ft_strlen(str);
			}
		}
		else if (!printfstruct->numberToken && printfstruct->numberToken2)
		{
			printfstruct->returnThis += putnchar(printfstruct->theNumber2 - numberlen, '0');
			if (number != 0 || printfstruct->theNumber2 != 0)
			{
				ft_putstr_fd(str, 1);
				printfstruct->returnThis += ft_strlen(str);
			}
		}
		else if (!printfstruct->numberToken && !printfstruct->numberToken2 && number == 0)
		{
		}
		else
		{
				ft_putstr_fd(str, 1);
				printfstruct->returnThis += ft_strlen(str);
		}
	}
	printfstruct->printed = True;                   
	free(str);
	return (printfstruct->returnThis);
}

int	positiveorzero(int n)
{
	if (n < 0)
		n = 0;
	return (n);
}

int	putnchar(int sc, char c)
{
	int putn;

	putn = 0;
	while (sc > 0)
	{
		ft_putchar_fd(c,1);
		sc--;
		putn++;
	}
	return (putn);
}
