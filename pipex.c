/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:02 by palucena          #+#    #+#             */
/*   Updated: 2023/06/23 17:05:03 by palucena         ###   ########.fr       */
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

	ft_putstr_fd("soy el hijo\n", 1);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		exit(1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	printf("\nHemos llegado a 1.0\n");
	exec_program(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	outfile;

	ft_putstr_fd("soy el padre\n", 1);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile == -1)
		exit(1);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	printf("\nHemos llegado a 1.1\n");
	exec_program(av[3], envp);
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
		waitpid(pid, NULL, 0);
		parent_process(av, envp, fd);
	}
	else
	{
		ft_putstr_fd("Wrong arguments\n", 1);
		ft_putstr_fd("Example: ./pipex file1 cmd1 cmd2 file2\n ", 1);
	}
	return (0);
}
