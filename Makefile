# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabre <msabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 15:08:28 by kbessa            #+#    #+#              #
#    Updated: 2020/07/01 15:59:47 by msabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap

NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC = sources

SRC1 	= main_ps.c get_min_and_middle.c check_args.c p_s.c operation.c create_lst_stack.c parse_stack_a.c select_op.c bonus.c insertion_sort.c three_or_five.c stack_output_str.c free_lst.c

SRC2 	= ch.c get_min_and_middle.c operation.c create_lst_stack.c parse_stack_a.c select_op.c free_lst.c bonus.c check_args.c

OBJSFD 	= objects

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I./includes

LIBFT_HDR 	= -I./includes/libft/includes

LIB_BINARY	= -L./includes/libft -lft

LIBFT		= ./includes/libft/libft.a

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	@echo Create directory for objects...
	@mkdir $@

$(OBJSFD)/%.o: $(SRC)/%.c
	@echo Compiling push_swap objects: $<
	@gcc $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./includes/libft

$(NAME1): $(OBJSFD) $(OBJS1) $(LIBFT)
	@echo Create push_swap binary
	@gcc $(OBJS1) $(HDR) -o $(NAME1) $(LIBFT)

$(NAME2): $(OBJSFD) $(OBJS2) $(LIBFT)
	@echo Create checker binary
	@gcc $(OBJS1) $(HDR) -o $(NAME2) $(LIBFT)

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C ./includes/libft fclean

re: fclean all
