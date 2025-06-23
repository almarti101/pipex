/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:47:07 by almarti3          #+#    #+#             */
/*   Updated: 2024/03/22 17:47:49 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static int	ft_calculate_power(int base, int exponent)
{
	int	i;
	int	result;

	result = 1;
	if (exponent < 0)
	{
		base = 1 / base;
		exponent = -exponent;
	}
	if (exponent == 0)
		return (1);
	i = 0;
	while (i < exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}

static int	ft_write_nb(long int nb, int length)
{
	int	left_nb;
	int	curr_nb;
	int	i;
	int	size;

	i = 1;
	size = 0;
	if (nb < 0)
	{
		size += ft_write_char('-');
		nb = -nb;
	}
	curr_nb = nb;
	if (curr_nb == 0)
		return (ft_write_char('0'));
	while (curr_nb > 0 && i <= length)
	{
		left_nb = curr_nb / ft_calculate_power(10, length - i);
		size += ft_write_char(left_nb + '0');
		curr_nb = curr_nb - left_nb * ft_calculate_power(10, length - i);
		i++;
	}
	while (i++ <= length)
		size += ft_write_char('0');
	return (size);
}

int	ft_nb_to_string(int nb)
{
	int	count;

	if (nb == -2147483648)
	{
		ft_write_str("-2147483648");
		return (11);
	}
	count = ft_count_digits(nb);
	return (ft_write_nb(nb, count));
}
