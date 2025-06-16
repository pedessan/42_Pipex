/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:50:53 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 16:22:43 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//prova a sostituire con libft substr?

char	*pipex_substr(char *start, char *end)
{
	char	*s;
	char	*p;
	int		len;

	len = end - start;
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	p = s;
	while (start < end)
		*p++ = *start++;
	*p = '\0';
	return (s);
}
