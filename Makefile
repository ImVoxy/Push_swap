# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpascal <alpascal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:34:58 by alpascal          #+#    #+#              #
#    Updated: 2021/12/13 01:40:03 by alpascal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN = `tput setaf 2`
RED = `tput setaf 1`
END = `tput sgr0`

NAME 			= push_swap
LIBFT 			= libft/libft.a

INCLUDES 		= -Iincludes -Ilibft

PUSHSWAP_NAME	= push_swap/push_swap.c \
					push_swap/short_sort.c \
					push_swap/short_sort2.c \
					push_swap/insert_sort.c \
					push_swap/quick_sort.c \
					push_swap/quick_sort2.c \
					utils/stack_utils.c \
					utils/string_utils.c \
					utils/string_utils2.c \
					utils/operations.c \
					utils/operations_2.c \
					utils/operations_3.c \

OBJ_PUSHSWAP 	= $(SRC_PUSHSWAP:.c=.o)
SRCS_PATH		= srcs

SRC				= $(addprefix $(SRCS_PATH)/,$(SRC_NAME))
SRC_PUSHSWAP	= $(addprefix $(SRCS_PATH)/,$(PUSHSWAP_NAME))
RM 				= rm -rf
CC 				= clang
MEM				= -g -O3 -fsanitize=address

all:	$(NAME)

$(NAME): $(OBJ)$(OBJ_PUSHSWAP)
	make -C libft/ 1>/dev/null
	@echo "$(GREEN)$(LIBFT) done...$(END)"
	$(CC) -Wall -Wextra -Werror $(OBJ_PUSHSWAP) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) binary is ready !$(END)"

%.o: %.c
	@echo "$(GREEN)Compiling source files to objects $<$ ...$(END)"
	$(CC) -Wall -Wextra -Werror $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_PUSHSWAP)
	make clean -C libft/ 1>/dev/null

fclean:		clean
	$(RM) $(NAME) a.out vgcore.*
	make fclean -C libft/ 1>/dev/null
	@echo "$(RED)$(LIBFT) removed$(END)"
	@echo "$(RED)$(NAME) removed$(END)"

re: clean fclean all
