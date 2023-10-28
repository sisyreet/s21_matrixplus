NAME		= s21_matrix_oop.a
TEST		= test
SRCS		= s21_matrix_oop.cpp
T_SRCS		= s21_matrix_tests.cpp s21_matrix_oop.cpp

HEADER		= s21_matrix_oop.h

OBJS		= $(SRCS:%.cpp=%.o)
T_OBJS		= $(T_SRCS:%.coo=%.o)

CXX			= g++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g -std=c++17
TEST_LIBS	= -lgtest -lstdc++ -pthread -lm
AR			= ar rcs

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $@ $?

test:			$(NAME) $(T_OBJS)
				$(CXX) -g -o $@ $? $(TEST_LIBS)
				./$(TEST)

%.o:			%.cpp $(HEADER)
				$(CXX) $(CFLAGS) -c $< -o $@ 

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(TEST)

re:				fclean all