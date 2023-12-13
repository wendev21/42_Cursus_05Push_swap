# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:46:47 by wecorzo-          #+#    #+#              #
#    Updated: 2023/12/11 18:14:22 by wecorzo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME				=	push_swap
						
PUSHSWAP_SRC		=\
					 src/algorithm.c \
					 src/handle_errors.c \
					 src/nodes_initiation.c \
					 src/push.c \
					 src/push_swap.c \
					 src/reverse_rotate.c \
					 src/rotate.c \
					 src/sort_three.c \
					 src/split_mut.c \
					 src/stack_initiation.c \
					 src/stack_utils.c \
					 src/swap.c 
OBJS			= $(PUSHSWAP_SRC:.c=.o)

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# Rules
all:		$(NAME)
			@printf "$(BLUE)==> $(CYAN)Push_swap compiled ✅\n\n$(RESET)"

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
			@$(RM) $(NAME) $(OBJS)
			@printf "\n$(BLUE)==> $(RED)Removed Push_swap 🗑️\n$(RESET)"

fclean:		clean
			@make -C libft fclean

re:			fclean all
			@printf "$(BLUE)==> $(CYAN)Push_swap recompiled 🔄\n$(RESET)"

.PHONY:		all clean fclean bonus re
