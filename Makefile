SRCDIR=src
OBJDIR=obj

TESTDIR=test
CC=g++

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

CFLAGS=-I./include -fpic

all: prepare $(OBJS)
	echo $(OBJS)
	echo $(SOURCES)
#	$(CC) -shared $(CFLAGS) $< -o 


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@


prepare:
	mkdir -p obj

clean:
	rm -rf obj/*