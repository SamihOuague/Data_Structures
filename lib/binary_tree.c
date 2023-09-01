/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   binary_tree.c                                     o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/30 22:36:32 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/09/01 21:02:46 by anonymous          oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_tree(t_tree **node, int value)
{
	*(node) = malloc(sizeof(t_tree));
	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->value = value;
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
	t_tree	*tmp;
	t_queue	*q;

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
                	empty_queue(&q);
			return (root);
		}
		if (tmp->right != NULL)
			push_queue(&q, tmp->right);
		else
		{
			push_tree(tmp, value);
			empty_queue(&q);
			return (root);
		}
	}
}
