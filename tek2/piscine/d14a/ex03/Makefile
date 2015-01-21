BINPATH ?= ..
NAME ?= test03
BIN ?= $(BINPATH)/$(NAME)
EX ?= ex03
TESTSRCS ?= *.cpp ../srcs/ex01/[^Base][^Rover]*.cpp ../srcs/ex01/Errors.cpp
EXSRCS ?= ../srcs/$(EX)/*.cpp
INCLUDES ?= -I../srcs/$(EX)/ -I./ -I../srcs/ex01/
CXXFLAGS ?= -W -Wall -Wextra -Werror
LDFLAGS ?= -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	g++ -o $(BIN) $(TESTSRCS) $(EXSRCS) $(INCLUDES) $(LDFLAGS)

fclean:
	rm $(BIN)

re: fclean all

.PHONY: all fclean re
