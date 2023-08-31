/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   queue.c                                           o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/31 20:46:53 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/31 21:52:49 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct  t_tree {
        struct t_tree   *right;
        struct t_tree   *left;
        int                     value;
}       t_tree;

typedef struct  t_queue
{
        struct  t_queue *front;
        t_tree		*value;
}	t_queue;

void	push_queue(t_queue **q, t_tree *value)
{
	t_queue	*new_queue;
	
	if (*q == NULL)
	{
		*q = malloc(sizeof(t_queue));
		(*q)->value = value;
		return ;
	}

	new_queue = malloc(sizeof(t_queue));
	new_queue->value = value;
	new_queue->front = *q;
	*q = new_queue;
}

void	pop_queue(t_queue **q)
{
	t_queue	*tmp;

	tmp = (*q)->front;
	
	if (*q != NULL)
	{
		free(*q);
		*q = tmp;

	}
}
