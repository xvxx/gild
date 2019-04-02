default: run

build: gild.lsc
	ldpl -o=gild gild.lsc

run: build
	./gild localhost 6969
