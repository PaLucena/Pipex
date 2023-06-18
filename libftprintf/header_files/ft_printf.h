/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:37:47 by palucena          #+#    #+#             */
/*   Updated: 2023/05/01 14:07:47 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int		ft_printchar(char c);
int		ft_printdec(int nb);
int		ft_printf(char const *type, ...);
int		ft_printhexa(unsigned long long nb, char c);
int		ft_printptr(unsigned long long ptr);
int		ft_printstr(char *str);
int		ft_printunsigned(unsigned int nb);
void	ft_putchar(char c);

#endif