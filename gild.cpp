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

// module functions
void error(const string & msg);
void signal_handler(int sig);
void set_term_size();

void GOPHER_INIT()
{
    signal(SIGWINCH, signal_handler);
    set_term_size();
}

void error(const string & msg)
{
    cerr << "\033[1;31mGILD Error: ";
    cerr << msg;
    cerr << "\033[0m" << endl;
    exit(1);
}

void signal_handler(int sig)
{
    if (sig == SIGWINCH) set_term_size();
}

void set_term_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    WINDOW_ROWS = (ldpl_number)w.ws_row - 1; // account for prompt
    WINDOW_COLS = (ldpl_number)w.ws_col;
}


