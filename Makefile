CXX := g++
# add compiler flags here
CXXFLAGS += -std=c++17 -pedantic-errors
CXXFLAGS += -Wall -Wextra
CXXFLAGS += -g3 -O0
# add external includes here
CPPFLAGS += -I./include -I./src
# add library flags here
LDFLAGS +=

SRC_DIR = ./src
BUILD_DIR = ./build
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.d,$(SRC_FILES))

all: supersudoku

.PHONY: clean run

clean:
	rm -f $(BUILD_DIR)/*.o

supersudoku: $(OBJ_FILES)
	$(CXX) -o $@.out  main.cpp $^ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)

-include $(DEP_FILES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	$(CXX) -MMD -MP -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

run:
	./supersudoku.out
