/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:47:05 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/30 15:25:43 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_helper(char *cmd, char *line, char *start)
{
	char	*end;
	char	*dir;
	char	*full;

	if (*line == ':')
		end = line;
	else
		end = line + 1;
	dir = pipex_substr(start, end);
	full = path_join(dir, cmd);
	free(dir);
	if (access(full, X_OK) == 0)
		return (full);
	free(full);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*start;
	char	*line;
	char	*full_path;

	if (ft_strchr(cmd, '/') && access(cmd, F_OK | X_OK | R_OK) == 0)
		return (ft_strdup(cmd));
	line = get_path_line(envp);
	if (!line)
		return (NULL);
	start = line;
	while (*line)
	{
		if (*line == ':' || *(line + 1) == '\0')
		{
			full_path = get_path_helper(cmd, line, start);
			if (full_path)
				return (full_path);
			start = line + 1;
		}
		line++;
	}
	return (NULL);
}

/* char	*get_cmd_path(char *cmd, char **envp)
{
	char	*end;
	char	*start;
	char	*line;
	char	*dir;
	char	*full;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	line = get_path_line(envp);
	if (!line)
		return (NULL);
	start = line;
	while (*line)
	{
		if (*line == ':' || *(line + 1) == '\0')
		{
			if (*line == ':')
				end = line;
			else
				end = line + 1;
			dir = pipex_substr(start, end);
			full = path_join(dir, cmd);
			free(dir);
			if (access(full, X_OK) == 0)
				return (full);
			free(full);
			start = line + 1;
		}
		line++;
	}
	return (NULL);
} */
