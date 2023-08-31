/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   trees.c                                           o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/29 18:23:01 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/30 18:55:09 by souaguen           oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*remove_char(char *allowed, char c)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	if (strlen(allowed))
		tmp = malloc(sizeof(char) * strlen(allowed));
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
	if (tmp != NULL)
		*(tmp + j) = '\0';
	return (tmp);
}

void	init_tree(t_tree *t, char *allowed)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	t->allowed = allowed;
	if (*(allowed) != '\0')
	{
		t->tree = malloc(sizeof(t_tree) * strlen(allowed));
		while (*(allowed + i) != '\0')
		{
			(t->tree + i)->id = *(allowed + i);
			tmp = remove_char(allowed, *(allowed + i));
			(t->tree + i)->tree = NULL;
			init_tree((t->tree + i), tmp);
			i++;
		}
	}
}

void	read_tree(t_tree *t, char *str, int size)
{
	char	*tmp;
	int		i;	

	i = 0;
	if (strlen((*t).allowed) == 0)
	{
		tmp = (str - (size - 1));
		printf("%s", tmp);
		printf("%c\n", t->id);
	}
	while (i < strlen((*t).allowed))
	{
		if (t->id != 0)
			*(str) = t->id;
		*(str + 1) = '\0';
		if ((t->tree + i) != NULL)
			read_tree((t->tree + i), (str + 1), size);
		free((t->tree + i)->allowed);
		i++;
	}
	if (t->tree != NULL)
		free(t->tree);
}

void	print_comb(char *s)
{
	t_tree	t;
	char	*allowed;
	char	*str;
	int		i;
	int		len;

	len = strlen(s);
	allowed = malloc(sizeof(char) * len + 1);
	str = malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		*(allowed + i) = *(s + i);
		i++;
	}
	*(allowed + i) = '\0';
	*(str) = '\0';
	t.id = 0;
	init_tree(&t, allowed);
	read_tree(&t, str, strlen(allowed));
	free(allowed);
	free(str);
}
