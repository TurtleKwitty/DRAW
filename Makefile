OBJS = ./Includes/Displayable_Image_Entity.cpp ./Includes/Window_Entity.cpp ./main.cpp
CC=g++
COMPILER_FLAGS = 

LINKER_FLAGS = -lSDL2

OBJ_NAME = Out/DRAW

ProgVer = V0.1

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)