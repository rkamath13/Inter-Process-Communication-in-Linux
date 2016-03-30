#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
	pid_t pid;
	int mypipefd[2];

	
	if(pipe(mypipefd)==-1)
	{
		perror("pipe :");
		exit(-1);
	}

	pid = fork();
	
	if(pid == 0)
	{/*Child Process*/	
		printf("child process...\n");
		char buf1[] = "hello there";
		close(mypipefd[0]);
		write(mypipefd[1], buf1, 12);

	}
	
	else if(pid > 0)
	{/*Parent process*/
		char buf2[12];
		printf("parent process......\n");
		close(mypipefd[1]);
		read(mypipefd[0], buf2, 12);
		printf("%s\n", buf2);
	}
	
	else
	{
		perror("fork: ");
		exit(-1);
	}





return 0;
}
