#include <string>

#ifndef ldpl_number
#define ldpl_number double
#endif

// definitions for LDPL
extern string VAR_GOPHERr_VHOST;      // gopher.host is text
extern ldpl_number VAR_GOPHERr_VPORT; // gopher.port is number
extern string VAR_GOPHERr_VSELECTOR;  // gopher.selector is text
extern string VAR_GOPHERr_VRESPONSE;  // gopher.response is text
void SUBPR_GOPHERr_UGET();            // sub-procedure gopher-get 

// aliases for nicer code
#define GOPHER_HOST VAR_GOPHERr_VHOST
#define GOPHER_PORT VAR_GOPHERr_VPORT
#define GOPHER_SELECTOR VAR_GOPHERr_VSELECTOR
#define GOPHER_RESPONSE VAR_GOPHERr_VRESPONSE
#define GOPHER_GET SUBPR_GOPHERr_UGET
