#include "config.h"
#include "connect.h"

void mws_ws_init(){
	int s;
	struct sockaddr_in addr;

	//socket create
	if((s = socket(AF_INET, SOCK_STREAM, 0)) <0){
		perror("socket create fail");
		exit(1);
	}

	//set socket line
	//int keepalive = 1; // 开启keepalive属性
	int on = 1;	//地址重新启用属性
	//int keepidle = 60; // 如该连接在60秒内没有任何数据往来,则进行探测
	//int keepinterval = 5; // 探测时发包的时间间隔为5 秒
	//int keepcount = 3; // 探测尝试的次数.如果第1次探测包就收到响应了,则后2次的不再发.
	//setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, (void *)&keepalive , sizeof(keepalive));
	setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	//setsockopt(s, SOL_TCP, TCP_KEEPIDLE, (void*)&keepidle , sizeof(keepidle));
	//setsockopt(s, SOL_TCP, TCP_KEEPINTVL, (void *)&keepinterval , sizeof(keepinterval));
	//setsockopt(s, SOL_TCP, TCP_KEEPCNT, (void *)&keepcount , sizeof(keepcount));
	
	//printf("SO_REUSEADDR:%d", ret);

	//fill in sockaddr_in
	bzero((struct sockaddr*)&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(80);
	addr.sin_addr.s_addr = inet_addr("192.168.157.129");

	//socket bind
	if(bind(s, (struct sockaddr*)&addr, sizeof(struct sockaddr_in))<0){
		perror("socket bind error");
		exit(1);
	}

	//socket listen
	if(listen(s, 3)<0){
		perror("socket listen error");
		exit(1);
	}
	
	mws_ws_acpt(s);
}

//web server accept
void mws_ws_acpt(int s)
{
	int ns;
	//char buffer[1024];

	//pid_t pid;
	// create process
	//pid = fork();

	while(1){
		//bzero(buffer,sizeof(struct sockaddr));
		/*if(pid==0)
		{
			//printf("this is child process\n");
		}
		else if(pid > 0)
		{
			//printf("this is parent process\n");
		}
		else
		{
			printf("error in fork\n");
		}*/

		/* accept */
		if((ns=accept(s, NULL, NULL))<0){
			perror("accept error\n");
			exit(1);
		}
		
		//第一个方式
		/*if(recv(ns, buffer, sizeof(buffer), 0)<0){
			printf("recv error\r\n");
			exit(1);
		}*/

		//第二种方式:文件流打开
		mws_ws_analysis(ns);
		

		//denpend on accept to send
		if(mws_ws_send(ns)<0){
			exit(1);
		}	
	}
}


void mws_ws_analysis(int s)
{
	FILE *data = NULL;
	data = fdopen(s, "r+");
	char buf[10240L];
	int j=0;
	while (!feof(data)) {
		
		char* in = fgets(buf, 10240L-2, data);
		printf("%d:%s\n", j,in);
		j++;

		if(!in){//EOF
			break;
		}

		if(!strcmp(in, "\r\n") || !strcmp(in,"\n")) {//Reached end of headers.
			break;
		}
	}
}



int mws_ws_send(int ns){
	char r[1024];
	bzero(r, 1024);


	//header
	strcat(r,"HTTP/1.1 200 OK\r\n");
	strcat(r,"Date: Tue, 09 Jul 2013 07:55:52 GMT\r\n");
	strcat(r,"Server: MWS/0.1.0\r\n");
	//strcat(r,"Transfer-Encoding: chunked\r\n");
	strcat(r,"Content-Type: text/html; charset=UTF-8\r\n");
	//strcat(r,"Connection: Keep-Alive\r\n");
	strcat(r,"Connection: close\r\n");
	//content
	strcat(r, "\r\n");
	strcat(r, "<html><head><title>MWS</title></head><body>MWS is working,thinks for you using</body></html>");

	//send 
	if(send(ns, r, 1024, MSG_DONTWAIT)<0){
		perror("send error\n");	
		exit(1);
	}
	close(ns);
	return 0;
}

int mws_ws_close(int s){
	int sd;
	sd = shutdown(s, 2);
	return sd;
}
