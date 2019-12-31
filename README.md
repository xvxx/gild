<p align="center"><img src="gild.png"/></p>

<p align="center">
    <b>G</b>opher <b>I</b>n <b>LD</b>PL
</p>

GILD is a gopher client for the terminal written in LDPL, an easy to
learn language for programmers of all ages.

**Features:**

- Surf your favorite Gopherholes in glorious technicolor!
- Quick, no-nonsense prompt-based navigation.
- Supports menus, files, and searches.

## ~ Screencast ~

<p align="center"><a href="https://bit.ly/2MLVOmR" target="_blank">
<img src="https://bit.ly/2sBmTlM" /></a></p>

## ~ Usage ~

    Usage: gild hostname [port [selector]]

    $ gild gopher.black
    $ gild sdf.org 70
    $ gild hngopher.com 70 /live/p1/

## ~ Install ~

Linux and Mac binaries can be downloaded from
https://github.com/dvkt/gild/releases:

- **[gild-macos.zip][macos]**
- **[gild-linux-x86-64.tar.gz][x86_64]**
- **[gild-linux-arm.tar.gz][armv8]**

Just unzip/untar the `gild` binary into your `$PATH` get going!

## ~ Building Source ~

Building from source requires **LDPL 4.3**.

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

[macos]: https://github.com/dvkt/gild/releases/download/v0.4.0/gild-macos.zip
[x86_64]: https://github.com/dvkt/gild/releases/download/v0.4.0/gild-linux-x86-64.tar.gz
[armv8]: https://github.com/dvkt/gild/releases/download/v0.4.0/gild-linux-arm.tar.gz