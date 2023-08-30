# **************************************************************************** #
#                                                                              #
#                                                      oo  #######  oo         #
#    Makefile                                          o o#########o o         #
#                                                         ##  #  ##            #
#    By: SamihOuague <souaguen96@gmail.com>                ### ###             #
#                                                          o#####o             #
#    Created: 2023/08/30 04:11:24 by  SamihOuague       o o # # # o o          #
#    Updated: 2023/08/30 04:22:15 by anonymous          oo         oo          #
#                                                                              #
# **************************************************************************** #

OBJECTS=lib/trees.o main.o
HEADER=lib/header.h
CC=cc
FLAGS=-Wall -Werror -Wextra
EXEC=tree

all: $(EXEC)
	
tree: $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS) $(HEADER) $(FLAGS)
main.o: main.c
	$(CC) -o main.o -c main.c
trees.o: lib/trees.c
	$(CC) -o trees.o -c trees.c
clean:
	rm -rf $(OBJECTS) $(EXEC)
