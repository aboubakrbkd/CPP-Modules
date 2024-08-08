CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = Brain
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	 $(CC)  $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp Weapon.hpp HumanB.hpp HumanA.hpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all