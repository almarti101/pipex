/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:57:20 by almarti3          #+#    #+#             */
/*   Updated: 2025/03/05 21:57:23 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_heredoc(char *delimiter, int heredoc_fd[2])
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, delimiter, ft_strlen(line) - 1) == 0)
		{
			free(line);
			break ;
		}
		write(heredoc_fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(heredoc_fd[1]);
	exit(0);
}

int	heredoc_mode(char *delimiter)
{
	int		heredoc_fd[2];
	pid_t	temp_pipe;

	if (pipe(heredoc_fd) == -1)
		error_custom("Error in here_doc", 1);
	temp_pipe = fork();
	if (temp_pipe == -1)
		error_custom("Error in here_doc", 1);
	if (temp_pipe == 0)
		read_heredoc(delimiter, heredoc_fd);
	close(heredoc_fd[1]);
	return (heredoc_fd[0]);
}

int	pipe_logic(int in_fd, char *cmd_name, char **env, int output_fd)
{
	int		fd[2];
	pid_t	pid;

	if (output_fd == -1)
	{
		if (pipe(fd) == -1)
			error_custom("Pipe error", 1);
	}
	else
		fd[1] = output_fd;
	pid = fork();
	if (pid < 0)
		error_custom("Fork error", 1);
	if (pid == 0)
	{
		dup2(in_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(in_fd);
		close(fd[1]);
		execute_command(cmd_name, env);
		error_custom("Error ejecutando el comando", 127);
	}
	return (close(in_fd), close(fd[1]), fd[0]);
}

void	wait_final(int *i, int is_heredoc)
{
	if (!is_heredoc)
		*i -= 2;
	else
		*i -= 3;
	while ((*i)-- >= 0)
		wait(NULL);
}

int	main(int argc, char **argv, char **env)
{
	int	output_fd;
	int	is_heredoc;
	int	prev_fd;
	int	i;

	i = 0;
	handle_args(argc, argv, &is_heredoc);
	open_input_file(argv, is_heredoc, &prev_fd);
	open_output_file(argv, argc, is_heredoc, &output_fd);
	if (!is_heredoc)
		i = 2;
	else
		i = 3;
	while (i < argc - 1)
	{
		if (i < argc - 2)
			prev_fd = pipe_logic(prev_fd, argv[i], env, -1);
		else
			pipe_logic(prev_fd, argv[i], env, output_fd);
		i++;
	}
	close(output_fd);
	wait_final(&i, is_heredoc);
	return (0);
}
