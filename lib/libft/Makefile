NAME = libft.a

CC = cc

OBJ_DIR	= obj/

CFLAGS = -Wall -Werror -Wextra -I.

#######################################################################################

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c  ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

EXTRA_UTILS = extra_utils/ft_fibonacci.c extra_utils/ft_sqrt.c extra_utils/ft_strcmp.c

#######################################################################################

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o) $(EXTRA_UTILS:%.c=$(OBJ_DIR)%.o)

BONUS_OBJ = $(BONUS:%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#######################################################################################

all: $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	rm -f $(OBJ_DIR)*.o
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	# @echo $(NAME) deleted

re: fclean all

.PHONY: all clean fclean re bonus
