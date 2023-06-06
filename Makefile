NAME = fftransform

CC = g++
CFLAGS = -std=c++11 -Wall -Werror -Wextra

SRCS = $(wildcard source/*.cpp)
INC_DIRS = -Iinclude

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(INC_DIRS) -o $(NAME) $(SRCS)

all: clean $(NAME) test

test:
	./$(NAME) --test

clean:
	rm -f $(NAME)

.PHONY: all, test, clean
