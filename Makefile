QDOC=qdoc

all: doc

doc: algo/* algo.h algo.qdoc config.qdocconf
	$(QDOC) config.qdocconf

clean:
	rm -r doc

