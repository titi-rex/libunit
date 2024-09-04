# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 21:12:50 by tlegrand          #+#    #+#              #
#    Updated: 2024/09/04 23:09:49 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##
# tests
#
# @file
# @version 0.2


#	==============================	NAME	==============================	#
NAME	=	tests

#	==============================	CMP	==============================	#
CC			=	gcc 
CFLAG		=	-Wall -Wextra -Werror 
DFLAG		=	-MMD -MP


#	==============================	INCLUDE	==============================	#
DIR_INC		=	inc/
IFLAG		=	-I ${DIR_INC} -I ../framework/inc


#	==============================	SRC	==============================	#
# STRLEN
SRC_DIR		=	strlen/
SRC_LST		=	00_launcher.c \
				01_ok_short.c \
				02_ok_long.c \
				03_ko_bad_result.c \
				04_ko_segv.c \
				05_ko_buse.c \
				06_ko_timeout.c 

SRC			=	${addprefix ${SRC_DIR}, ${SRC_LST}}
SRC_MAIN	=	main.c

#	==============================	OBJ	==============================	#
OBJ_DIR		=	.obj/
OBJ_LST		=	${SRC_LST:.c=.o} ${SRC_MAIN:.c=.o}
OBJ			=	${addprefix ${OBJ_DIR}, ${OBJ_LST}}

#	==============================	OBJ	==============================	#
LIBUNIT		=	../framework/libunit.a

#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY: all clean fclean
#	==============================	BASE	==============================	#
all: ${OBJ_DIR} ${NAME}

clean:
	@rm -rf ${OBJ_DIR}
	@echo "Clean"

fclean: clean
	@rm -f ${NAME}
	@echo "FClean"

re: fclean all

test:	${NAME}
	@./${NAME}


#	==============================	COMPILATION	==============================	#
${NAME}: ${LIBUNIT} ${OBJ_DIR} ${OBJ}
	${CC} ${IFLAG} ${CFLAG} ${OBJ} ${LIBUNIT} -o $@


${OBJ_DIR}%.o: ${SRC_DIR}%.c
	${CC} ${IFLAG} ${CFLAG} ${DFLAG} -c $< -o $@

${OBJ_DIR}%.o: %.c
	${CC} ${IFLAG} ${CFLAG} ${DFLAG} -c $< -o $@

${LIBUNIT}:
	make -C ../framework

-include ${OBJ_DIR}/*.dep


#	==============================	UTILS	==============================	#
${OBJ_DIR}:
	@mkdir ${OBJ_DIR}


# end
