/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:48:33 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 15:36:24 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_line(char **envp)
{
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}
