                              * * *
                     _____ _____ _    ______ 
                    |  __ \_   _| |   |  _  \
                    | |  \/ | | | |   | | | |
                    | | __  | | | |   | | | |
                    | |_\ \_| |_| |___| |/ / 
                     \____/\___/\_____/___/  

                              * * *

GILD is a gopher client for the terminal written in LDPL, a language
for programmers. This client requires the latest version of LDPL built
from master. 

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

1. Install the LDPL programming language and build from master.

    $ git clone https://github.com/lartu/ldpl
    $ cd ldpl/src 
    $ make 
    # cp ldpl to /usr/local/bin or something in your $PATH

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