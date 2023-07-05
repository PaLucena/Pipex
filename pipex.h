/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:19 by palucena          #+#    #+#             */
/*   Updated: 2023/07/05 19:13:18 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

// pipex_utils.c
void	exec_program(char *av, char **envp);
char	*find_path(char *cmd, char **envp);

// pipex_utils_bonus.c
void	wrong_args(int ac);
int		open_doc(char *file, int c);

#endif