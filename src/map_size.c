/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:42:50 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 18:43:07 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/error.h"
#include "../include/game.h"
#include "../include/get_next_line.h"
#include <fcntl.h>

// COUNT MAP FILEFUNCTION ->	Dosyayı satır satır okur ve counter variablei
//								oluşturur. Alınan fonksiyona göre değişen counter
//								gönderir.
// -> WIDTH fonksiyonu ->		New line kontrolü yapar bu sayede get next line
//								\n döndürdüyse bile doğru hesap yapar.
//								alınan değer pointer olmak zorunda adresi çünkü
//								counter ile çalışan ana fonksiyonun yardımcı
//								fonksiyonu olarak kullanıyorum.
// -> HIEGHT fonksiyonu ->		Zaten halihazırda satır saydığı için bu
//								yardımcı fonksiyon sadece counteri arttırır.

int	count_width(int *counter, char *line)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (*(line + line_len - 1) == '\n')
		line_len = ft_strlen(line) - 1;
	if (*counter == 0)
		*counter = line_len;
	if (*counter != line_len)
		return (1);
	return (0);
}

int	count_height(int *counter, char *line)
{
	(void)line;
	(*counter)++;
	return (0);
}

int	count_map_file(const char *map_path, int (*f)(int*, char*))
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (f(&counter, line))
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}
