/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:46:17 by esafouan          #+#    #+#             */
/*   Updated: 2022/10/31 20:53:48 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		return (i);
	}
	else
		return (ft_putstr("(null)"));
}

int	ft_putnbr(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		len++;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_hexadicimal_ouper(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			n += 48;
		else
			n += 55;
		len += ft_putchar((char)n);
	}
	else
	{
		len += ft_hexadicimal_ouper(n / 16);
		len += ft_hexadicimal_ouper(n % 16);
	}
	return (len);
}
