##
##
##  Author : Aurelien Girardeau
##
##

NAME		=		mazer

CC		=		g++

RM		=		rm -f

INCL_DIR	=		includes/

SOURCE_DIR	=		sources

CXXFLAGS	=		-Wall -pedantic -std=c++14 -g3 -I./$(INCL_DIR)

SRCS		=		$(SOURCE_DIR)/Edge.cpp \
				$(SOURCE_DIR)/Maze.cpp \
				$(SOURCE_DIR)/GenMaze.cpp \
				$(SOURCE_DIR)/LoadMaze.cpp \
				$(SOURCE_DIR)/DomElement.cpp \
				$(SOURCE_DIR)/SVGGenerator.cpp \
				$(SOURCE_DIR)/Node.cpp \
				$(SOURCE_DIR)/ArgsTree.cpp \
				$(SOURCE_DIR)/MazeCore.cpp \
				$(SOURCE_DIR)/Utils.cpp \
				$(SOURCE_DIR)/AldousBroder.cpp \
				$(SOURCE_DIR)/Eller.cpp \
				$(SOURCE_DIR)/Factory.cpp \
				$(SOURCE_DIR)/SolveMaze.cpp \
				$(SOURCE_DIR)/ManhattanH.cpp \
				$(SOURCE_DIR)/EuclideanH.cpp \
				$(SOURCE_DIR)/Dijkstra.cpp \
				$(SOURCE_DIR)/DepthFirst.cpp \
				$(SOURCE_DIR)/BreadthFirst.cpp \
				main.cpp

OBJS		=		$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
