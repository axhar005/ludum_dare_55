#--- LIBRARY NAME ---#
NAME = ludum_dare_55

#--- COMPILER AND FLAGS ---#
CXX = g++
CFLAGS = -Wall -std=c++11
RAYLIB_SRC = 
RAYLIB_OBJ = 

#--- OS DETECTION ---#
ifeq ($(OS),Windows_NT)
    CFLAGS += -Iinclude -Ic:/raylib/include
    LDFLAGS = -Lc:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CFLAGS += -Iinclude -I/usr/local/include
        LDFLAGS = -L/usr/local/lib -lraylib -lGL -lm -lrt -lX11
    endif
    ifeq ($(UNAME_S),Darwin)
        CFLAGS += -I/Users/$(USER)/homebrew/include
        LDFLAGS = -L/Users/$(USER)/homebrew/lib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
        RAYLIB_SRC = $(wildcard lib/raylib/src/*.c)
        RAYLIB_OBJ = $(patsubst %.c,%.o,$(RAYLIB_SRC))
    endif
endif

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

.PHONY: all clean fclean re run