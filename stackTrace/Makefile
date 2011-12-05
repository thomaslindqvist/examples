EXECUTABLE = app
CC = g++
CFLAGS = -Wall -O0
INCLUDES := -I.
COMPILE = $(CC) $(INCLUDES) $(CFLAGS) -c -g
OBJFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
LDFLAGS = -rdynamic


all: $(OBJFILES)
	$(CC) -o $(EXECUTABLE) $(OBJFILES) $(LDFLAGS)


$(EXECUTABLE): $(OBJFILES)
	$(CC) -o $(EXECUTABLE) $(OBJFILES) $(LDFLAGS)


%.o: %.cpp
	$(COMPILE) -o $@ $<


clean:
	rm -rf *o $(EXECUTABLE)

