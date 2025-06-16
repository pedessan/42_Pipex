/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:07:55 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 15:44:37 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

/* UTILS */

//int		pipex_wordcount(char *s);
char	*pipex_substr(char *start, char *end);
//char	**pipex_split(char *s);
//int		pipex_strlen(char *s);
//int		pipex_strncmp(char *s1, char *s2, int n);
//char	*pipex_strnstr(char *hay, char *needle, int len);

/* PIPEX */

void	child_1(int pipefd[2], char **argv, char **envp);
void	child_2(int pipefd[2], char **argv, char **envp);
void	error_exit(char *msg);
void	exec_cmd(char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
char	*get_path_line(char **envp);
char	*path_join(char *path, char *cmd);

#endif
