/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:13:26 by palucena          #+#    #+#             */
/*   Updated: 2023/07/05 19:10:39 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		ft_printf("Pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		exec_program(cmd, envp);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
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
			infile = open_doc(av[1], 2);
			outfile = open_doc(av[ac - 1], 2);
			dup2(infile, STDIN_FILENO);
		// }
		while (i < ac - 2)
			child_process(av[++i], envp);
		dup2(outfile, STDOUT_FILENO);
		exec_program(av[ac -2], envp);
	}
	wrong_args(ac);
}
