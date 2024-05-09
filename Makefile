.SILENT:

NAME	:= cub3d
CC		:= gcc
CFLAGS	:= -Ofast -Wextra -Wall -Werror -Wunreachable-code
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
GNL		:= ./lib/get_next_line
OBJDIR	:= ./obj

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/includes -I $(GNL)

LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm

SRCS	:=	src/main.c \
			src/ft_error.c \
			src/ft_hooks.c \
			src/ft_keys.c \
			src/raycast_utils.c \
			src/raycast.c \
			src/render.c \
			src/render_wall.c \
			src/init/ft_textures_load.c \
			src/init/ft_colors.c \
			src/init/ft_init_utils.c \
			src/init/ft_flood_fill.c \
			src/init/ft_init_map.c \
			src/init/ft_map2d.c \
			src/init/ft_realloc_file.c \
			src/init/ft_texture_utils.c \
			src/init/ft_texture.c \
			./lib/get_next_line/get_next_line.c \
			./lib/get_next_line/get_next_line_utils.c

OBJS	:= ${SRCS:.c=.o}
OBJS	:= $(addprefix $(OBJDIR)/,$(notdir $(OBJS)))


all: libmlx libft $(NAME)

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone --depth 1 --branch v2.3.2 https://github.com/codam-coding-college/MLX42 $(LIBMLX) && \
		cmake -S $(LIBMLX) -B $(LIBMLX)/build && \
		make -C $(LIBMLX)/build -j4; \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

rmlibmlx:
	@rm -rf $(LIBMLX)

libft:
	@make -C $(LIBFT)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(OBJDIR)/%.o: src/init/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(OBJDIR)/%.o: ./lib/get_next_line/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re, bonus, libmlx, libft, rmlibmlx