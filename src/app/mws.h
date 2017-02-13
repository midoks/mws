
#ifndef _MWS_MWS_H_
#define _MWS_MWS_H_


#define mws_version     100000
#define MWS_VERSION  	"1.0.0"
#define MWS_VER      	"mws/" MWS_VERSION ".0"

#define MWS_AUTHOR 		"https://github.com/midoks"
#define MWS_P_URL 		"https://github.com/midoks/mws"


//start MinWebServer
void cli_mws_start();

//stop MinWebServer
void  cli_mws_stop();

//restart MinWebServer
void cli_mws_restart();

//MinWebServer version
void cli_mws_version();

//MinWebServer help info
void  cli_mws_help();

#endif
