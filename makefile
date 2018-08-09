IDIR =include
ODIR=obj
SDIR=src
BDIR=bin
INST_DIR=/usr/local/bin

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

.PHONY: clean install uninstall

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

install: hl
	@cp $(BDIR)/hl $(INST_DIR)

uninstall:
	rm -f $(INST_DIR)/hl
