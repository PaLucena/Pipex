/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:39:24 by palucena          #+#    #+#             */
/*   Updated: 2023/07/10 17:19:56 by palucena         ###   ########.fr       */
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
		exit(-1);
	execve(path, cmd_new, envp);
}

void	error(int e)
{
	if (e < 6)
	{
		ft_putstr_fd("\n\033[31mError: Wrong number of arguments\n", 1);
		ft_putstr_fd("Example: ./pipex_bonus infile cmd1 cmd2 ... outfile\n", 1);
		ft_putstr_fd("\t ./pipex_bonus here_doc LIMITER cmd1 cmd2 outfile\n\n", 1);
		exit(-1);
	}
	else
		exit(0);
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
		exit(-1);
	return (fd);
}
