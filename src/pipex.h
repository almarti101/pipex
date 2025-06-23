/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:58:06 by almarti3          #+#    #+#             */
/*   Updated: 2025/03/05 21:58:07 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "../libft/libft.h"

//utils
void	error_custom(char *message, int exit_channel);
void	free_array(char **array);
char	*find_path(char *cmd, char **envp);
void	execute_command(char *argv, char **envp);

//pipex_bonus
void	close_pipes(int pipe[2]);
int		heredoc_mode(char *delimiter);

//utils_bonus
void	open_input_file(char **argv, int is_heredoc, int *fd_i);
void	handle_args(int argc, char **argv, int *is_heredoc);
void	open_output_file(char **argv, int argc, int is_heredoc, int *fd_o);
void	create_pipes(int pipes[][2], int num_cmds);