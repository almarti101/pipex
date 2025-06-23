/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:57:31 by almarti3          #+#    #+#             */
/*   Updated: 2025/03/05 21:57:32 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(int pipe[2])
{
	close(pipe[0]);
	close(pipe[1]);
}

void	handle_args(int argc, char **argv, int *is_heredoc)
{
	if (argc < 5)
		error_custom("Error, not enough arguments", 1);
	*is_heredoc = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		*is_heredoc = 1;
}

void	open_input_file(char **argv, int is_heredoc, int *fd_i)

{
	if (!is_heredoc)
	{
		*fd_i = open(argv[1], O_RDONLY);
		if (*fd_i == -1)
			error_custom("Error opening input file", 1);
	}
	else
		*fd_i = heredoc_mode(argv[2]);
}

void	open_output_file(char **argv, int argc, int is_heredoc, int *fd_o)
{
	int	mode;

	if (is_heredoc)
		mode = O_APPEND;
	else
		mode = O_TRUNC;
	*fd_o = open(argv[argc - 1], O_CREAT | O_WRONLY | mode, 0664);
	if (*fd_o == -1)
		error_custom("Error with output file", 1);
}

void	create_pipes(int pipes[][2], int num_cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds - 1)
	{
		if (pipe(pipes[i]) == -1)
			error_custom("Pipe error", 1);
		i++;
	}
}
