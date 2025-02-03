NAME	= Bureaucrat
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp

INCLUDE	= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp PresidentialPardonForm.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

mc: all clean

.PHONY : all clean fclean re mc