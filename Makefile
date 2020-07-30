.PHONY: all clean test

all: bin/irrverbs
bin/irrverbs: build/main.o build/irrverbs.o build/irrverbs2.o
	gcc -Wall build/main.o build/irrverbs.o build/irrverbs2.o -o bin/irrverbs
build/irrverbs.o: src/irrverbs.c
	gcc -Wall -c src/irrverbs.c -o build/irrverbs.o
build/irrverbs2.o: src/irrverbs2.c
	gcc -Wall -c src/irrverbs2.c -o build/irrverbs2.o
build/main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o

clean: 
	rm build/main.o build/irrverbs.o build/irrverbs2.o

test: bin/test/test
	./bin/test/test
bin/test/test: build/irrverbs2.o build/test/main.o build/test/test.o
	gcc -Wall build/irrverbs2.o build/test/main.o build/test/test.o -o bin/test/test
build/test/main.o: test/main.c
	gcc -Wall -I thirdparty -I src -c test/main.c -o build/test/main.o
build/test/test.o: test/test.c
	gcc -Wall -I thirdparty -I src -c test/test.c -o build/test/test.o
