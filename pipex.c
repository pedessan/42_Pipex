/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:07:58 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/30 15:28:33 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(int pipefd[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		error_exit("Infile open failed");
	}
	dup2(infile, 0);
	dup2(pipefd[1], 1);
	close(infile);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(argv[2], envp);
}

void	child_2(int pipefd[2], char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		error_exit("Outfile open failed");
	}
	dup2(pipefd[0], 0);
	dup2(outfile, 1);
	close(outfile);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(argv[3], envp);
}
