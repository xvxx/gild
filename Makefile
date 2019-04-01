default: run

build: gold.lsc
	ldpl gold.lsc

run: build
	./digc-bin localhost 6969