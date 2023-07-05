/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:22:44 by palucena          #+#    #+#             */
/*   Updated: 2023/07/05 19:08:14 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**all_paths;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (all_paths[++i])
	{
		path = ft_strjoin(ft_strjoin(all_paths[i], "/"), cmd);
		if (access(path, X_OK) == 0)
			return (path);
	}
	return (0);
}

void	exec_program(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_new;

	cmd_new = ft_split(cmd, ' ');
	path = find_path(cmd_new[0], envp);
	if (access(path, F_OK) == -1)
	{
		ft_printf("Error: command not found");
		exit(EXIT_FAILURE);
	}
	execve(path, cmd_new, envp);
}
