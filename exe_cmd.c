/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:45:10 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 15:37:26 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		if (args)
			ft_free_s_matrix(args);
		error_exit("Command parsing error");
	}
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		ft_free_s_matrix(args);
		error_exit("Command not found");
	}
	execve(path, args, envp);
	ft_free_s_matrix(args);
	error_exit("Exec failed");
}
