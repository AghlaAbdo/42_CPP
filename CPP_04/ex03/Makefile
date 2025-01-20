NAME	= Materia
CC		= c++
FLAGS	= -Wall -Wextra -Werror

SRC		= main.cpp AMateria.cpp ICharacter.cpp Character.cpp \
			Ice.cpp Cure.cpp IMateriaSource.cpp MateriaSource.cpp grb.cpp

INCLUDS = AMateria.hpp ICharacter.hpp Ice.hpp IMateriaSource.hpp \
			MateriaSource.hpp Cure.hpp grb.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp $(INCLUDS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

mc: all clean

.PHONY : all clean fclean re mc