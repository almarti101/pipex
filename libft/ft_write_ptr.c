/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:02:17 by almarti3          #+#    #+#             */
/*   Updated: 2024/04/09 16:02:18 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_ptr(size_t nbr, char *base)
{
	int		n;
	char	*digits;
	int		length;

	n = 0;
	if (nbr == 0)
		return (ft_write_str("0x0"));
	length = ft_count_hex(nbr);
	digits = malloc(sizeof(char) * (length + 1));
	if (digits == NULL)
		return (0);
	digits[length] = '\0';
	n += ft_write_str("0x");
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
