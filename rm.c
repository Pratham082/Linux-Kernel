#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>


int main(int argc, char** argv){
	// printf("Reached in rm.c file\n");
	char* option = argv[1];
	// printf("%s\n",option);
	DIR * dir = opendir(".");
	// printf("directory created\n");
	if (option[0] == '\0'){
		printf("Wrong COmmand!! Enter file name!!\n");
	}
	if (option[0] != '-' ){
		// printf("Entered in if block where '-' is not mentioned\n");
		int i= 0;
		char file_names[10][50];
		int index_files = 0;
		int loop_break = 0;
		// printf("About to enter in while loop to extract file name\n");
		while(option[i] != '\0'){
			// printf("entered in while loop %d times\n", i);
			int j=0;
			char file_single[30] = {};
			while (option[i] != ' '){
				// printf("%c\n", option[i]);
				if (option[i] == '\0'){
					// printf("recieved end before blank\n");
					loop_break = 1;
					break;
				}
				// printf("looping till recieve a blank space: %d\n", j);
				file_single[j] = option[i];
				// printf("%s\n", file_single);
				j++;
				i++;
			}
			// printf("time to copy string literal into array of strings\n");
			strcpy(file_names[index_files],file_single);
			// printf("this will not be printed\n");
			index_files++;
			i++;
			if(loop_break){
				// printf("Loop breaked\n");
				break;
			}
		}
		// printf("filename: %s\n%s\n", file_names[0], file_names[1]);

		struct dirent *file;
		for (int k =0;k<index_files;k++){
			int file_found = 0;
			while ((file = readdir(dir)) != NULL)
			{
				if(strcmp(file->d_name,file_names[k]) == 0){
					file_found = 1;
					{
						printf("removing file: %s\n",file_names[k]);
						remove(file_names[k]);
						break;
					}
				}
				
			}
			if (!file_found){
				printf("\'%s\' File does not exist in directory!!\n", file_names[k]);
			}
		}

	}
	if (option[0] == '-'){
		if (option[1] = 'i'){
			if (option[3] == '\0'){
				printf("Wrong Command!! please type file name!!\n");
			}

			int i= 3;
			char file_names[10][50];
			int index_files = 0;
			int loop_break = 0;
			while(option[i] != '\0'){
				int j=0;
				char file_single[30] = {};
				while (option[i] != ' '){
					if (option[i] == '\0'){
						loop_break = 1;
						break;
					}
					file_single[j] = option[i];
					j++;
					i++;
				}
				strcpy(file_names[index_files],file_single);
				index_files++;
				i++;
				if(loop_break){
					break;
				}
			}
			printf("file names: %s %s %s\n",file_names[0],file_names[1],file_names[2]);

			struct dirent *file;
			int file_found;
			int repeat;
			char answer;
			for (int k =0;k<index_files;k++){
				file_found = 0;
				while ((file = readdir(dir)) != NULL)
				{
					if(strcmp(file->d_name,file_names[k]) == 0){
						file_found = 1;
						repeat = 1;
						while (repeat){
							repeat = 0;
							printf("Are you sure you want to delete: %s : ", file_names[k]);
							scanf("%c",&answer);
							if (answer == 'y'){
								remove(file_names[k]);
								break;
							}
							else if(answer != 'n' && answer != 'y'){
								printf("wrong input for y/n: Enter again!! \n");
								repeat = 1;
							}
						}
						break;
					}
					
				}
				if (!file_found){
					printf("\'%s\' File does not exist in directory!!\n", file_names[k]);
				}
			}
		
		}
	}
	return 0;
}

