CXX := g++

# add compiler flags here
CXXFLAGS += -std=c++17 -pedantic-errors
CXXFLAGS += -Wall -Wextra
CXXFLAGS += -g3 -O0

# add external includes here
CPPFLAGS += -I./include -I./src

# add library flags here
LDFLAGS +=

SRCDIR = ./src
BUILDDIR = ./build
OUTDIR = $(BUILDDIR)/bin
MKDIR_P = mkdir -p

.PHONY: clean run

all: main.o
	$(CXX) -o supersudoku.out src/Game.cpp src/utils.cpp main.cpp $(CXXFLAGS) $(CPPFLAGS)

run:
	./supersudoku.out

clean:
	rm -f *.o
