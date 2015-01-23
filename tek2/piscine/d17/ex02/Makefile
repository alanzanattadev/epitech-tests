BINPATH ?= ..
NAME1 ?= test02-1
NAME2 ?= test02-2
BIN1 ?= $(BINPATH)/$(NAME1)
BIN2 ?= $(BINPATH)/$(NAME2)
EX ?= ex02
EXSRCS1 = $(BINPATH)/srcs/$(EX)/Cesar.cpp
EXSRCS2 = $(BINPATH)/srcs/$(EX)/*.cpp
TESTSRCS1 ?= main1.cpp
TESTSRCS2 ?= main2.cpp
INCLUDES ?= -I../srcs/$(EX)/ -I./
CXXFLAGS ?= -W -Wall -Wextra -Werror
LDFLAGS ?= -W -Wall -Wextra -Werror

all:
	make -C . bin1
	make -C . bin2

bin1: $(NAME1)
	echo "bin1"

bin2: $(NAME2)
	echo "bin2"

$(NAME1):
	echo "name1"
	g++ -o $(BIN1) $(TESTSRCS1) $(EXSRCS1) $(INCLUDES) $(LDFLAGS)

$(NAME2):
	echo "name2"
	g++ -o $(BIN2) $(TESTSRCS2) $(EXSRCS2) $(INCLUDES) $(LDFLAGS)

fclean:
	rm $(BIN1)
	rm $(BIN2)

re: fclean all

.PHONY: all fclean re
