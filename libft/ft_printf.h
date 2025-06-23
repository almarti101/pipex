/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:25:49 by almarti3          #+#    #+#             */
/*   Updated: 2024/04/09 14:25:57 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>

//Funciones
int		ft_printf(char const *format, ...);
int		ft_write_char(char char_to_write);
int		ft_write_str(char *str);
int		ft_nb_to_string(int nb);
int		ft_uns_to_string(unsigned int nb);
int		ft_write_ptr(size_t nbr, char *base);
int		ft_nb_hex(size_t nbr, char *base);
int		ft_count_hex(size_t ptr);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif
