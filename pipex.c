/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:02 by palucena          #+#    #+#             */
/*   Updated: 2023/06/20 15:19:38 by palucena         ###   ########.fr       */
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
		perror();
	dup2(av[1], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	cloes(ev[1])
	exec_program(); // Está por empezar
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	outfile;

	wait(NULL);
	outfile = open(av[4], O_WRONLY);
	if (outfile == -1)
		perror();
	dup2(av[4], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(av[4]);
	exec_program();
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		pid = fork();
		if (pipe(fd) == -1)
			return (perror("pipe: "));
		else if (pid == -1)
			return (perror("fork: "));
		if (pid == 0)
			child_process(av, envp, fd);
		else
			parent_process(av, envp, fd);
	}
	else
	{
		ft_putstr_fd("Wrong arguments\n");
		ft_putstr_fd("Example: ./pipex file1 cmd1 cmd2 file2\n ");
	}
	return (0);
}
