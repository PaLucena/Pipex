/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:39:49 by palucena          #+#    #+#             */
/*   Updated: 2023/07/05 19:25:45 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrong_args(int ac)
{
	if (ac < 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		ft_printf("Example:  ./pipex file1 cmd1 cmd2 ... file2\n ");
		exit(EXIT_FAILURE);
	}
	exit(0);
}

int	open_doc(char *file, int c)
{
	int	fd;

	fd = 0;
	if (c == 0)
		fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0777);
	else if (c == 1)
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	else if (c == 2)
		fd = open(file, O_RDONLY, 0777);
	if (fd <= 0)
	{
		ft_printf("Opening error\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
