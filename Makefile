# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 20:27:02 by rnaka             #+#    #+#              #
#    Updated: 2023/03/26 20:34:38 by rnaka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC		= gcc

INCLUDE		= -I include

CFLAGS = -Wall -Wextra -Werror

DEBUG = -g -fsanitize=address  -fsanitize=undefined

M_SRCS		= main.c

C_SRCS		= check/check_file_name.c\
			check/check_map.c\
			check/const_map.c\
			check/check_char.c\
			check/check_wall.c\
			check/check_cep.c\
			check/find_cep.c

E_SRCS		= error/error.c\
			error/error_free.c\
			error/free_dp.c

SRCS		= $(M_SRCS) $(C_SRCS) $(E_SRCS)

OBJDIR		= objs

LIBFTDIR	= libft

OBJS		= $(SRCS:%.c=$(OBJDIR)/%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFTDIR)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

ifeq ($(shell uname), Linux)
DEBUG += -fsanitize=leak
endif

clean:
			@$(RM) -r $(OBJDIR)
			@make fclean -C $(LIBFTDIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

debug:	CFLAGS += $(DEBUG)
debug:	re

.PHONY:		all clean fclean re
