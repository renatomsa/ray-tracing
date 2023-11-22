# Define the link target
linkTarget  := RayTracer

# Define the libraries 
LIBS := -lSDL2

# Define any flags
CFLAGS := -std=c++17

# Define the object files
objects := main.o \
           CApp.o \
           $(patsubst %.cpp,%.o,$(wildcard ./rayTracer/*.cpp))

# Define the rebuildables
rebuildables := $(objects) $(linkTarget)

# Rule to perform the build
$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)

# Rule to create the .o files
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(rebuildables)
