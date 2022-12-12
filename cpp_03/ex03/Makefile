CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98

INC := -I./

SRC := main.cpp ClapTrap.cpp ft_string.cpp ft_string.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJ := $(SRC:.cpp=.o)

NAME := a.out

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean clean all

.PHONY : clean fclean re all