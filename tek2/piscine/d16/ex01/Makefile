BINPATH ?= ..
NAME ?= test01
BIN ?= $(BINPATH)/$(NAME)
EX ?= ex01
TESTSRCS ?= *.cpp
EXSRCS ?= ../srcs/$(EX)/*.cpp
INCLUDES ?= -I../srcs/$(EX)/ -I./
CXXFLAGS ?= -W -Wall -Wextra -Werror -g
LDFLAGS ?= -W -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	g++ -o $(BIN) $(TESTSRCS) $(EXSRCS) $(INCLUDES) $(LDFLAGS)

fclean:
	rm $(BIN)

re: fclean all

.PHONY: all fclean re
