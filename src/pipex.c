/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:02 by palucena          #+#    #+#             */
/*   Updated: 2023/07/12 17:23:56 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open_doc(av[1], 1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	exec_program(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	outfile;

	outfile = open_doc(av[4], 2);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	exec_program(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			exit(EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			child_process(av, envp, fd);
		wait(0);
		parent_process(av, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Wrong number of arguments\n", 1);
		ft_putstr_fd("Example: ./pipex infile cmd1 cmd2 outfile\n", 1);
	}
	return (0);
}
