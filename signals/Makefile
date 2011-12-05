EXECUTABLE = app
CC = g++
CFLAGS = -Wall -O0
COMPILE = $(CC) $(CFLAGS) -c -g
OBJFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(OBJFILES)
	$(CC) -o $(EXECUTABLE) $(OBJFILES)


$(EXECUTABLE): $(OBJFILES)
	$(CC) -o $(EXECUTABLE) $(OBJFILES)


%.o: %.cpp
	$(COMPILE) -o $@ $<


clean:
	rm -rf *o $(EXECUTABLE)

