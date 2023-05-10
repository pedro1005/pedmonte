/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:31:21 by pedmonte          #+#    #+#             */
/*   Updated: 2023/05/10 20:09:36 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line; 		/*linha do ficheiro a devolver*/
	ssize_t		numRead;	/*numero de bytes devolvidos pelu ultimo read()*/
	size_t		total;		/*numero total de bytes lidos*/
	
	return (line);
}

int main()
{
	FILE	*fp = fopen("test.txt", "r");
	int	fd = fileno(fp);
	char	*line;
	line = (char *)malloc(BUFFER * sizeof(char));
	size_t	start = 4;
	ssize_t	sizeLine = read(fd, line, BUFFER);

	fgets(line, 50, fp);
	printf("%s\n%zu\n%zd", line, start, sizeLine);

	return (0);
}

