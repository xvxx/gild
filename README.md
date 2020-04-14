<p align="center"><img src="gild.png"/></p>

<p align="center">
    <b>G</b>opher <b>I</b>n <b>LD</b>PL
</p>

GILD is a gopher client for the terminal written in [LDPL][ldpl],
an easy to learn language for programmers of all ages.

**Features:**

- Surf your favorite Gopherholes in glorious technicolor!
- Quick, no-nonsense prompt-based navigation.
- Supports menus, files, and searches.

**NOTE:** If you are looking for a more full-featured Gopher client
that still has pretty colors, check out [phetch][phetch].

## ~ Screencast ~

<p align="center"><a href="https://bit.ly/2MLVOmR" target="_blank">
<img src="https://bit.ly/2sBmTlM" /></a></p>

## ~ Usage ~

    Usage: gild URL

    $ gild gopher.black
    $ gild gopher://hngopher.com/live/p1/
    $ gild gopher://port70.dk/1/motd

## ~ Install ~

Linux and Mac binaries can be downloaded from
https://github.com/xvxx/gild/releases:

- **[gild-macos.zip][macos]**
- **[gild-linux-x86-64.tar.gz][x86_64]**
- **[gild-linux-arm.tar.gz][armv8]**

Just unzip/untar the `gild` binary into your `$PATH` get going!

## ~ Building Source ~

Building from source requires **LDPL 4.3**.

1. With `ldpl` in your path, clone this repo and build it:

    git clone https://github.com/xvxx/gild
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

[macos]: https://github.com/xvxx/gild/releases/download/v0.4.0/gild-macos.zip
[x86_64]: https://github.com/xvxx/gild/releases/download/v0.4.0/gild-linux-x86-64.tar.gz
[armv8]: https://github.com/xvxx/gild/releases/download/v0.4.0/gild-linux-arm.tar.gz
[ldpl]: https://www.ldpl-lang.org/
[phetch]: https://github.com/xvxx/phetch
