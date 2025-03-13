#####################################SO_LONG#####################################

NAME	=		so_long
NAME_BONUS	=	so_long_bonus

#####################################SRCS########################################

PATH_SRCS	=	srcs/

SRCS	+= exit.c
SRCS	+= init.c
SRCS	+= parsing.c
SRCS	+= valid_path.c
SRCS	+= read_map.c
SRCS	+= utils.c
SRCS	+= visuals.c
MAIN	+= srcs/main.c

vpath	%.c	$(PATH_SRCS)

PATH_SRCS_BONUS	=	srcs_bonus/

SRCS_BONUS	+=	main_bonus.c

vpath	%.c	$(PATH_SRCS_BONUS)

###################################OBJS#########################################

PATH_OBJS	=	objs
OBJS	=	$(patsubst	%.c,	$(PATH_OBJS)/%.o,	$(SRCS))
MAIN	=	$(patsubst	%.c,	$(PATH_OBJS)/%.o,	main.c)

PATH_OBJS_BONUS	=	objs_bonus
OBJS_BONUS	=	$(patsubst	%.c,	$(PATH_OBJS_BONUS)/%.o,	$(SRCS_BONUS))

################################COMPILATION####################################

INCLUDE	= -Ilibft/includes -Iinclude -Iminilibx-linux

LINK	= libft/libft.a -L minilibx-linux/ -lmlx -lXext -lX11

CFLAGS	=	-Wall	-Wextra	-Werror

##################################RULES#######################################

all: libft mlx $(NAME)

mlx:
	${MAKE} -sC minilibx-linux

libft:
	${MAKE} -sC libft

$(NAME): 	$(OBJS)	$(MAIN)
	$(CC)	$(CFLAGS) $(OBJS)	$(MAIN)	-o	$(NAME)	$(INCLUDE)	$(LINK)

$(MAIN): srcs/main.c
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

$(OBJS):	$(PATH_OBJS)/%.o:%.c Makefile
	mkdir	-p	$(PATH_OBJS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS)	$(OBJS_BONUS)
	$(CC)	$(CFLAGS)	$(OBJS)	$(OBJS_BONUS) -o	$(NAME_BONUS) $(INCLUDE)	$(LIBFT)

$(OBJS_BONUS):	$(PATH_OBJS_BONUS)/%.o:%.c Makefile
	mkdir	-p	$(PATH_OBJS_BONUS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

clean:
	rm	-rf	$(PATH_OBJS)
	rm	-rf	$(PATH_OBJS_BONUS)
	${MAKE}	clean -sC	libft
	${MAKE}	clean -sC	minilibx-linux

fclean:	clean
	rm	-rf	$(NAME)
	rm	-rf	$(NAME_BONUS)
	${MAKE}	fclean -sC	libft

re:	fclean
	${MAKE}

malloc_test: $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} libft/libft.a -L. -lmallocator

.PHONY:	all	libft	clean	fclean	re
