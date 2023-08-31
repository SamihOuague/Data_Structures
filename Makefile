# **************************************************************************** #
#                                                                              #
#                                                      oo  #######  oo         #
#    Makefile                                          o o#########o o         #
#                                                         ##  #  ##            #
#    By: SamihOuague <souaguen96@gmail.com>                ### ###             #
#                                                          o#####o             #
#    Created: 2023/08/30 04:11:24 by  SamihOuague       o o # # # o o          #
#    Updated: 2023/08/30 22:32:22 by souaguen           oo         oo          #
#                                                                              #
# **************************************************************************** #

OBJECTS=lib/comb_tree.o main.o
HEADER=lib/header.h
CC=cc
FLAGS=-Wall -Werror -Wextra
EXEC=tree

all: $(EXEC)
	
tree: $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS) $(HEADER) $(FLAGS)
main.o: main.c
	$(CC) -o main.o -c main.c
trees.o: lib/comb_tree.c
	$(CC) -o comb_tree.o -c comb_tree.c
clean:
	rm -rf $(OBJECTS) $(EXEC)
