all: bin/graph 

bin/graph: build/src/main.o build/src/print_graph.o build/src/algoritm.o build/src/interface.o
	gcc -Wall -Werror build/src/main.o build/src/print_graph.o build/src/algoritm.o build/src/interface.o -o bin/graph

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/print_graph.o: src/print_graph.c
	gcc -Wall -Werror -c src/print_graph.c -o build/src/print_graph.o

build/src/algoritm.o: src/algoritm.c
	gcc -Wall -Werror -c src/algoritm.c -o build/src/algoritm.o

build/src/interface.o: src/interface.c
	gcc -Wall -Werror -c src/interface.c -o build/src/interface.o


.PHONY: test

test: bin/graph-test

bin/graph-test: build/test/main.o build/test/test.o build/src/algoritm.o build/src/print_graph.o
	gcc -Wall -Werror build/test/main.o build/test/test.o build/src/algoritm.o build/src/print_graph.o -o bin/graph-test

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/test.o: test/test.c
	gcc -I thirdparty -Wall -Werror -c test/test.c -o build/test/test.o



.PHONY: clean

clean:
	rm -rf build/src/*.o | rm -rf build/test/*.o