#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>



int main(){
	
	printf("Hello all!\n");
	printf("!!WELCOME TO PRATHAM'S SHELL!!\n");
	int cont = 1;
	char* address = "hello";
	while (cont){
		printf("%s>>>", address);
		char command[500] = {"\0"};
		scanf("%[^\n]%*c",command);
		//printf("command taken\n");
		char instruction[20]= {};
		int single_inst = 0;
		int i =0;
		while(command[i] != ' ' ){
			if (command[i] == '\0'){
				single_inst = 1;
				break;
			}
			instruction[i] = command[i];
			printf("%s\n",instruction);
			i++;
		}
		
	//      printf("%d\n",i);
		char rest[100] = {};
		if (!single_inst){
			i = i+1;
			int j=0;
			while( command[i] != '\0'){
				rest[j] = command[i];
		        printf("%s\n",rest);
				i++;
				j++;
			}
		}
		//printf("initializing argv\n");
		char *argv[3];
		//printf("intialized\n");
		//printf("checking \n");

		if (strcmp(instruction, "exit")==0){
			printf("entered exit\n");
			cont =0;
			// exit(1);
			break;
		}
		
		else if (!strcmp(instruction,"echo")){
			// code for echo actually calling execvp
			// printf("process echo intializing\n");
			int process_echo = fork();   // calling a new process also as a child process;
			if (process_echo <0){
				printf("error reported in echo fork call\n");
			}
			else if (process_echo==0){
				// child process
				// here I will code for the execv sys call and call the echo.c file which will do the rest process
				// argv[0] = "./echo";
				// argv[1] = rest;
				// argv[2] = NULL;
				// execv(argv[0],argv);
				if (rest[0] !='-'){
					if (rest[0] == '\"'){
						i = 1;
						while (rest[i]!= '\"'){
							printf("%c", rest[i]);
							i++;
						}
					}
					else{
						printf("%s",rest);
					}
					printf("\n");
						// printf("%s\n", rest);
				}
				else if (rest[1] == 'E'){
					if (rest[3] == '\"'){
						i = 4;
						while (rest[i]!= '\"'){
							printf("%c", rest[i]);
							i++;
						}
					}
					else{
						i = 3;
						while (rest[i]!= '\0'){
							printf("%c", rest[i]);
							i++;
						}
					}
					printf("\n");
						// printf("%s\n", rest);
				}
				else if (rest[1] == 'n'){
					if (rest[3] == '\"'){
						i = 4;
						while (rest[i]!= '\"'){
							printf("%c", rest[i]);
							i++;
						}
					}
					else{
						i = 3;
						while (rest[i]!= '\0'){
							printf("%c", rest[i]);
							i++;
						}
					}	
				}
			}
			else{
				pid_t c = wait(NULL); // the parent process will wait for the child process to complete
				continue;
			}
		}
		else if (!strcmp(instruction,"cd")){
			// code for changing directory calling execvp
			int process_cd = fork();
			
			if (process_cd <0){
				printf("Error reported in cd fork call\n");
			}
			else if(process_cd == 0){
				char* s;
				//child process
				// code here for execv syscall to call cd.c to run
				// argv[0] = "./cd";
				// argv[1] = rest;
				// argv[2] = NULL;
				// execv(argv[0],argv);
				int i = 0;
				while(rest[i]){
					if (rest[i] == ' '){
						printf("wrong command for cd!!\n");
						break;
					}
					i++;
				}
				if (rest[0] == '\0'){
					getcwd(s,100);
					chdir("..");
					getcwd(address,100);
				}
				else if (rest[0] != '\0'){
					getcwd(s,100);
					chdir(rest);
					getcwd(address,100);
				}
			}
			else{
				pid_t c = wait(NULL);//parent will wait for the child process to complete
				continue;
			}
		
		}
		else if (!strcmp(instruction,"ls")){
			// code for redirecting to ls.c using execvp
			int process_ls = fork();
			if (process_ls <0){
				printf("error reported in ls fork call\n");
			}
			else if(process_ls ==0){
				// child process
				// code here for the execv for ls.c
				argv[0] = "./ls";
				argv[1] = rest;
				argv[2] = NULL;
				execv(argv[0],argv);

			}
			else{
				pid_t c = wait(NULL);
				continue;
			}
		}
		else if (!strcmp(instruction,"cat")){
			//code for redirecting to cat.c using execvp
			int process_cat = fork();
			if (process_cat < 0){
				printf("Error reported in cat fork call");
			}
			else if (process_cat == 0){
				// child process
				// code here for the execv for cat.c
				argv[0] = "./cat";
				argv[1] = rest;
				argv[2] = NULL;
				execv(argv[0],argv);
			}
			else{
				pid_t c = wait(NULL);
				continue;
			}
			
		}
		//printf("reached pwd\n");
		else if (strcmp(instruction,"pwd")==0){
			//code for redirecting to pwd.c using execvp
		//	printf("reached inside pwd\n");
			int process_pwd = fork();
			if (process_pwd <0){
				printf("error reported in pwd fork call");
			}
			else if (process_pwd ==0){
				// child process 
				// code here for the execv for pwd.c
				// argv[0] = "./pwd";
				// argv[1] = rest;
				// argv[2] = NULL;
				// execv(argv[0],argv);
				char *current_dir = (char*) malloc(1024);
				if (getcwd(current_dir,1024) != NULL){
					printf("%s\n",current_dir);
				}else{
					printf("error in pwd printing!!\n");
				}
	
			}
			else{
				pid_t c = wait(NULL);
				continue;
			}
		}

		else if (strcmp(instruction,"rm")==0){
			//code for redirecting to rm.c using execvp
			int process_rm = fork();
			if (process_rm <0){
				printf("error reported in rm fork call");
			}
			else if (process_rm ==0){
				// child process
				// code here for the execv for rm.c
				printf("reached rm if block\n");
				argv[0] = "./rm";
				argv[1] = rest;
				argv[2] = NULL;
				execv(argv[0],argv);

			}
			else{
				pid_t c = wait(NULL);
				continue;
			}
		}

		else if (!strcmp(instruction,"mkdir")){
			// code for redirecting to mkdir.c using execv
			int process_mkdir = fork();
			if (process_mkdir <0){
				printf("error reported in mkdir fork call");
			}
			else if( process_mkdir == 0){
				// child process 
				// code here for execv call for mkdir.c
				argv[0] = "./mkdir";
				argv[1] = rest;
				argv[2] = NULL;
				execv(argv[0],argv);
			}
			else{
				pid_t c = wait(NULL);
				continue;
			}
		}

		else if (strcmp(instruction,"date")==0){
			// code for redirecting to date.c using execvp
			int process_date = fork();
			if (process_date <0){
				printf("error reported in date fork call");

			}
			else if (process_date == 0){
				// child process
				// code here for execv call to date.c
				argv[0] = "./date";
				argv[1] = rest;
				argv[2] = NULL;
				execv(argv[0],argv);
			}
			else{
				pid_t c = wait(NULL);
				continue;
			}
		}

		else{
			printf("Wrong command!! Try again!!\n");
			continue;
		}

		//printf("the command is %s\n",instruction);
		//printf("the instruction is %s\n",rest);
	}
	
	return 0;
}



 