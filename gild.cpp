#include <cstring>
#include <iostream>
#include <signal.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;

#ifndef ldpl_number
#define ldpl_number double
#endif

ldpl_number WINDOW_ROWS; // window.rows
ldpl_number WINDOW_COLS; // window.cols

void set_term_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    WINDOW_ROWS = (ldpl_number)w.ws_row - 1; // account for prompt
    WINDOW_COLS = (ldpl_number)w.ws_col;
}

void signal_handler(int sig)
{
    if (sig == SIGWINCH) set_term_size();
}

void GOPHER_INIT()
{
    signal(SIGWINCH, signal_handler);
    set_term_size();
}
