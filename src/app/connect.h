#ifndef _MWS_CGI_H_
#define _MWS_CGI_H_


typedef struct req_info{
	void** buffer;
	unsigned int size;
	unsigned int allocSize;
}req_info_t;



//web server init
void mws_ws_init();

//web server accpet
void mws_ws_acpt(int s);

void mws_ws_analysis(int s);

//web server send
int mws_ws_send(int ns);

//web server close
int mws_ws_close(int s);

#endif
