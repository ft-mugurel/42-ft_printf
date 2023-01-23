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

int	printnumber(int number, t_printf *printfstruct)
{
	char	*str;
	int numberlen;

	if (printfstruct->dotToken && number < 0)
		str = ft_itoa(number * -1);
	else
		str = ft_itoa(number);
	numberlen = ft_strlen(str);
	if (printfstruct->minusToken)
	{
		if (printfstruct->plusToken)
		{
		 	if (number >= 0)
		 	{
		 		ft_putchar_fd('+', 1);
		 		printfstruct->returnThis++;
		 	}
		}
		ft_putstr_fd(str, 1);
		if (printfstruct->zeroToken)
			printfstruct->returnThis += putnchar(printfstruct->theNumber - numberlen, '0');
		else if (!printfstruct->zeroToken)printfstruct->returnThis += 
			printfstruct->returnThis += putnchar(printfstruct->theNumber - numberlen, ' ');
	}
	if (!printfstruct->minusToken)
	{
		if (printfstruct->plusToken)
		{
		 	if (number >= 0)
		 	{
		 		ft_putchar_fd('+', 1);
		 		printfstruct->returnThis++;
		 	}
		}
		if (printfstruct->spaceToken && number >= 0 && !printfstruct->numberToken)
		{
			ft_putchar_fd(' ', 1);
			printfstruct->returnThis += 1;
		}
		if (printfstruct->dotToken)
		{
			if (printfstruct->numberToken2)
			{
				if (number < 0)
					ft_putchar_fd('-', 1);
				if (printfstruct->spaceToken)
					putnchar((printfstruct->theNumber - (numberlen + 1) - printfstruct->theNumber2), '0');
				else if (!printfstruct->spaceToken)
					putnchar(printfstruct->theNumber - numberlen, '0');
			}
			if (!printfstruct->numberToken2)
			{
				if (number < 0)
					ft_putchar_fd('-', 1);
				if (printfstruct->spaceToken)
					putnchar((printfstruct->theNumber - (numberlen + 1) - printfstruct->theNumber2), ' ');
				else if (!printfstruct->spaceToken)
					putnchar(printfstruct->theNumber - numberlen, '0');
			}
		}
		else if (printfstruct->zeroToken)
			printfstruct->returnThis += putnchar(printfstruct->theNumber - numberlen, '0');
		else if (!printfstruct->zeroToken)
			printfstruct->returnThis += putnchar(printfstruct->theNumber - numberlen, ' ');
		ft_putstr_fd(str, 1);
	}
	printfstruct->returnThis += ft_strlen(str);
	printfstruct->printed = True;                   
	free(str);
	return (printfstruct->returnThis);
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
