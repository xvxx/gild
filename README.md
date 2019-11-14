<p align="center"><img src="gild.png"/></p>

<p align="center">
    <b>G</b>opher <b>I</b>n <b>LD</b>PL
</p>

GILD is a gopher client for the terminal written in LDPL, a language for programmers. 

**Features:**

- Surf your favorite Gopherholes in glorious technicolor!
- Quick, no-nonsense prompt-based navigation.
- Supports menus, files, and searches. 

## ~ Screencast ~

<p align="center">
<a href="https://asciinema.org/a/p0Ywy6fQBXRZm7sQU4OC5HeJK" target="_blank"><img src="https://asciinema.org/a/p0Ywy6fQBXRZm7sQU4OC5HeJK.svg" /></a>
</p>

## ~ Usage ~

    Usage: gild hostname [port [selector]]

    $ gild gopher.black
    $ gild sdf.org 70
    $ gild hngopher.com 70 /live/p1/

## ~ Install ~

Linux and Mac binaries can be downloaded from https://github.com/dvkt/gild/releases 

- **[gild-macos.zip](https://github.com/dvkt/gild/releases/download/v0.2.0/gild-macos.zip)**
- **[gild-linux-x86-64.tar.gz](https://github.com/dvkt/gild/releases/download/v0.2.0/gild-linux-x86-64.tar.gz)**
- **[gild-linux-arm.tar.gz](https://github.com/dvkt/gild/releases/download/v0.2.0/gild-linux-arm.tar.gz)**

Just unzip/untar the `gild` binary into your `$PATH` get going!

## ~ Building Source ~

Gild requires **LDPL 4.3**.

1. With `ldpl` in your path, clone this repo and build it:

        git clone https://github.com/dvkt/gild
        cd gild
        make build

3. Now visit your favorite gopher servers!

        ./gild bitreich.org


## ~ 🐭 ~

       (\~---.
       /   (\-`-/)
      (      ' ' )
       \ (  \_Y_/\
        ""\ \___//
           `w   "       -nathaN 
