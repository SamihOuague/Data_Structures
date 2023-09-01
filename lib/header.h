/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   header.h                                          o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/30 03:49:08 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/09/01 21:02:11 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_tree
{
	struct t_tree	*right;
	struct t_tree	*left;
	int				value;
}	t_tree;

typedef struct t_queue
{
	struct t_queue	*front;
	t_tree			*value;
}	t_queue;

t_tree	*push_node(t_tree *root, int value);
void	push_queue(t_queue **q, t_tree *value);
void	pop_queue(t_queue **q);
void	init_tree(t_tree **node, int value);
void	print_tab(int level);
void	print_tree(t_tree *root, int level);
void	empty_queue(t_queue **q);
int		push_tree(t_tree *root, int value);
