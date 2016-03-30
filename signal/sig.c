#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void myhandle(int mysignal)
{

	printf("inside the handlewith signal %d\n", mysignal);
}

int main( int argc, char* argv[])
{
	
	signal(SIGTERM, myhandle);
	int i=0;
	while(1)
	{
	i++;
	printf("%d\n", i);
	sleep(1);
	}	

return 0;
}
