/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:37:58 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/26 09:21:31 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	c;
	char	*str;
	char	*tmp;

	c = ft_getchar(fd);
	if (c == EOF || c == 0)
		return (NULL);
	str = ft_c_to_str(c);
	if (!str)
		return (NULL);
	while (c != '\n' && c != EOF)
	{
		c = ft_getchar(fd);
		if (c == '\n' || c == EOF)
			break ;
		tmp = ft_str_c_join(str, c);
		free(str);
		if (!tmp)
			return (NULL);
		str = tmp;
	}
	return (str);
}

// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("testfile.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("output: %s\n", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }