/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:56:31 by esafouan          #+#    #+#             */
/*   Updated: 2022/11/01 01:32:55 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_hexadicimal_lower(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			n += 48;
		else
			n += 87;
		len += ft_putchar((char )n);
	}
	else
	{
		len += ft_hexadicimal_lower(n / 16);
		len += ft_hexadicimal_lower(n % 16);
	}
	return (len);
}

int	adress(unsigned long n)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			n += 48;
		else
			n += 87;
		len += ft_putchar((char )n);
	}
	else
	{
		len += adress(n / 16);
		len += adress(n % 16);
	}
	return (len);
}
