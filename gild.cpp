#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <string>
#include <unistd.h>

#include "gild.h"

using namespace std;

void GOPHER_GET() 
{
    int sock = connect_to(GOPHER_HOST, GOPHER_PORT);
    GOPHER_RESPONSE = fetch(sock, GOPHER_SELECTOR);
}

void error(const string & msg)
{
    cerr << "\033[1;31mGILD Error: ";
    cerr << msg;
    cerr << "\033[0m" << endl;
    exit(1);
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
        error("connect() failed");

    return sock;
}

string fetch(int sock, string & selector) 
{
    string request = "";
    if (!selector.empty()) request = selector;
    request += "\r\n";

    if (send(sock,request.c_str(),request.size(),0) != request.size())
        error("send() sent unexpected number of bytes");

    int rsize = 500000; // XXX 500k? bigger?
    string response;
    char buf[rsize];
    int bytes, totalBytes = 0;
    while (totalBytes < rsize) {
        if ((bytes = read(sock, buf, rsize)) < 0)
            error("recv() failed");
        if (bytes == 0) break;
        totalBytes += bytes;
        response += buf;
    }

    if (response[totalBytes-3] == '.' &&
        response[totalBytes-2] == '\r' &&
        response[totalBytes-1] == '\n') {
        response[totalBytes-3] = '\0';
    }

    return response;
}

