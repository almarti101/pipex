/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:57:00 by almarti3          #+#    #+#             */
/*   Updated: 2025/03/05 21:57:02 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int fd_pipe[2], int fd_o, char **argv, char **env)
{
	close(fd_pipe[1]);
	dup2(fd_pipe[0], 0);
	close(fd_pipe[0]);
	dup2(fd_o, 1);
	execute_command(argv[3], env);
	close(fd_o);
}

void	child_process(int fd_pipe[2], int fd_i, char **argv, char **env)
{
	dup2(fd_i, 0);
	close(fd_i);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[1]);
	execute_command(argv[2], env);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_pipe[2];
	int		fd_i;
	int		fd_o;
	pid_t	pid1;

	if (argc != 5)
		error_custom("Error, incorrect number of arguments", 1);
	if (pipe(fd_pipe) == -1)
		error_custom("Pipe error", 1);
	fd_i = open(argv[1], O_RDONLY);
	if (fd_i == -1)
		error_custom("Error opening input file.", 1);
	fd_o = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_o == -1)
		error_custom("Error opening output file.", 1);
	pid1 = fork();
	if (pid1 < 0)
		exit(1);
	if (pid1 == 0)
		child_process(fd_pipe, fd_i, argv, env);
	waitpid(pid1, NULL, 0);
	parent_process(fd_pipe, fd_o, argv, env);
	close(fd_i);
	return (0);
}
