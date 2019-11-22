# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumourot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 13:38:04 by jumourot          #+#    #+#              #
#    Updated: 2019/11/18 14:24:28 by jumourot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = Clang

NAME = GNL

LIB = $(addprefix $(IPATH), get_next_line.h)

IPATH = /includes

CFLGS += -Wall
CFLGS += -Werror
CFLGS += -Wextra
CFLGS += -I $(IPATH)

SRCS += get_next_line.c
SRCS += get_next_line_utils.c
SRCS += main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLGS) $^ -o $@
$(OBJS): $(

