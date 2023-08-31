/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   binary_tree.c                                     o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/30 22:36:32 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/31 23:32:49 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include  <stdlib.h>

typedef struct	t_tree {
	struct t_tree	*right;
	struct t_tree	*left;
	int			value;
}	t_tree;

typedef struct  t_queue
{
        struct  t_queue *front;
        t_tree          *value;
}	t_queue;

void	init_tree(t_tree **node, int value)
{
	*(node) = malloc(sizeof(t_tree));
	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->value = value;
}

void    push_queue(t_queue **q, t_tree *value)
{
        t_queue *new_queue;
	
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

void    pop_queue(t_queue **q)
{
        t_queue *tmp;

        tmp = (*q)->front;

        if (*q != NULL)
        {
                free(*q);
                *q = tmp;
        }
}


int	push_tree(t_tree *root, int value)
{
	if (root->left == NULL)
	{
		init_tree(&(root->left), value);
		return (1);
	}
	else if (root->right == NULL)
	{
		init_tree(&(root->right), value);
		return (1);
	}
	return (0);
}

void	print_tab(int level)
{
	int	i;

	i = 0;
	while (i < level)
	{
		printf("\t");
		i++;
	}
}

void	print_tree(t_tree *root, int level)
{
	if (root == NULL)
	{
		print_tab(level);
		printf("---<empty>---\n");
		return ;
	}
	
	print_tab(level);
	printf("Value = %d\n", root->value);
	
	print_tab(level);
	printf("left\n");
	print_tree(root->left, level + 1);

	print_tab(level);
	printf("right\n");
	print_tree(root->right, level + 1);

	print_tab(level);
	printf("done\n");

}

t_tree	*push_node(t_tree *root, int value)
{
        t_tree  *tmp;
        t_queue *q;

	q = NULL;
	tmp = NULL;
	push_queue(&q, root);
        while (q != NULL)
        {
                tmp = (q->value);
                pop_queue(&q);
                if (tmp->left != NULL)
                        push_queue(&q, tmp->left);
                else
		{
			push_tree(tmp, value);
                        return (root);
		}
                if (tmp->right != NULL)
                        push_queue(&q, tmp->right);
                else
		{
			push_tree(tmp, value);
                        return (root);
        	}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_tree	t;
	t_tree	*tmp;
	t_queue	*q;
	int	n[10];
	int	i;
	int	size;

	size = 10;
	i = 0;
	while (i < size)
	{
		n[size - (size - i)] = size - i;
		i++;
	}
	t.value = n[0];
	t.left = NULL;
	t.right = NULL;

	i = 1;
	while (i < size)
	{
		push_node(&t, n[i]);
		i++;
	}
	//printf("%d\n", tmp->value);
	print_tree(&t, 0);
	return (0);
}
