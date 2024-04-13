#--- LIBRARY NAME ---#
NAME = ludum_dare_55

#--- COMPILER AND FLAGS ---#
CXX = g++
CFLAGS = -Wall -std=c++11

#--- OS DETECTION ---#
ifeq ($(OS),Windows_NT)
    CFLAGS += -Ic:/path_to_includes
    LDFLAGS = -Lc:/path_to_libs -lopengl32 -lgdi32 -lwinmm
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CFLAGS += -I/usr/include
        LDFLAGS = -L/usr/lib -lGL -lm -lrt -lX11
    endif
    ifeq ($(UNAME_S),Darwin)
        CFLAGS += -I/Users/$(USER)/homebrew/include
        LDFLAGS = -L/Users/$(USER)/homebrew/lib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
    endif
endif

#--- RAYLIB ---#
RAYLIB_SRC = $(wildcard lib/raylib/src/*.c)
RAYLIB_OBJ = $(patsubst %.c,%.o,$(RAYLIB_SRC))

#--- OBJECT ---#
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))

#--- RULES ---#
all: dependencies $(NAME)

dependencies:
	@echo "Checking and installing the necessary dependencies..."

$(NAME): $(RAYLIB_OBJ) $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) $(RAYLIB_OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run: re
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all re