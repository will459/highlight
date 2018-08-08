IDIR =include
ODIR=obj
SDIR=src
BDIR=bin

CC=gcc
CFLAGS=-I$(IDIR)

_DEPS = highlight.h utilities.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = highlight.o utilities.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hl: $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
