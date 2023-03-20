# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 20:27:02 by rnaka             #+#    #+#              #
#    Updated: 2023/03/20 04:48:04 by rnaka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc

INCLUDE		= -I include

CFLAGS = -Wall -Wextra -Werror

M_SRCS		= 	main.c
			
#C_SRCS		=check/check_file_name.c\
			#check/check_map.c\

SRCS		= $(M_SRCS)

OBJDIR		= objs

LIBFTDIR		= libft

OBJS		= $(SRCS:%.c=$(OBJDIR)/%.o)



all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFTDIR)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:
			@$(RM) -r $(OBJDIR)
			@make fclean -C $(LIBFTDIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
