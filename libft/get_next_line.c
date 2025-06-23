/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:49:25 by almarti3          #+#    #+#             */
/*   Updated: 2024/05/01 14:49:26 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *new_str);
char		*check_pre_n(char *str);
char		*check_post_n(char *str);

char	*get_next_line(int fd)
{
	char			*new_str;
	static char		*remaining;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(remaining), remaining = NULL);
	if (!remaining)
		remaining = ft_strdup("");
	remaining = read_file(fd, remaining);
	if (!remaining)
		return (NULL);
	new_str = check_pre_n(remaining);
	remaining = check_post_n(remaining);
	return (new_str);
}

static char	*read_file(int fd, char *remaining)
{
	int		read_file;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(remaining), remaining = NULL);
	read_file = 1;
	while (read_file > 0 && !ft_strchr(remaining, '\n'))
	{
		read_file = read(fd, buffer, BUFFER_SIZE);
		if (read_file == -1)
			return (free(buffer), free(remaining), remaining = NULL);
		buffer[read_file] = '\0';
		remaining = ft_strjoin_free(remaining, buffer);
	}
	free(buffer);
	if (read_file == 0 && ft_strcmp(remaining, "") == 0)
	{
		free(remaining);
		remaining = NULL;
	}
	return (remaining);
}

char	*check_pre_n(char *remainig)
{
	int		i;
	char	*new_str;

	i = 0;
	while (remainig[i] && remainig[i] != '\n')
		i++;
	if (remainig[i] == '\n')
		i++;
	new_str = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (remainig[i] && remainig[i] != '\n')
	{
		new_str[i] = remainig[i];
		i++;
	}
	new_str[i] = '\n';
	i++;
	new_str[i] = '\0';
	return (new_str);
}

char	*check_post_n(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), str = NULL);
	i++;
	while (str[i + j] != '\0')
		j++;
	new_str = malloc(sizeof(char) * (j + 1));
	if (!new_str)
		return (free(str), str = NULL);
	j = 0;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	return (free(str), new_str);
}

//  int	main(void)
//  {
//  	char	*str;
//  	int		fd;
//     int     i;

//     i = 0;
//  	fd = open("fight.txt", O_RDONLY);
//  	if (fd == -1)
//  		return (1);
//  	while (i < 50)
//  	{
//         str = get_next_line(fd);
//         printf("%s\n", str);
//  		free(str);
//         i++;
//  	}
//     system("leaks -q a.out");
//  	close(fd);
//  	return (0);
//  }