NAME	= BSQ
SRCS	= *.c
OBJS	= ${SRCS:.c=.o}
HEADER	= *.h
HFLAGS	= -I
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
all:    
	${CC} ${CFLAGS} ${SRCS} ${HFLAGS} ${HEADER} -o ${NAME}
clean:
	/bin/rm -f ${OBJS}
fclean:		clean
	/bin/rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re

