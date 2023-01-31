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
#include <unistd.h>

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
	int		Number;
	int		Number2;
	char	*After;
	char	firstAfter;
	Bool	printed;
	int		retlen;
}			t_printf;

int		ft_printf(const char *str, ...);
void	parsing(char *str, va_list args, t_printf *printfstruct);
int		pars(va_list args, t_printf *printfstruct);
void	pars0(va_list args, t_printf *printfstruct);
void	pars1(va_list args, t_printf *printfstruct);
void	pars2(va_list args, t_printf *printfstruct);
void	pars3(va_list args, t_printf *printfstruct);
void	pars4(va_list args, t_printf *printfstruct);
int		c(int args, t_printf *ps);
int		s(char *str, t_printf *ps);
void	s2(char *str, t_printf *ps);
void	s3(char *str, t_printf *ps, int slen);
void	s4(char *str, t_printf *ps, int slen);
int		printnumber(int number, t_printf *printfstruct);
void	printnumber2(t_printf *ps, char *pthis, char *str, int nlen);
void	printnumber3(t_printf *ps, char *pthis, int nlen,int number);
void	printnumber4(t_printf *ps, int nlen);
void	printnumber5(t_printf *ps, char *pthis, int nlen,int number);
void	printnumber6(t_printf *ps, char *pthis, int nlen,int number);
void	printnumber7(t_printf *ps, char *pthis, int nlen,int number);
void	printnumber8(t_printf *ps, char *pthis, int nlen,int number);
void	printnumber9(t_printf *ps, char *pthis, int nlen,int number);
void	printnumber10(t_printf *ps, char *pthis, int nlen,int number);
void	printnumber11(t_printf *ps, char *pthis, int nlen,int number);
int		printnumber12(t_printf *ps, char *pthis, int nlen,int number);
int		x(unsigned int number, t_printf *ps);
void	x2(unsigned int number, t_printf *ps, int *nlen, char c);
void	x3(unsigned int number, t_printf *ps, int *nlen, char c);
int		X(unsigned int number, t_printf *ps);
void	X2(unsigned int number, t_printf *ps, int *nlen, char c);
void	X3(unsigned int number, t_printf *ps, int *nlen, char c);
int		p(unsigned long number, t_printf *ps);
void	p2(unsigned long number, t_printf *ps, int *nlen, char c);
int		ft_putstr_n(char *str, int n);
void	makeallfalse(t_printf *printfstruck);
void	numberflag1(char *number, t_printf *printfstruct);
void	numberflag2(char *number, t_printf *printfstruct);
int		putnc(int sc, char c);
int		change_sine(int n);
int		porz(int n);
int		printfsetup(char *pthis, t_printf *ps, int number);
void	dpc(t_printf *ps, char c);
void	hex_len(unsigned int nbr, char *base, int *nlen);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	hex_len_p(unsigned long nbr, char *base, int *nlen);
void	ft_putnbr_base_p(unsigned long nbr, char *base);
void	ft_putchar(char c);

#endif // FT_PRINTF_H_
