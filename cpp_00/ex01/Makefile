CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

INC := -I ./

SRC := PhoneBook.class.cpp Contact.class.cpp phonebook.cpp ft_string.cpp
OBJ := $(SRC:.cpp=.o)

NAME := phonebook

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