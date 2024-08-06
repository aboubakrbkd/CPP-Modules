CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
NAME = Phonebook
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	 $(CC)  $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
