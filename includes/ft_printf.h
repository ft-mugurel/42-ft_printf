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

#ifndef FT_PRINTF_H_
#define FT_PRINTF_H_

#include <stdarg.h>

typedef short Bool;

enum BoolStruc {False = 0, True = ~0};

typedef struct t_list
{
 	Bool	numberToken;
 	Bool	minusToken;
 	Bool	plusToken;
 	Bool	zeroToken;
 	Bool	hastagToken;
	Bool	dotToken;
	Bool	spaceToken;
	int		theNumber;
	char	firstAfter;
	int		returnThis;
	Bool	percentageFound;
	int		start;
}			t_printf;

void	parsing(char *str, va_list args, t_printf printfstruc);
void	pars0(va_list args, t_printf printfstruc);
void	pars1(va_list args, t_printf printfstruc);
void	pars2(va_list args, t_printf printfstruc);
void	pars3(va_list args, t_printf printfstruc);
void	pars4(va_list args, t_printf printfstruc);
int		printnumber(int n);
int		printhex(va_list args, Bool X);


#endif // FT_PRINTF_H_
