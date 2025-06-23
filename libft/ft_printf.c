/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:55:56 by almarti3          #+#    #+#             */
/*   Updated: 2024/04/09 15:56:01 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_format(char const ch_var, va_list vargs)
{
	int	size;

	size = 0;
	if (ch_var == 'c')
		size += ft_write_char(va_arg(vargs, int));
	else if (ch_var == 's')
		size += ft_write_str(va_arg(vargs, char *));
	else if (ch_var == 'p')
		size += ft_write_ptr((size_t)va_arg(vargs, void *), HEX_LOWER);
	else if (ch_var == 'd' || ch_var == 'i')
	{
		size += ft_nb_to_string(va_arg(vargs, int));
	}
	else if (ch_var == 'u')
		size += ft_uns_to_string(va_arg(vargs, unsigned int));
	else if (ch_var == 'x')
		size += ft_nb_hex((size_t)va_arg(vargs, unsigned int), HEX_LOWER);
	else if (ch_var == 'X')
		size += ft_nb_hex((size_t)va_arg(vargs, unsigned int), HEX_UPPER);
	else
		size += ft_write_char(ch_var);
	return (size);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		size;
	va_list	vargs;

	va_start(vargs, format);
	size = 0;
	i = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_check_format(format[i], vargs);
		}
		else
			size += ft_write_char(format[i]);
		i++;
	}
	va_end(vargs);
	return (size);
}

// int main(void)
// {
// 	ft_printf("%i", 132);
// 	return (0);
// }
