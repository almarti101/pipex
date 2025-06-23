/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:57:12 by almarti3          #+#    #+#             */
/*   Updated: 2025/03/05 21:57:13 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_custom(char	*message, int exit_channel)
{
	errno = 1;
	ft_printf("\033[31m%s: \033[0m", message);
	perror("");
	exit(exit_channel);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*part_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i++], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (free_array(paths), path);
		free(path);
	}
	free_array(paths);
	return (NULL);
}

void	execute_command(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	if (!argv || argv[0] == '\0' || argv[0] == ' ' || argv[0] == '\t')
		error_custom("NULL Error", 1);
	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_custom("Error dividing the command", 1);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_array(cmd);
		perror("Error, command not found");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
		error_custom("Error executing command", 1);
	free_array(cmd);
	error_custom("Error en execve", 1);
}
