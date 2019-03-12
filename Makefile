default: run

build: digc.ldpl
	ldpl digc.ldpl

run: build
	./digc-bin