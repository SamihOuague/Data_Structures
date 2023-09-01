/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   main.c                                            o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/30 03:58:21 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/09/01 20:54:47 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "lib/header.h"

void	init_root(t_tree **t, int value)
{
	*t = malloc(sizeof(t_tree));
	(*t)->left = NULL;
	(*t)->right = NULL;
	(*t)->value = value;
}

void	free_tree(t_tree *t)
{
	if (t == NULL)
		return ;
	free_tree(t->left);
	free_tree(t->right);
	free(t->left);
	free(t->right);
}

int	main(int argc, char **argv)
{
	t_tree	*t;

	t = NULL;
	init_root(&t, 42);
	push_node(t, 24);
	push_node(t, 23);
	push_node(t, 18);
	print_tree(t, 0);
	free_tree(t);
	free(t);
	return (0);
}
