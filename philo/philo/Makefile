SRCS =	philo.c philo_utils.c life.c init.c free_and_time.c

SRCS_DIR = ./srcs/

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

NAME = philo

HEADER = ./srcs/head_philo.h

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re norm

all:		${NAME}

%.o:%.c		${HEADER}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
			@echo "${GREEN}${NAME} compile!${SHALLOW}"

norm:
			@echo "${GREEN}|-----Chek NORMs!-----|${NEW}"
			@norminette ./srcs/
			@echo "${GREEN}|-----Chek ended!-----|${SHALLOW}"

clean:		
			@${RM} ${OBJS}
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${NAME}
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all