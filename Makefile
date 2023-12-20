NAME = philo

SRCC_DIR = src/

SRCC = \
philo.c \
parsing.c \
error.c \
tools.c \
tools_2.c \
threads.c \
init.c 

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread

INCLUDE = -I .
HEADER = philo.h
HEADER_PATH =  $(SRCC_DIR)$(HEADER)

OBJ_DIR = OBJ/
OBJ_PATH = $(SRCC_DIR)$(OBJ_DIR)

OBJ = $(addprefix $(OBJ_PATH), $(SRCC:.c=.o))

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME) -g3

$(OBJ_PATH)%.o : $(SRCC_DIR)%.c $(HEADER_PATH)
	$(CC) $(FLAGS) -c $< -o $@ -g3

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

re : fclean $(NAME)

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ)

.PHONY: all re fclean clean
