/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:57:48 by almarti3          #+#    #+#             */
/*   Updated: 2024/04/09 15:57:49 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_char(char char_to_write)
{
	write(1, &char_to_write, 1);
	return (1);
}

int	ft_write_str(char *str)
{
	int	size;

	size = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[size] != '\0')
	{
		write(1, &str[size], 1);
		size++;
	}
	return (size);
}
