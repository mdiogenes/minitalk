SRC			= 	main_client.c ft_error.c

SRS			=	main_server.c ft_error.c

BONUSSRC	= 	bonus_main_client.c ft_error.c

BONUSSRS	= 	bonus_main_server.c ft_error.c

LIB			=	ft

LIB_DIR		=	libft/

NAME		=	client

NAME2		=	server

BONUSNAME	=	bonusclient

BONUSNAME2	=	bonusserver

OBJS		=	${SRC:.c=.o}

OBJS2		=	${SRS:.c=.o}

BONUSOBJS	=	${BONUSSRC:.c=.o}

BONUSOBJS2	=	${BONUSSRs:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:		$(NAME) $(NAME2)

bonus:		$(BONUSNAME) $(BONUSNAME2)

$(NAME):	
			$(MAKE) -C $(LIB_DIR)
			$(CC) $(CFLAGS) $(SRC) -o $(NAME) -L $(LIB_DIR) -l$(LIB) -I$(LIB_DIR)libft.h

$(NAME2):
			$(CC) $(CFLAGS) $(SRS) -o $(NAME2) -L $(LIB_DIR) -l$(LIB) -I$(LIB_DIR)libft.h

$(BONUSNAME):
			$(CC) $(CFLAGS) $(BONUSSRC) -o $(BONUSNAME) -L $(LIB_DIR) -l$(LIB) -I$(LIB_DIR)libft.h

$(BONUSNAME2):
			$(CC) $(CFLAGS) $(BONUSSRS) -o $(BONUSNAME2) -L $(LIB_DIR) -l$(LIB) -I$(LIB_DIR)libft.h
clean:
			$(RM) $(OBJS)
			$(RM) $(OBJS2)
			$(RM) $(BONUSOBJS)
			$(RM) $(BONUSPBJS2)
			$(MAKE) clean -C./libft

fclean:		clean
			$(MAKE) fclean -C./libft
			$(RM) $(NAME)
			$(RM) $(NAME2)
			$(RM) $(BONUSNAME)
			$(RM) $(BONUSNAME2)

re:			fclean all
