.SUFFIXES:	# Delete the default suffixes
.SUFFIXES:	.cc .hh
.PHONY:		all clean astyle enscript

CC = g++
CFLAGS = -Wall
LDFLAGS =

TARGET		= main
CC_FILES	= $(wildcard *.cc)
HH_FILES	= $(wildcard *.hh)
O_FILES		= $(CC_FILES:%.cc=%.o)

default: all

all: $(TARGET)

$(O_FILES): %.o: %.cc Makefile
	$(CC) $(CFLAGS) $*.cc -c

$(TARGET): %: $(O_FILES) Makefile
	$(CC) $(CFLAGS) $(LDFLAGS) $(O_FILES) -o $*

## Learn this rather tricky use of g++ -MM and Gnu make include directive
## at URL http://stackoverflow.com/a/13545596/7266382
## Do not use the obsolete makedepend utility!

DEPENDENCY_FILE	= Makefile.dep

include $(DEPENDENCY_FILE)

$(DEPENDENCY_FILE): $(CC_FILES) $(HH_FILES) Makefile
	g++ -MM $(CC_FILES) $(HH_FILES) > $@

#####################################################


ASTYLE_OPTIONS = 	--style=attach --indent=spaces=2

astyle:
	astyle $(ASTYLE_OPTIONS) $(CC_FILES) $(HH_FILES)

ENSCRIPT_OPTIONS	= \
	--language=PostScript --missing-characters \
	--borders --nup=2 --word-wrap --mark-wrapped=arrow

OUTPUT	= output

enscript:
	enscript $(ENSCRIPT_OPTIONS) $(CC_FILES) $(HH_FILES) -o $(OUTPUT).ps
	ps2pdf $(OUTPUT).ps $(OUTPUT).pdf

clean:
	-rm -f $(O_FILES) $(TARGET) *.orig Makefile.dep $(OUTPUT).* *.bak
	-rm -rf *.dSYM
