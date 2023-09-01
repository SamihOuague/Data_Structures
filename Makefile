# **************************************************************************** #
#                                                                              #
#                                                      oo  #######  oo         #
#    Makefile                                          o o#########o o         #
#                                                         ##  #  ##            #
#    By: SamihOuague <souaguen96@gmail.com>                ### ###             #
#                                                          o#####o             #
#    Created: 2023/08/30 04:11:24 by  SamihOuague       o o # # # o o          #
#    Updated: 2023/09/01 20:31:30 by anonymous          oo         oo          #
#                                                                              #
# **************************************************************************** #

OBJECTS=lib/binary_tree.o lib/queue.o main.o
HEADER=lib/header.h
CC=cc
FLAGS=-Wall -Werror -Wextra
EXEC=tree

all: $(EXEC)
	
tree: $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS) $(HEADER) $(FLAGS)
main.o: main.c
	$(CC) -o main.o -c main.c
binary_tree.o: lib/binary_tree.c
	$(CC) -o binary_tree.o -c binary_tree.c
queue.o:
	$(CC) -o queue.o -c queue.c
clean:
	rm -rf $(OBJECTS) $(EXEC)
