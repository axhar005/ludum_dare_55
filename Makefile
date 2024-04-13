#--- LIBRARY NAME ---#
NAME = ludum_dare_55

#--- COMMAND VARIABLES ---#
CXX = g++
CFLAGS = -Wall -std=c++11 -I/Users/$(USER)/homebrew/include
LDFLAGS = -L/Users/$(USER)/homebrew/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

#--- OS DETECTION ---#
ifeq ($(OS),Windows_NT)
    LDFLAGS += -lopengl32 -lgdi32 -lwinmm
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        LDFLAGS += -lGL -lm -lrt -lX11
        INSTALL_CMD = dpkg -l | grep -qw libglfw3 || sudo apt-get install libglfw3 libglfw3-dev
    endif
    ifeq ($(UNAME_S),Darwin)
        LDFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
        INSTALL_CMD = brew list glfw > /dev/null 2>&1 || brew install glfw
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
	@$(INSTALL_CMD)

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