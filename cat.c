#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char** argv){
	FILE* file;
	char filename[20];
	printf("entered cat.c\n");
	if (argv[1][0] == '\0'){
		printf("wrong command!!\n");
	}
	if (argv[1][0] == '-'){
		if (argv[1][1] == 'n'){
			int i=3;
			while (argv[1][i] != '\0'){
				filename[i-3] = argv[1][i];
				i++;
			}
			file = fopen(filename,"r");
			printf("1)");
			int j = 1;
			char ch;
			while ((ch = fgetc(file)) != EOF){
				if (ch =='\n'){
					printf("%c",ch);
					j++;
					printf("%d)",j);
				}else{
					printf("%c",ch);
				}
			}
		}
		if (argv[1][1] == 'E'){
			int i=3;
			while (argv[1][i] != '\0'){
				filename[i-3] = argv[1][i];
				i++;
			}
			file = fopen(filename,"r");
			// int j = 1;
			char ch;
			while ((ch = fgetc(file)) != EOF){
				if (ch =='\n'){
					printf("$");
					printf("%c",ch);
					// j++;
				}else{
					printf("%c",ch);
				}
			}
		}
		// else if (argv[1][2] == ''){

		// }
	}
	// printf("DOdged all!!\n");
	// printf("%s\n",argv[1]);
	file = fopen(argv[1],"r");
	if (file == 0){
		printf("Erorr opening file!!");
	}
	char ch;
	while((ch=fgetc(file)) !=EOF){
		printf("%c", ch);
	}
	fclose(file);
	return 0;

}
