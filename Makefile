NAME = ircserv

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp SRC/Authenti.cpp SRC/Channel.cpp SRC/Client.cpp SRC/Server.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

git:
	find . -type f -name '*.o' -exec rm {} +
	@git add .
	@git commit
	@git push
	@clear
	@echo "|                                                 |"
	@echo "|                                                 |"
	@echo "|      -------{ Commited and Pushed }-------      |"
	@echo "|                                                 |"
	@echo "|                                                 |"

.PHONY: all clean fclean re