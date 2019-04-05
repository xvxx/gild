#include <string>

using std::string;

#ifndef ldpl_number
#define ldpl_number double
#endif

// definitions for LDPL
extern string VAR_GOPHERr_VHOST;      // gopher.host is text
extern ldpl_number VAR_GOPHERr_VPORT; // gopher.port is number
extern string VAR_GOPHERr_VSELECTOR;  // gopher.selector is text
extern string VAR_GOPHERr_VRESPONSE;  // gopher.response is text
extern ldpl_number VAR_WINDOWr_VROWS; // window.rows is number
extern ldpl_number VAR_WINDOWr_VCOLS; // window.cols is number
void SUBPR_GOPHERr_UGET();            // sub-procedure gopher-get 
void SUBPR_GOPHERr_UINIT();           // sub-procedure gopher-init

// aliases for nicer code
#define GOPHER_HOST VAR_GOPHERr_VHOST
#define GOPHER_PORT VAR_GOPHERr_VPORT
#define GOPHER_SELECTOR VAR_GOPHERr_VSELECTOR
#define GOPHER_RESPONSE VAR_GOPHERr_VRESPONSE
#define WINDOW_ROWS VAR_WINDOWr_VROWS
#define WINDOW_COLS VAR_WINDOWr_VCOLS
#define GOPHER_GET SUBPR_GOPHERr_UGET
#define GOPHER_INIT SUBPR_GOPHERr_UINIT

// module functions
void error(const string & msg);
int connect_to(string & hostname, int port);
string fetch(int sock, string & selector);
void signal_handler(int sig);
void set_term_size();
