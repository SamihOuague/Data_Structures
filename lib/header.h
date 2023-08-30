/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   header.h                                          o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/30 03:49:08 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/30 04:25:01 by souaguen           oo         oo         */
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

char	*remove_char(char *allowed, char c);
void	init_tree(t_tree *t, char *allowed);
void	read_tree(t_tree *t, char *str, int size);
void	print_comb(char *s);
