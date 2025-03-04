NAME	= span
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp Span.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

mc: all clean

.PHONY : all clean fclean re mc