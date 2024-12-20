CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I. -Iprintf -Ignl
NAME    = libft.a

SRC = ft_strlen.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
      ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_memset.c ft_bzero.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
      ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
      ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

PRINTF_GNL_SRC = printf/ft_printf.c printf/ft_utils.c printf/ft_utils_np.c \
				gnl/get_next_line.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
        ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
        ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o) $(PRINTF_GNL_SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "libft compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Library removed."

re: fclean all

bonus: $(OBJ) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJS)
	@echo "Bonus functions added to libft!"

.PHONY: all clean fclean re bonus