NAME	= MyContacts
CC		= g++
FLAGS	= -Wall -Wextra -Werror

SRC		= main.cpp		\
		PhoneBook.cpp	\
		Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re