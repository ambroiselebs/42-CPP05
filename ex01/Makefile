NAME = form

SRC = main.cpp src/Bureaucrat.cpp src/Form.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
