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

## Release process

# Your build servers need:
#   ~/gild git repo 
#   ldpl in $PATH

# This also assumes your local machine is a mac.

LINUX_x64_SERVER="ubuntu"
LINUX_ARM_SERVER="ubuntu-arm"

release: 
	rm -f dist/*

	ssh $(LINUX_x64_SERVER) 'cd gild && rm -f gild && git pull origin master && make rebuild && strip gild'
	scp $(LINUX_x64_SERVER):~/gild/gild  dist/linux-x86-64 
	
	ssh $(LINUX_ARM_SERVER) 'cd gild && rm -f gild && git pull origin master && make rebuild && strip gild'
	scp $(LINUX_ARM_SERVER):~/gild/gild  dist/linux-arm

	make rebuild
	strip gild 
	mv gild dist/macos

	cd dist && mv linux-x86-64 gild 
	cd dist && tar -czvf gild-linux-x86-64.tar.gz gild 
	rm dist/gild 

	cd dist && mv linux-arm gild 
	cd dist && tar -czvf gild-linux-arm.tar.gz gild 
	rm dist/gild 

	cd dist && mv macos gild 
	cd dist && zip -r gild-macos.zip gild
	rm dist/gild 
	