CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = RPN
SRCS = main.cpp RPN.cpp 
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	 $(CC)  $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp RPN.hpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all