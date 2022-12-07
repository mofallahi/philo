NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC = main.c ft_atoi.c
OBJ = $(SRC:.c=.o)
INC = philo.h

all : $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf philo

re: fclean all