CXX       := g++
CXX_FLAGS := -std=c++17 -Wall -fsanitize=address

BIN     := bin
SRC     := src
INCLUDE := include
LIB     := lib
TESTS   := tests
LIBRARIES   := -lstdc++ -lm
EXECUTABLE  := main
RUN_TEST    := test

build: $(BIN)/$(EXECUTABLE)

run: clean build
	@echo "Executing..."
	$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(TESTS)/main.cpp | $(BIN)
	@echo "Building..."
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) -L $(LIB) $^ -o $@ $(LIBRARIES)

$(BIN)/$(RUN_TEST): $(wildcard $(TESTS)/*.cpp) $(wildcard $(TESTS)/*.hpp) |$(BIN)
	@echo "Building tests..."
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) -L $(LIB) $^ -o $@ $(LIBRARIES)

$(BIN):
	mkdir $@

clean:
	@echo "Clearing..."
	-rm -r $(BIN)

_test: $(BIN)/$(RUN_TEST)

test: clean _test
	@echo "Run tests..."
	$(BIN)/$(RUN_TEST)