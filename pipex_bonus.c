/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:13:26 by palucena          #+#    #+#             */
/*   Updated: 2023/07/06 20:53:50 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_doc(char *file, int c)
{
	int	fd;

	fd = 0;
	if (c == 0)
		fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0777);
	else if (c == 1)
		fd = open(file, O_RDONLY, 0777);
	else if (c == 2)
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd <= 0)
		error_message(2);
	return (fd);
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
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

/* void	here_doc(char *limiter, int ac)
{
	
} */

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (ac >= 5)
	{
		/* if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open_doc(av[ac - 1], 0);
			here_doc(av[1], ac);
		}
		else
		{ */
			i = 2;
			infile = open_doc(av[1], 1);
			outfile = open_doc(av[ac - 1], 2);
			dup2(infile, STDIN_FILENO);
		// }
		while (i < ac - 2)
			children_processes(av[++i], envp);
		dup2(outfile, STDOUT_FILENO);
		exec_program(av[ac -2], envp);
	}
	error_message(ac * -1);
}
