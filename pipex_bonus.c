/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:13:26 by palucena          #+#    #+#             */
/*   Updated: 2023/06/27 21:32:44 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	here_doc()
{
	
}

int	main(int ac, char **av, char **envp)
{
	int	i;

	if (ac <= 5)
	{
		if (ft_strncmp(av[ac - 1], "here_doc", 8) == 0)
			here_doc();
		else
			// algo
	}
	return (0);
}