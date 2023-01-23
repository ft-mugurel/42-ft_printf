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
 	Bool	numberToken2;
 	Bool	minusToken;
 	Bool	plusToken;
 	Bool	zeroToken;
 	Bool	hastagToken;
	Bool	dotToken;
	Bool	spaceToken;
	int		theNumber;
	int		theNumber2;
	char	*After;
	char	firstAfter;
	Bool	printed;
	int		returnThis;
}			t_printf;

int ft_printf(const char *str, ...);
void	parsing(char *str, va_list args, t_printf *printfstruct);
int		pars(va_list args, t_printf *printfstruct);
void	pars0(va_list args, t_printf *printfstruct);
void	pars1(va_list args, t_printf *printfstruct);
void	pars2(va_list args, t_printf *printfstruct);
void	pars3(va_list args, t_printf *printfstruct);
void	pars4(va_list args, t_printf *printfstruct);
int		printhex(va_list args, Bool X);
int		printnumber(int number, t_printf *printfstruct);
void	makeallfalse(t_printf *printfstruck);
void	numberflag1(char *number, t_printf *printfstruct);
void	numberflag2(char *number, t_printf *printfstruct);
int	putnchar(int sc, char c);


#endif // FT_PRINTF_H_
