CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98 -g

INC := -I./

SRC := main.cpp Conversion.cpp

OBJ := $(SRC:.cpp=.o)

NAME := convert

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

.PHONY : clean fclean re all%