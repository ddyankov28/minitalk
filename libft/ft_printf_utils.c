/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:25:20 by ddyankov          #+#    #+#             */
/*   Updated: 2022/12/13 10:41:00 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char *s, int *len)
{	
	int	a;

	a = 0;
	if (!s)
		ft_putstr("(null)", len);
	while (s && s[a])
	{
		ft_putchar(s[a], len);
		a++;
	}
}

int	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
	}
	if (n < 0 && n > -2147483648)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0', len);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	return (n);
}

int	ft_pos_nbr(unsigned int n, int *len)
{
	if (n < 10)
	{
		ft_putchar(n + '0', len);
	}
	if (n >= 10)
	{
		ft_pos_nbr(n / 10, len);
		ft_pos_nbr(n % 10, len);
	}
	return (n);
}
