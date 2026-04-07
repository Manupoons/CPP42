NAME = animal

BRIGHT_GREEN = \033[1;92m

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

.cpp.o:
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(BRIGHT_GREEN)$(NAME) created.\n"

clean:
	@$(RM) $(OBJ)
	@echo "\n$(BRIGHT_GREEN)Cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "\n$(BRIGHT_GREEN)Full clean\n"

re: fclean $(NAME);

.PHONY: all clean fclean re