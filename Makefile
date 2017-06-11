CC = g++
CPPFLAGS = -std=c++11 -g
LIBS = -lallegro -lallegro_image -lallegro_image -lallegro_font -lallegro_ttf -lallegro_dialog
EXE = main
SRC_DIR = ./src
SRCS = $(shell find $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:%=%.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(EXE) $(LIBS)

$(SRC_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@ $(LIBS)

PHONY: clean doc check

clean:
	rm $(SRC_DIR)/*.o $(EXE)

doc:
	doxygen Doxyfile

check:
	cppcheck --enable=all $(SRC_DIR)
