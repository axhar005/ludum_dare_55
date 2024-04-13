CXX = g++
CFLAGS = -Wall -std=c++11 -I/Users/$(USER)/homebrew/include
LDFLAGS = -L/Users/$(USER)/homebrew/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo


# Détection du système d'exploitation
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

# Ajouter les fichiers source de Raylib
RAYLIB_SRC = $(wildcard raylib/src/*.c)
RAYLIB_OBJ = $(patsubst %.c,%.o,$(RAYLIB_SRC))

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))

all: dependencies myproject

dependencies:
	@echo "Vérification et installation des dépendances nécessaires..."
	@$(INSTALL_CMD)

myproject: $(RAYLIB_OBJ) $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) $(RAYLIB_OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(RAYLIB_OBJ) $(OBJ) myproject
