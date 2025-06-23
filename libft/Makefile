CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_isspace.c ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_nb_to_string.c \
ft_uns_to_string.c ft_strdup.c ft_strlen.c ft_printf.c ft_nb_hex.c ft_write_ptr.c ft_write_text.c \
get_next_line.c get_next_line_utils.c

OBJECTS = $(SRCS:.c=.o)

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
ft_lstpenultimate.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_O = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

bonus: $(OBJECTS) $(BONUS_O)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

bclean: clean
	rm -f $(OBJECTS) $(BONUS_O)

re: fclean all

.PHONY: all clean fclean re