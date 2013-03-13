SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

CC := gcc
FLAGS := -Wall -std=c99 -pedantic-errors -g
CFLAGS := $(FLAGS) -save-temps 
HFLAGS := $(FLAGS)

EXECUTABLE := main
DEPEND := .depend
SUBMIT := submit

$(EXECUTABLE): $(OBJECTS)


$(DEPEND):
	$(CC) $(CFLAGS) -MM *.c > $@

-include $(DEPEND)

clean:
	-rm *.h.gch *.s *.i *.o
	-rm  $(SUBMIT).tar $(SUBMIT).tar.gz $(DEPEND) $(EXECUTABLE) 

headers:
	$(CC) $(HFLAGS) *.h
	-rm *.h.gch

cppcheck:
	-cppcheck *.c *.h

$(SUBMIT).tar:
	tar cvf $@ --exclude *.*~ *

$(SUBMIT).tar.gz: submit.tar
	gzip $<

.PHONY: clean headers
