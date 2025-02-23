/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:40 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 16:04:06 by ysumeral         ###   ########.fr       */
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
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strrchr(char *s, int c);

#endif