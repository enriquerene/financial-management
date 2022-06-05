CC=g++
TEST_CFLAGS=-std=c++11 -Wall
TEST_CFLAGS=-std=c++20

DIR_TEST=tests
DIR_APP=src
DIR_BIN=bin

TEST_BIN=$(DIR_BIN)/test
TEST_SRC=$(DIR_TEST)/main.cpp

APP_BIN=$(DIR_BIN)/app
APP_SRC=$(DIR_APP)/main.cpp


all: $(DIR_BIN) test $(APP_BIN)
	
$(DIR_BIN):
	mkdir -p $(DIR_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CC) $(TEST_CFLAGS) -o $@ $^

$(APP_BIN): $(APP_SRC)
	$(CC) $(APP_CFLAGS) -o $@ $^

test: $(TEST_BIN)
	$(TEST_BIN) --success

clean: 
	@echo "Removing executable files"
	rm -f $(DIR_BIN)/*
