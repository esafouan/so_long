/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:36:40 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 17:30:59 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_forme(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += adress((unsigned long)va_arg(args, void *));
	}
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_hexadicimal_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		i += ft_hexadicimal_ouper(va_arg(args, unsigned int));
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		a;

	a = 0;
	va_start(args, s);
	i = 0;
	while (s && s[a])
	{
		if (s[a] == '%')
		{
			a++;
			if (s[a] == '\0')
				break ;
			i += ft_forme(s[a], args);
		}
		else
			i += ft_putchar(s[a]);
		a++;
	}
	va_end(args);
	return (i);
}
