BINPATH ?= ..
NAME ?= test05
BIN ?= $(BINPATH)/$(NAME)
EX ?= ex05
TESTSRCS ?= *.cpp
EXSRCS ?= 
INCLUDES ?= -I../srcs/$(EX)/
CXXFLAGS ?= -W -Wall -Wextra -Werror -g
LDFLAGS ?= -W -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	g++ -o $(BIN) $(TESTSRCS) $(EXSRCS) $(INCLUDES) $(LDFLAGS)

fclean:
	rm $(BIN)

re: fclean all

.PHONY: all fclean re
