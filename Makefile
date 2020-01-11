LDPL_SOCKET_REPO=https://github.com/xvxx/ldpl-socket
LDPL_SOCKET_VERSION=v0.1.0
LDPL_VERSION=4.4

default: build
.PHONY: run build rebuild clean

gild: gild.ldpl ldpl_socket
	ldpl -o=gild gild.ldpl

build: gild

rebuild: clean
	make build

run: build
	./gild localhost 6969

clean:
	rm -f gild gild-bin gild.{a,o}
	rm -rf ldpl_socket ldpl-socket

ldpl_socket:
	git clone $(LDPL_SOCKET_REPO)
	cd ldpl-socket && git checkout $(LDPL_SOCKET_VERSION) 2> /dev/null
	mv ldpl-socket/ldpl_socket .
	rm -rf ldpl-socket

## Release process

# Your build servers need:
#   ~/gild git repo
#   ldpl in $PATH

# This also assumes your local machine is a mac.

LINUX_x64_SERVER="ubuntu"
LINUX_ARM_SERVER="ubuntu-arm"

release:
	rm -rf dist
	mkdir dist

	ssh $(LINUX_x64_SERVER) 'cd ldpl && git fetch origin && git reset --hard origin/master && git checkout $(LDPL_VERSION) && cd src && make'
	ssh $(LINUX_x64_SERVER) './ldpl/src/ldpl -v | head -n 3'
	ssh $(LINUX_x64_SERVER) 'cd gild && rm -f gild && git pull origin master && make rebuild && strip gild'
	scp $(LINUX_x64_SERVER):~/gild/gild  dist/linux-x86-64

	ssh $(LINUX_ARM_SERVER) 'cd ldpl && git fetch origin && git reset --hard origin/master && git checkout $(LDPL_VERSION) && cd src && make'
	ssh $(LINUX_ARM_SERVER) './ldpl/src/ldpl -v | head -n 3'
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

