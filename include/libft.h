/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:40 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/07 20:04:57 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(int count, int size);
int		ft_strlcpy(char *dest, const char *src, int dstsize);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strrchr(char *s, int c);

#endif