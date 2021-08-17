SRCS =	philo_bonus.c philo_utils_bonus.c life_bonus.c init_bonus.c free_and_time_bonus.c

SRCS_DIR = ./srcs/

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

NAME = philo_bonus

HEADER = ./srcs/head_philo_bonus.h

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
			@${CC} ${CFLAGC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC} ${CFLAGC} -o ${NAME} ${OBJS}
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