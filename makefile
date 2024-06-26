# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++17

# Define the SFML include and library paths
SFML_INCLUDE = -I/opt/homebrew/Cellar/sfml/2.6.1/include
SFML_LIB = -L/opt/homebrew/Cellar/sfml/2.6.1/lib
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Define the target executable and source files
TARGET = main
SRCS = main.cpp Game.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: compile

# Rule to compile the source files into object files and link them to create the target executable
compile: $(OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $(SFML_LIB) $(OBJS) $(SFML_LIBS) -o $(TARGET)

# Rule to compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Rule to run the target executable
run: compile
	./$(TARGET)

# Rule to clean the build
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all compile run clean
