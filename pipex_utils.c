/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:22:44 by palucena          #+#    #+#             */
/*   Updated: 2023/06/23 16:26:56 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**a;
	int		i;

	i = 0;
	printf("\nHemos llegado a 1\n");
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	a = ft_split(envp[i] + 5, ':');
	printf("Hemos llegado a 2\n");
	i = 0;
	path = ft_strjoin(ft_strjoin(a[i], "/"), cmd);
	while (access(path, F_OK) != 0)
	{
		i++;
		path = ft_strjoin(ft_strjoin(a[i], "/"), cmd);
	}
	printf("Hemos llegado a 3\n");
	return (path);
}

void	exec_program(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_new;

	printf("\nHemos llegado a 0\n");
	cmd_new = ft_split(cmd, ' ');
	path = find_path(cmd_new[0], envp);
	printf("sale de find path\n");
	if (access(path, F_OK) != -1)
		execve(path, &cmd, envp);
	else
		ft_putstr_fd("Error: command not found", 1);
}

// ./pipex f "ls -l"