NAME			=	ft_containers

SRCS_FT			=	ft_main.cpp

SRCS_STD 		=	std_main.cpp

INCL			=	Containers/Stack.hpp

OBJS_FT			=	$(SRCS_FT:.cpp=.o)

OBJS_STD		=	$(SRCS_STD:.cpp=.o)

CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98

CC				=	c++

all:			$(NAME) std_con

$(OBJS_FT):		$(SRCS_FT) $(INCL)
				@$(CC) $(CPPFLAGS) -I $(INCL) -c $< -o $@

$(OBJS_STD):	$(SRCS_STD) $(INCL)
				@$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):		$(OBJS_FT)
				@$(CC) $(OBJS_FT) $(CPPFLAGS) -o $(NAME)
				@${RM} ${OBJS_FT}
				@echo "Make done"


std_con:		$(OBJS_STD)
				@$(CC) $(CPPFLAGS) $(OBJS_STD) -o $@
				@${RM} ${OBJS_STD}
				@echo "Make std_con done"

clean:
				@${RM} ${OBJS_FT}
				@${RM} ${SRCS_STD}
				@echo "Make clean done"

fclean:
				@${RM} ${OBJS_FT}
				@${RM} ${OBJS_STD}
				@${RM} ${NAME}
				@${RM} std_con
				@echo "Make fclean done"

re:				fclean all
				@echo "Make re done"

.PHONY:			all clean fclean re
