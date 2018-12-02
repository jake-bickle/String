CC := g++
CPPFLAGS := -I src -I tests/third_party -I include -g -Wall 
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := tests
TARGET := $(TEST_DIR)/debug/run_tests

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC)) 

$(TARGET): $(OBJ) $(OBJ_DIR)/tests_main.o $(OBJ_DIR)/string_tests.o
	$(CC) $(CPPFLAGS) $(OBJ) $(OBJ_DIR)/tests_main.o $(OBJ_DIR)/string_tests.o -o $@

$(OBJ_DIR)/%.o: $(SRC)
	$(CC) $(CPPFLAGS) -c -o $@ $< 

$(OBJ_DIR)/tests_main.o: $(TEST_DIR)/tests_main.cpp $(TEST_DIR)/third_party/catch.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $< 

$(OBJ_DIR)/string_tests.o: $(TEST_DIR)/string_tests.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $< 

.phoney: clean

clean:
	rm $(OBJ_DIR)/*.o
	rm $(TARGET)
