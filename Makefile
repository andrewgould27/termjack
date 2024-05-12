# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Executable
EXECUTABLE = $(BINDIR)/blackjack

# Default target
all: $(EXECUTABLE)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean generated files
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*

# Create directories
directories:
	mkdir -p $(OBJDIR) $(BINDIR)

# Phony targets
.PHONY: all clean directories