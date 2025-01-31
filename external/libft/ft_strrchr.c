/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:14:03 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 19:03:27 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	while (*(s + slen) != (char)c && slen > 0)
		slen--;
	if (*(s + slen) == (char)c)
		return ((char *)(s + slen));
	else
		return (NULL);
}
