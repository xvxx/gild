* GILD: Gopherin' around with LDPL

GILD is a command line gopher client written in LDPL, a language
for programmers. This client is a big hack that requires a working
UNIX environment.

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

    $ ./gild-bin gopher.black
    $ ./gild-bin sdf.org 70
    $ ./gild-bin hngopher.com 70 /live/p1/

TODO 
~~~~

[x] Connect to server and print response (bad: depends on nc)
[x] Display dir contents in technicolor
[ ] Prompt-based navigation (show link #s and ask what to do)
[ ] Pipe file contents to less
[ ] Search
[ ] Download file to pwd 
[ ] Are we missing anything basic?
