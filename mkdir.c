
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
  
void main(int argc, char** argv)
{
    int check;
    char* dirname = argv[1];
	printf("%s\n", dirname);
    // clrscr();
  
    check = mkdir(dirname,0777);
  
    // check if directory is created or not
    if (!check)
        printf("Directory created\n");
    else {
        printf("Unable to create directory\n");
        exit(1);
    }
  
    // getch();
  
    // system("dir");
    // getch();
}