BINPATH ?= ..
NAME ?= test-1
BIN ?= $(BINPATH)/$(NAME)
EX ?= ex-1
TESTSRCS ?= *.c
EXSRCS ?= ../srcs/$(EX)/*.c
INCLUDES ?= -I../srcs/$(EX)/
CFLAGS ?= -W -Wall -Wextra -Werror
LDFLAGS ?= -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(BIN) $(TESTSRCS) $(EXSRCS) $(INCLUDES) $(LDFLAGS)

fclean:
	rm $(BIN)

re: fclean all

.PHONY: all fclean re
