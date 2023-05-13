CC := c++
CC_FLAGS := -g -Wall -Wextra -Werror -std=c++98 -I./inc

SRC_DIR := ./src
OBJ_DIR := ./obj

SRC := main.cpp

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME := btc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CC_FLAGS) $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CC_FLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

PHONY := all clean fclean re