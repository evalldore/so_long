NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
SRCDDIR	:= ./src/
BINDIR	:= ./bin/
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
ECS		:= ./lib/ecs

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(ECS)/include
LIBS	:= $(ECS)/ecs.a $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
SRCS	:= main.c entities.c so_long.c controls.c movement.c assets.c sprites.c animation.c state.c\
		components/controls.c components/position.c components/gravity.c components/velocity.c components/sprite.c components/collision.c components/animation.c components/state.c
OBJS	:= $(addprefix $(BINDIR), $(SRCS:.c=.o))

all: libmlx libft ecs $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	$(MAKE) -C $(LIBFT)

ecs:
	$(MAKE) -C $(ECS)

$(BINDIR)%.o: $(SRCDDIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(BINDIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BINDIR) :
	mkdir $(BINDIR)
	mkdir $(BINDIR)/components

clean:
	@rm -r $(BINDIR)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(ECS) fclean
	@rm -r $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft