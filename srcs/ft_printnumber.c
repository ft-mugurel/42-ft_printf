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
