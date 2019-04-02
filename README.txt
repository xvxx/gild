                              * * *
                     _____ _____ _    ______ 
                    |  __ \_   _| |   |  _  \
                    | |  \/ | | | |   | | | |
                    | | __  | | | |   | | | |
                    | |_\ \_| |_| |___| |/ / 
                     \____/\___/\_____/___/  

                              * * *

GILD is a command line gopher client written in LDPL, a language
for programmers. This client is a big hack that requires a working
UNIX environment. Specifically, the `nc` and `tput` UNIX commands.
For now.

                           (\~---.
                           /   (\-`-/)
                          (      ' ' )
                           \ (  \_Y_/\
                            ""\ \___//
                               `w   "    -nathaN 
                    
Usage 
~~~~~

1. Install the LDPL programming language: https://ldpl.lartu.net/

2. With `ldpl` in your path, build GILD:

    $ make build

3. Now visit your favorite gopher server!

    $ ./gild gopher.black
    $ ./gild sdf.org 70
    $ ./gild hngopher.com 70 /live/p1/

TODO 
~~~~

** Essential

[✓] Connect to server and print response (bad: depends on nc)
[✓] Display dir contents in technicolor
[✓] Prompt-based navigation (show link #s and ask what to do)
[ ] 0 to go back 
[ ] Render one page at a time
[ ] Pipe file contents to less (or just use the same infra as menus)
[ ] Search

** Nice to have 

[ ] Download file to pwd 
[ ] Render images in fancy terminals like kitty 
[ ] move from nc to socket API (need: LDPL C/C++ interop)
[ ] Are we missing anything basic?
