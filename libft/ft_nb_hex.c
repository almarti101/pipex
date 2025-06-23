/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:06:29 by almarti3          #+#    #+#             */
/*   Updated: 2024/04/09 16:06:30 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_hex(size_t ptr)
{
	int	length;

	length = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		length++;
	}
	return (length);
}

int	ft_nb_hex(size_t nbr, char *base)
{
	int		n;
	char	*digits;
	int		length;

	n = 0;
	if (nbr == 0)
		return (ft_write_str("0"));
	length = ft_count_hex(nbr);
	digits = malloc(sizeof(char) * (length + 1));
	if (digits == NULL)
		return (0);
	digits[length] = '\0';
	while (length > 0)
	{
		length--;
		digits[length] = base[nbr % 16];
		nbr /= 16;
	}
	n += ft_write_str(digits);
	free(digits);
	return (n);
}
