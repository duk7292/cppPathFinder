# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# SDL2 flags
SDL2_CFLAGS = $(shell sdl2-config --cflags)
SDL2_LDFLAGS = $(shell sdl2-config --libs)

# Source and output
SRC = main.cpp
OUT = bin/PathFinder

# Build rules
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -o $(OUT) $(SRC) $(SDL2_LDFLAGS)

clean:
	rm -f $(OUT)
