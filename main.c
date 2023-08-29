/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   main.c                                            o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/29 18:23:01 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/29 21:20:47 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	t_tree
{
	struct t_tree	*tree;
	char		*allowed;
	int			id;

}	t_tree;

char	*remove_char(char *allowed, char c)
{
	char	*tmp = malloc(sizeof(char) * strlen(allowed));
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(allowed + i) != '\0')
	{
		if (*(allowed + i) != c)
		{
			*(tmp + j) = *(allowed + i);
			j++;
		}
		i++;
	}
	*(tmp + j) = '\0';
	free(allowed);
	allowed = tmp;
	return (tmp);
}


int	main()
{
	char	*allowed;
	int		i;
	
	allowed = malloc(sizeof(char) * 5);
	i = 0;
	while (i < 4)
	{
		*(allowed + i) = '0' + (i + 1);
		i++;
	}
	*(allowed + i) = '\0';
	printf("%s\n", allowed);
	free(allowed);
	return (0);
}
