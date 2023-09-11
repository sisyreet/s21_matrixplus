NAME			= s21_matrix

SRCS			= main.cpp s21_matrix_oop.cpp

HEADER			= s21_matrix_oop.h

OBJS			= $(SRCS:.cpp=.o)

CC				= g++
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -g

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@ 

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all