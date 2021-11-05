SRCDIR=.
OBJDIR=obj
VPIDIR=build

TESTDIR=test
CC=g++
ISIM=iverilog

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
# HDLS=$(wildcard $(SRCDIR)/*.v)

OBJS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
VPIS=$(patsubst $(SRCDIR)/%.cpp, $(VPIDIR)/%.vpi, $(SOURCES))
VVPS=$(patsubst $(SRCDIR)/%.cpp, $(VPIDIR)/%.vvp, $(SOURCES))

# HDLS=$(patsubst $(SRCDIR)/%.cpp, $(SRCDIR)/%.v, $(SOURCES))

CFLAGS=-I../include
ADCSRC=../obj/vpihandle.o

all: prepare $(OBJS) $(VPIS)
	echo $(VPIS)
	echo $(SOURCES)
#	$(CC) -shared $(CFLAGS) $< -o 

tests: $(OBJS) $(VPIS) $(VVPS)
	echo $(VVPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -fpic $(CFLAGS) $< -o $@


$(VPIDIR)/%.vpi: $(OBJDIR)/%.o
	$(CC) -shared -lvpi $(CFLAGS) $(ADCSRC) $< -o $@

$(VPIDIR)/%.vvp: $(SRCDIR)/%.v
	iverilog -o $@ $< -L$(VPIDIR) -m$(patsubst $(VPIDIR)/%.vvp, %, $@)

prepare:
	mkdir -p $(VPIDIR) $(OBJDIR)

clean:
	rm -rf $(VPIDIR)/* $(OBJDIR)/*