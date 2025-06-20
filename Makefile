NAME = pipex

LIBFT = libft/libft.a

INC = -I.

CC = clang

FLAGS = -Wall -Wextra -Werror -g

SRCS =	\
		pipex_substr.c \
		error_exit.c \
		exe_cmd.c \
		get_cmd_path.c \
		get_path_line.c \
		path_join.c \
		pipex.c \
		main.c



GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

all: ${LIBFT} ${NAME}

${LIBFT}:
	@make bonus -C libft

${NAME}: ${SRCS}
	${CC} ${FLAGS} ${SRCS} ${LIBFT} -o ${NAME}
	@echo "${GREEN}Program successfully compiled!${NO_COLOR}"

clean:
	@make clean -C libft
	rm -f ${OBJS}

fclean: clean
	@make fclean -C libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re



