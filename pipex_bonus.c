/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:13:26 by palucena          #+#    #+#             */
/*   Updated: 2023/07/09 18:15:54 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process_bonus(int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	waitpid(-1, NULL, 0);
}

void	children_processes(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_message(0);
	pid = fork();
	if (pid == -1)
		error_message(1);
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec_program(cmd, envp);
	}
	else
		parent_process_bonus(fd);
}

void	here_doc(char *limiter, int ac)
{
	int		here_doc;
	int		fd[2];
	char	*str;

	if (ac != 6)
		error_message(-1);
	if (pipe(fd) == -1)
		error_message(0);
	here_doc = fork();
	if (here_doc == -1)
		error_message(1);
	else if (here_doc == 0)
	{
		close(fd[0]);
		str = get_next_line(0);
		while (str)
		{
			if (ft_strcmp(str, limiter) != 0)
				break ;
			ft_putstr_fd(str, fd[1]);
		}
	}
	else
		parent_process_bonus(fd);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open_doc(av[ac - 1], 2);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			infile = open_doc(av[1], 1);
			outfile = open_doc(av[ac - 1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < ac - 2)
			children_processes(av[++i], envp);
		dup2(outfile, STDOUT_FILENO);
		exec_program(av[ac -2], envp);
	}
	error_message(ac * -1);
}
