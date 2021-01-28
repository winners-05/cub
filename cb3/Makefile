SRC = main.c \
	  map_funct.c \

INCL = -INCLUDE
OBJS = ${SRC: .c = .o}
NAME =  CUB3D
FLAGS = -Wall -Werror -Wextra



all = $(NAME)
$(NAME) : $(OBJS)	
	@gcc ${FLAGS} -I/usr/local/include ${OBJS} -o$(NAME) -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT
	.c .o : ${SRC}
	@gcc ${FLAGS} -c ${INCL} $< -o ${<: .c=.o}
clean : @rm ${OBJS}
fclean : @rm ${NAME}
re : fclean
	make all