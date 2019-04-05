default: run

gild.a: gild.o
	ar -cvq gild.a gild.o

gild.o: gild.cpp gild.h
	c++ -c gild.cpp -std=gnu++11 -o gild.o

gild: gild.a gild.lsc
	ldpl -i=gild.h -o=gild gild.lsc

build: gild

run: build
	./gild localhost 6969

clean:
	rm -f gild gild-bin gild.{a,o}