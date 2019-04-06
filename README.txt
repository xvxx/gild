                              * * *
                     _____ _____ _    ______ 
                    |  __ \_   _| |   |  _  \
                    | |  \/ | | | |   | | | |
                    | | __  | | | |   | | | |
                    | |_\ \_| |_| |___| |/ / 
                     \____/\___/\_____/___/  

                              * * *

GILD is a gopher client for the terminal written in LDPL, a language
for programmers. This client is a big hack that requires dvkt's  
experimental fork of LDPL. For now. Consider it a work in progress.

Screencast
~~~~~~~~~~

View a lil asciicast of GILD in action here: 

    https://asciinema.org/a/hzEPi57q4YlbDbkniMZaGTjhD
                    
Usage 
~~~~~

    Usage: gild hostname [port [selector]]
    
    $ gild gopher.black
    $ gild sdf.org 70
    $ gild hngopher.com 70 /live/p1/

Install
~~~~~~~

Linux and Mac binaries can be downloaded from:

    https://github.com/dvkt/gild/releases

Just unzip/untar the `gild` binary into your `$PATH` get going!

Building Source
~~~~~~~~~~~~~~~

1. Install the LDPL programming language: https://ldpl.lartu.net/

(NOTE: Install the `extensions` branch from github.com/dvkt/ldpl)

2. With `ldpl` in your path, clone this repo then build it:

    $ make build

3. Now visit your favorite gopher servers!

    $ ./gild bitreich.org

TODO 
~~~~

[✓] Connect to server and print response 
[✓] Display dir contents in technicolor
[✓] Prompt-based navigation (show link #s and ask what to do)
[✓] 0 to go back 
[✓] Render one page at a time
[✓] Pipe file contents to less (or just use the same infra as menus)
[✓] Search

                           (\~---.
                           /   (\-`-/)
                          (      ' ' )
                           \ (  \_Y_/\
                            ""\ \___//
                               `w   "    -nathaN 