
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>

int ls_command(char *directory ,int a,int b)
{
	struct dirent *dir;
	DIR *dh = opendir(directory);
	if (!dh)
	{
		if (errno = ENOENT)
		{
			printf("Directory do not exist");
		}
		else
		{
			printf("Unable to read the directory");
		}
		exit(EXIT_FAILURE);
	}
	while ((dir = readdir(dh)) != NULL)
	{
		if (!a && dir->d_name[0] == '.'){
			continue;
		}
		printf("%s  ", dir->d_name);
		if(b){
			printf("\n");
		}
	}
	if(!b){
		printf("\n");
	}
	return 0;
}


int main(int argc, char *argv[])
{
	if (argv[1][0] == '\0')
	{
		int ls = ls_command(".",0,0);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			//Checking if option is passed
			// a, l
			int a = 0;
			int l = 0;
			char *p = (char*)(argv[1] + 1);
			while(*p != 0){
				if(*p == 'a') {
					a = 1;
				}
				else if(*p == 'l') {
					l = 1;
				}
				else{
					perror("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			int ls = ls_command(".",a,l);
		}
	}
	return 0;
}
