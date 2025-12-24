# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 19:23:27 by agoldber          #+#    #+#              #
#    Updated: 2024/10/14 14:36:27 by agoldber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#BASE

NAME			=	push_swap
INCLUDES		=	includes
ALGO_DIR 		=	algo/
MISC_DIR 		=	misc/
MOVES_DIR 		=	moves/
SRCS_DIR 		=	src/
OBJS_DIR		=	obj/
CC				=	cc
C_FLAGS			=	-Wall -Werror -Wextra -I${INCLUDES}
LIBFT			=	libft.a
RM				=	rm -rf

#COLORS

BGREEN			=	\033[1;32m
BBLUE			=	\033[1;34m
BCYAN			=	\033[1;36m
BPURPLE			=	\033[1;35m
BWHITE			=	\033[1;37m
BYELLOW			=	\033[1;33m
BRED			=	\033[1;31m
PASTEL_PINK		=	\033[38;5;210m
PASTEL_PURPLE	=	\033[38;5;183m
PASTEL_BLUE		=	\033[38;5;111m
COLOR_END		=	\033[0m

#LOGO

define gradient_logo
		@echo "${PASTEL_PINK} ______   __  __     ______     __  __     ______     __     __     ______     ______  "
		@echo "${PASTEL_PURPLE}/\  == \ /\ \/\ \   /\  ___\   /\ \_\ \   /\  ___\   /\ \  _ \ \   /\  __ \   /\  == \ "
		@echo "${PASTEL_BLUE}\ \  _-/ \ \ \_\ \  \ \___  \  \ \  __ \  \ \___  \  \ \ \/ \".\ \  \ \  __ \  \ \  _-/ "
		@echo "${PASTEL_PURPLE} \ \_\    \ \_____\  \/\_____\  \ \_\ \_\  \/\_____\  \ \__/\".~\_\  \ \_\ \_\  \ \_\   "
		@echo "${PASTEL_PINK}  \/_/     \/_____/   \/_____/   \/_/\/_/   \/_____/   \/_/   \/_/   \/_/\/_/   \/_/   ${COLOR_END}"
		@echo ""
endef

#SOURCES

ALGO_FILES		=	bubble_sort rotate_sort sort_in_stack sort tiny_list
MISC_FILES		=	check_av stack_init utils utils2
MOVES_FILES		=	push r_rotate rotate swap

ALGO			=	${addprefix ${ALGO_DIR}, ${ALGO_FILES}}
MISC			=	${addprefix ${MISC_DIR}, ${MISC_FILES}}
MOVES			=	${addprefix ${MOVES_DIR}, ${MOVES_FILES}}

FILES			=	main ${ALGO} ${MISC} ${MOVES}

SRCS			=	${addprefix ${SRCS_DIR}, ${addsuffix .c, ${FILES}}}
OBJS			=	${addprefix ${OBJS_DIR}, ${addsuffix .o, ${FILES}}}

#PROGRESS BAR

TOTAL_FILES		=	$(words $(FILES))

# ---------------------------------------------------------------------------- #

OBJSF			=	.cache_exists

all: check

check: display_logo ${NAME}
	@echo "${BGREEN}\nEverything up to date${COLOR_END}";

display_logo:
			$(gradient_logo)

${NAME}:	${LIBFT} ${OBJS}
			@${CC} -o ${NAME} ${OBJS} ${LIBFT}
			@echo "\n${BGREEN}Push_swap compiled!${COLOR_END}"

${LIBFT}:
			@make -C libft/
			@mv libft/libft.a .
			@make clean -C libft/
			
${OBJS_DIR}%.o : ${SRCS_DIR}%.c | ${OBJSF}
			@mkdir -p $(dir $@)
			@${CC} ${C_FLAGS} -c $< -o $@
			@PROGRESS=$$(echo "$$(find ${OBJS_DIR} -type f | wc -l | tr -d ' ') * 100 / ${TOTAL_FILES}" | bc); \
			BAR=$$(for i in `eval echo {1..$$((PROGRESS / 2))}`; do printf "▇"; done); \
			SPACES=$$(for i in `eval echo {1..50}`; do if [ $$i -gt $$((PROGRESS / 2)) ]; then printf " "; fi; done); \
			CURRENT_FILES=$$(find ${OBJS_DIR} -type f | wc -l | tr -d ' '); \
			printf "\r${BBLUE}Compiling: [$$BAR$$SPACES] $$PROGRESS%% ($$CURRENT_FILES/${TOTAL_FILES}) files${COLOR_END}"

${OBJSF}:
			@mkdir -p ${OBJS_DIR}

clean:
			@${RM} ${OBJS_DIR}
			@${RM} ${OBJSF}
			@echo "${BCYAN}.o files cleaned!${COLOR_END}"

fclean:	clean
			@${RM} ${NAME}
			@${RM} ${LIBFT}
			@echo "${BBLUE}.a files cleaned!${COLOR_END}"

re:		fclean all

.PHONY:	all clean fclean re check display_logo