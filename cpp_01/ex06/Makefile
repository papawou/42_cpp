CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

INC := -I./
SRC := main.cpp Harl.cpp
OBJ := $(SRC:.cpp=.o)

NAME := HarlFilter

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re