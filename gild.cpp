#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <signal.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <unordered_map>

#include "gild.h"

using namespace std;

static unordered_map<string, string> response_cache;

void GOPHER_INIT()
{
    signal(SIGWINCH, signal_handler);
    set_term_size();
}

void GOPHER_GET()
{
    string cache_key = GOPHER_HOST+":"+to_string(GOPHER_PORT)+GOPHER_SELECTOR;
    if(response_cache.find(cache_key)!=response_cache.end())
    {
        GOPHER_RESPONSE = response_cache[cache_key];
        return;
    }

    int sock = connect_to(GOPHER_HOST, GOPHER_PORT);
    GOPHER_RESPONSE = fetch(sock, GOPHER_SELECTOR);
    response_cache[cache_key] = GOPHER_RESPONSE;
    close(sock);
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
    WINDOW_ROWS = (ldpl_number)w.ws_row;
    WINDOW_COLS = (ldpl_number)w.ws_col;
}

int connect_to(string & hostname, int port)
{
    struct hostent *h = gethostbyname(hostname.c_str());
    if (h==NULL) { error("bad hostname: "+hostname); }
    if (h->h_length <= 0) error("gethostbyname() failed");

    char *servIP = inet_ntoa(*(struct in_addr*)(h->h_addr_list[0]));

    int sock;
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        error("socket() failed");

    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr)); // zero out
    servAddr.sin_family      = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(servIP);
    servAddr.sin_port        = htons(port);

    if(connect(sock,(struct sockaddr*)&servAddr,sizeof(servAddr)) < 0)
        error("connect() failed host:"+hostname+" port:"+to_string(port));

    return sock;
}

string fetch(int sock, string & selector)
{
    string request = "";
    if (!selector.empty()) request = selector;
    request += "\r\n";

    if (send(sock,request.c_str(),request.size(),0) != request.size())
        error("send() sent unexpected number of bytes");

    int bsize = 999999; // XXX 999k? bigger?
    int bytes = 0;
    int i = 0;
    char buf[bsize];
    string output;

    while((i=read(sock,buf+bytes,bsize-bytes))!=0){
        bytes+=i;
    }
    buf[bytes] = 0;

    string response = buf;

    if(response[response.size()-3]=='.' &&
       response[response.size()-2]=='\r' &&
       response[response.size()-1]=='\n'){
        response[response.size()-3] = 0;
    }

    return response;
}

