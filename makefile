all:  run

run: test
	./test

test: example.o libdxf_2D.so
	g++ -L. -Wall -o test example.o -ldxf_2D  && export $ LD_LIBRARY_PATH=/home/username/Library:$ LD_LIBRARY_PATH

example.o: example.cpp
	g++ -c example.cpp

libdxf_2D.so: line.o circle.o base.o
	g++ -shared -o libdxf_2D.so line.o circle.o

base.o: base.cpp
	g++ -c -Wall -Werror -fpic base.cpp

line.o: line.cpp
	g++ -c -Wall -Werror -fpic line.cpp

circle.o: circle.cpp
	g++ -c -Wall -Werror -fpic circle.cpp

clean:
	rm -rf *o hello
