NAME = fftransform

CC = g++
CFLAGS = -std=c++11 -Wall -Werror -Wextra

SRCS = $(wildcard source/*.cpp)
INC_DIRS = -Iinclude

JSON_INC = -I/usr/local/include
JSON_LIB = -L/usr/local/lib -ljsoncpp

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(INC_DIRS) $(JSON_INC) -o $(NAME) $(SRCS) $(JSON_LIB)

all: clean $(NAME) test

test:
	./$(NAME) --test

clean:
	rm -f $(NAME)

.PHONY: all test clean
