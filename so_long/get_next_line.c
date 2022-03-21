/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:01:02 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:53:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#define	BUFFER_SIZE 10

int	kot(int fd, char *buf, char **thc)
{
	int	b;

	b = read(fd, buf, 10);
	while (b > 0)
	{
		buf[b] = '\0';
		if (!*thc)
			*thc = ft_substr(buf, 0, b);
		else
			*thc = ft_strjoin(*thc, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		b = read(fd, buf, 10);
	}
	free(buf);
	return (b);
}

static char	*kot2(char **thc, int b)
{
	int		j;
	char	*ret;
	char	*tmp;

	if (!*thc)
		return (0);
	if (b == 0 && *thc[0] == '\0')
	{
		free(*thc);
		*thc = 0;
		return (NULL);
	}
	if (!ft_strchr(*thc, '\n'))
	{
		ret = ft_substr(*thc, 0, ft_strlen(*thc));
		free(*thc);
		*thc = 0;
		return (ret);
	}
	j = ft_strlen(ft_strchr(*thc, '\n'));
	ret = ft_substr(*thc, 0, ft_strlen(*thc) - j + 1);
	tmp = *thc;
	*thc = ft_substr(ft_strchr(*thc, '\n'), 1, j);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*thc;
	char		*buf;
	int			b;

	buf = malloc(sizeof(char) * (10 + 1));
	if (fd == -1 || !buf || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	b = kot(fd, buf, &thc);
	return (kot2(&thc, b));
}

//int main()
//{
//	int fd;
//	char *lene;
//
//	fd = open("text.txt", O_RDONLY);
//	//	while ((lene = get_next_line(fd)))
//	//		printf("%s", lene);
//	lene = get_next_line(fd);
//	printf("%s", lene);
//	lene = get_next_line(fd);
//	printf("%s", lene);
//}
