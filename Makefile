APP_NAME = application
LIB_NAME = libapplication

BIN_DIR = bin
OBJ_DIR = obj
CODE_DIR = code
TEST_NAME = test

EXE = $(BIN_DIR)/tetris.exe
EXE1 = $(BIN_DIR)/test.exe
OBJ_FILE = $(OBJ_DIR)/$(APP_NAME)/main.o
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

all: compile

test: compile_test

CXX = g++
CXXFLAGS = -Isrc/include -I code/libapplication
LDFLAGS = -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lgdi32 -mwindows
LDFLAGS2 = -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lgdi32

$(shell mkdir -p obj)

compile:
	$(CXX) $(CXXFLAGS) -c $(CODE_DIR)/$(APP_NAME)/main.cpp -o $(OBJ_DIR)/$(APP_NAME)/main.o
	$(CXX) $(CXXFLAGS) -c $(CODE_DIR)/$(LIB_NAME)/functions.cpp -o $(OBJ_DIR)/$(LIB_NAME)/functions.o
	$(CXX) $(OBJ_DIR)/$(APP_NAME)/main.o $(OBJ_DIR)/$(LIB_NAME)/functions.o -o $(EXE) $(LDFLAGS)

compile_test:
	$(CXX) $(CXXFLAGS) -c $(TEST_NAME)/ctest.cpp -o $(OBJ_DIR)/$(TEST_NAME)/ctest.o
	$(CXX) $(CXXFLAGS) -c $(TEST_NAME)/main.cpp -o $(OBJ_DIR)/$(TEST_NAME)/main.o
	$(CXX) $(OBJ_DIR)/$(TEST_NAME)/ctest.o $(OBJ_DIR)/$(TEST_NAME)/main.o $(OBJ_DIR)/$(LIB_NAME)/functions.o  -o $(EXE1) $(LDFLAGS2)

.PHONY: clean
clean:
	rm -f main.o $(EXE) $(EXE1)
