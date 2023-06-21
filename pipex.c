/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:02 by palucena          #+#    #+#             */
/*   Updated: 2023/06/21 18:46:24 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. Analizar el input
// 2. Ejecutar los comandos
// 3. Eliminar archivos temporales

// ./pipex infile cmd1 cmd2 outfile

#include "pipex.h"

void	child_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		exit(1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	exec_program(av, envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	outfile;

	wait(NULL);
	outfile = open(av[4], O_WRONLY);
	if (outfile == -1)
		exit(1);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(outfile);
	exec_program(av, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		pid = fork();
		if (pipe(fd) == -1)
			return (1);
		else if (pid == -1)
			return (1);
		if (pid == 0)
			child_process(av, envp, fd);
		else
			parent_process(av, envp, fd);
	}
	else
	{
		ft_putstr_fd("Wrong arguments\n", 1);
		ft_putstr_fd("Example: ./pipex file1 cmd1 cmd2 file2\n ", 1);
	}
	return (0);
}
