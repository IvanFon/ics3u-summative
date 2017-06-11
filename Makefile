CC = g++
CPPFLAGS = -std=c++11 -g
LIBS = -lallegro -lallegro_image -lallegro_image -lallegro_font -lallegro_ttf
EXE = main
SOURCES = src/main.cpp src/Settings.cpp src/Assets.cpp \
	src/Constants.cpp src/Game.cpp src/Init.cpp src/Input.cpp src/Level.cpp \
	src/Menu.cpp src/Physics.cpp src/Player.cpp src/Quit.cpp src/Sprite.cpp \
	src/States.cpp src/Text.cpp src/Texture.cpp src/Utils.cpp src/LevelSelect.cpp

all:
	$(CC) $(SOURCES) -o $(EXE) $(CPPFLAGS) $(LIBS)

doc:
	doxygen

clean:
	rm -rf $(EXE) *.o doc/

.PHONY: doc clean
