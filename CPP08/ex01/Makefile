CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = Span
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	 $(CC)  $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp Span.hpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all