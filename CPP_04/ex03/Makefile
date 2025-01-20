NAME	= Animal
CC		= c++
FLAGS	= -Wall -Wextra -Werror

SRC		= main.cpp AMateria.cpp ICharacter.cpp Character.cpp Ice.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp AMateria.hpp ICharacter.hpp Ice.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

mc: all clean

.PHONY : all clean fclean re mc