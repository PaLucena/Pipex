/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:22:44 by palucena          #+#    #+#             */
/*   Updated: 2023/06/21 18:46:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;

	paths = ft_split(cmd, ' ');
	path = ft_strjoin("/bin/", paths[0]);
	return (path);
}

void	exec_program(char **av, char **envp)
{
	const char	*path;

	path = find_path(av[2], envp);

	execve(path, av, envp);
}

// ./pipex f "ls -l"