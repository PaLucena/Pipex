/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:39:24 by palucena          #+#    #+#             */
/*   Updated: 2023/07/09 18:10:32 by palucena         ###   ########.fr       */
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
		free(path);
	}
	i = -1;
	while (all_paths[++i])
		free(all_paths[i]);
	free(all_paths);
	return (0);
}

void	exec_program(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_new;
	int		i;

	cmd_new = ft_split(cmd, ' ');
	path = find_path(cmd_new[0], envp);
	i = -1;
	if (!path)
	{
		while (cmd_new[++i])
			free(cmd_new[i]);
		free(cmd_new);
	}
	if (access(path, F_OK) == -1)
		error_message(3);
	execve(path, cmd_new, envp);
}

void	error_message(int e)
{
	if (e > -5 && e <= 3)
	{
		if (e > -5 && e < 0)
		{
			ft_putstr_fd("\n\t\033[31mError: Wrong number of arguments\n", 1);
			ft_putstr_fd("\n\tExample:  ./pipex file1 cmd1 cmd2 ... file2\n", 1);
		}
		else if (e == 0)
			ft_putstr_fd("\n\t\033[31mPipe error\n", 1);
		else if (e == 1)
			ft_putstr_fd("\n\t\033[31mFork error\n", 1);
		else if (e == 2)
			ft_putstr_fd("\n\t\033[31mOpening error\n", 1);
		else if (e == 3)
			ft_putstr_fd("\\n\t033[31mError: Command not found\n", 1);
		ft_putstr_fd("\n", 1);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	open_doc(char *file, int c)
{
	int	fd;

	fd = 0;
	if (c == 1)
		fd = open(file, O_RDONLY, 0777);
	else if (c == 2)
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
		error_message(2);
	return (fd);
}
