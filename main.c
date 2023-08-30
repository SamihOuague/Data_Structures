/* ************************************************************************** */
/*                                                                            */
/*                                                     oo  #######  oo        */
/*   main.c                                            o o#########o o        */
/*                                                        ##  #  ##           */
/*   By: SamihOuague <souaguen96@gmail.com>                ### ###            */
/*                                                         o#####o            */
/*   Created: 2023/08/30 03:58:21 by  SamihOuague       o o # # # o o         */
/*   Updated: 2023/08/30 04:24:31 by souaguen           oo         oo         */
/*                                                                            */
/* ************************************************************************** */

#include "lib/header.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	print_comb(argv[1]);
	return (0);
}
