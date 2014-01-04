#include "config.h"
#include "times.h"

void mws_time_init(){
	struct timeval t;
	long int mws_current_t;
	gettimeofday(&t,NULL);
	mws_current_t = t.tv_sec*1000 + t.tv_usec;
	printf("time %ld:%ld:::%ld\n",t.tv_sec,t.tv_usec, mws_current_t);
};
