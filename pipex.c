/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:02 by palucena          #+#    #+#             */
/*   Updated: 2023/06/27 16:38:36 by palucena         ###   ########.fr       */
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
	exec_program(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	outfile;

	outfile = open(av[4], O_CREAT | O_RDWR, 0644);
	if (outfile == -1)
		exit(1);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	exec_program(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("Wrong arguments\n", 1);
		ft_putstr_fd("Example: ./pipex file1 cmd1 cmd2 file2\n ", 1);
	}
	if (pipe(fd) == -1)
	{
		ft_putstr_fd("Pipe error\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Fork error\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_process(av, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(av, envp, fd);
	return (0);
}