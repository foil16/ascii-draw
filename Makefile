CC ?= cc
CFLAGS ?= -O2

asciidraw: asciidraw.c
	$(CC) $(CFLAGS) -o $@ $< -lm

clean:
	rm -f asciidraw

.PHONY: clean
