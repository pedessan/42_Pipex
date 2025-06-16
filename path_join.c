/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:47:49 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 15:42:55 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_join(char *path, char *cmd)
{
	char	*full;
	int		plen;
	int		clen;
	int		i;

	plen = ft_strlen(path);
	clen = ft_strlen(cmd);
	full = malloc(plen + clen + 2);
	if (!full)
		return (NULL);
	i = 0;
	while (i < plen)
	{
		full[i] = path[i];
		i++;
	}
	full[plen] = '/';
	i = 0;
	while (i < clen)
	{
		full[plen + 1 + i] = cmd[i];
		i++;
	}
	full[plen + 1 + clen] = '\0';
	return (full);
}
