NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = src/pipex.c src/utils.c
SRCS_BONUS = src/pipex_bonus.c src/utils.c src/utils_bonus.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

src/%.o: src/%.c
	@echo "\033[32mCompiling $< → $@\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Llibft -lft -o $(NAME)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -Llibft -lft -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	@echo "\033[34mObject files cleaned.\033[0m"
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

tclean:
	@echo "\033[34mText files cleaned.\033[0m"
	@rm -f *.txt

re: fclean all

.PHONY: all bonus clean fclean re
