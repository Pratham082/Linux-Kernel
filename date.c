#include <stdio.h>
#include <time.h>

int main (int argc,char* argv[]) {
	char* option = argv[1];
	if (option[0] == '-'){
		if (option[1] == 'u'){
			char buffer[100];
			time_t now = time (0);
			strftime (buffer, 100, "%d-%m-%Y  %H:%M:%S", gmtime (&now));
			printf ("%s\n", buffer);
			return 0;
		}
		// else if (option[1] == 'R'){
		// 	struct date dt;
		// 	printf("%%%")
		// }
	}
    char buffer[100];
    time_t now = time (0);
    strftime (buffer, 100, "%d-%m-%Y %H:%M:%S", localtime (&now));
    printf ("%s\n", buffer);
    return 0;
}