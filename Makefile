# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I.  # Include the current directory

SDL2_CFLAGS = $(shell sdl2-config --cflags)
SDL2_LDFLAGS = $(shell sdl2-config --libs)

# Directories
SRCDIR = Code
BUILDDIR = build
BINDIR = build

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Output binary
TARGET = $(BINDIR)/program

# Rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) $(OBJECTS) -o $@ $(SDL2_LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Debug
debug: CXXFLAGS += -g
debug: clean all
