

#include "config.h"
#include "mws.h"
#include "version.h"
#include "times.h"
#include "connect.h"
#include "deamon.h"

//int s;
void  cli_mws_start()
{
	printf("Start MinWebServer!!!\n");

	char buf[80];
	getcwd(buf,sizeof(buf));

	//Deamon
	//mws_deamon();

	//Socket Init
	mws_ws_init();


	
	while(1){
		sleep(1);//ÀØ√ﬂ ±º‰√Î
		printf("current dir:%s\n", buf);
		
	}
	
	
}

void  cli_mws_stop()
{
	//if(mws_ws_close(s)<0)
	//{
		printf("Stop successful!!!\n");
	//}else{
	//	printf("Stop fail!!!\n");
	//}
}



void cli_mws_restart()
{
	printf("Restart MinWebServer!!!\n");
}


void cli_mws_help()
{
	printf("help\n");
}



void  cli_mws_version()
{
	const char *s = "verson info";
	printf("%s:%s\n", s, MWS_VERSION);
	printf("author blog:midoks.cachecha.com\n");
	printf("think for you use!!!\n");
	printf("...\n");
}

/**
 * @func Command Manger MinWebServer
 * -m start 
 * -m stop
 * -m restart
 * -v version
 */
int main(int argc, char *argv[])
{
	//cmd
	int cli;
	//char *s;
	while((cli = getopt(argc, argv, "m:vht")) != EOF)
	{
		switch(cli)
		{
			case 'm':
				if(strcasecmp("start", optarg) == 0)
					cli_mws_start();
				else if(strcasecmp("stop" , optarg) == 0)
					cli_mws_stop();
				else if(strcasecmp("restart",optarg) == 0)
					cli_mws_restart();
				else
					cli_mws_help();
				break;
			case 'v':cli_mws_version();break;
			case 'h':cli_mws_help();break;
			/* test */
			case 't':mws_time_init();break;
		}
	}
	return 0;
}