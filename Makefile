default: run
.PHONY: run build rebuild clean

gild: gild.ldpl gild.cpp
	ldpl -i=gild.cpp -o=gild gild.ldpl

build: gild

rebuild: clean
	make build

run: build
	./gild localhost 6969

clean:
	rm -f gild gild-bin gild.{a,o}
