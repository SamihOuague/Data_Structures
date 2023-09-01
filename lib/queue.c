/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   queue.c                                           o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/31 20:46:53 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/09/01 21:01:33 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	push_queue(t_queue **q, t_tree *value)
{
	t_queue		*new_queue;

	if (*q == NULL)
	{
		*q = malloc(sizeof(t_queue));
		(*q)->value = value;
		(*q)->front = NULL;
		return ;
	}
	new_queue = (*q);
	while (new_queue->front != NULL)
		new_queue = new_queue->front;
	new_queue->front = malloc(sizeof(t_queue));
	(new_queue->front)->value = value;
	(new_queue->front)->front = NULL;
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

void	empty_queue(t_queue **q)
{
	while ((*q) != NULL)
		pop_queue(q);
}
