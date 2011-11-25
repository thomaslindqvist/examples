EXECUTABLE = app
CC = g++
CFLAGS = -Wall -O0
COMPILE = $(CC) $(CFLAGS) -c -g
OBJFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
LDFLAGS = -lglog

all: $(OBJFILES)
	$(CC) -o $(EXECUTABLE) $(OBJFILES) $(LDFLAGS)


$(EXECUTABLE): $(OBJFILES)
	$(CC) -o $(EXECUTABLE) $(OBJFILES) $(LDFLAGS)


%.o: %.cpp
	$(COMPILE) -o $@ $<


clean:
	rm -rf *o $(EXECUTABLE)

