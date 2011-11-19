EXECUTABLE = app
CC = g++ -pthread
CFLAGS = -Wall -O0 -std=c++0x
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

