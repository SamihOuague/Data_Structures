/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   header.h                                          o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/30 03:49:08 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/31 20:53:42 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_tree
{
	struct t_tree	*tree;
	char			*allowed;
	char			id;

}	t_tree;

typedef	struct	t_queue
{
	struct	t_queue	*front;
	t_tree		*value;
}	t_queue;

char	*remove_char(char *allowed, char c);
void	push_queue(t_queue *q, t_tree *value);
void	pop_queue(t_queue *q);
void	init_tree(t_tree *t, char *allowed);
void	read_tree(t_tree *t, char *str, int size);
void	print_comb(char *s);
