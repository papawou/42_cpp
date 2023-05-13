CC := c++
CC_FLAGS := -g -Wall -Wextra -Werror -std=c++98

SRC := main.cpp PmergeMe.cpp
OBJ := $(SRC:.cpp=.o)

NAME := PmergeMe

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CC_FLAGS) $< -o $@

%.o : %.cpp
	$(CC) $(CC_FLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

PHONY := all clean fclean re