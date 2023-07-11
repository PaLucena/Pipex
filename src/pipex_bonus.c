/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:13:26 by palucena          #+#    #+#             */
/*   Updated: 2023/07/11 17:03:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parent_process_bonus(int *fd)
{
	waitpid(-1, NULL, 0);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}

void	children_processes(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
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
	pid_t	here_doc;
	int		fd[2];
	char	*str;

	if (ac < 6)
		exit(-1);
	if (pipe(fd) == -1)
		exit(-1);
	here_doc = fork();
	if (here_doc == -1)
		exit(-1);
	else if (here_doc == 0)
	{
		close(fd[0]);
		str = get_next_line(0);
		while (ft_strcmp(str, limiter) != 10)
		{
			ft_putstr_fd(str, fd[1]);
			str = get_next_line(0);
		}
		exit(EXIT_SUCCESS);
	}
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
			i = 2;
			outfile = open_doc(av[ac - 1], 2);
			here_doc(av[2], ac);
		}
		else
		{
			i = 1;
			infile = open_doc(av[1], 1);
			outfile = open_doc(av[ac - 1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < ac - 2)
			children_processes(av[++i], envp);
		dup2(outfile, STDOUT_FILENO);
		exec_program(av[ac -2], envp);
	}
	error(ac);
}
