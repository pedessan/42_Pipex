/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:32:28 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 15:39:29 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_exit("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile");
	if (pipe(pipefd) < 0)
		error_exit("Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("Fork failed");
	if (pid1 == 0)
		child_1(pipefd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("Fork failed");
	if (pid2 == 0)
		child_2(pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
