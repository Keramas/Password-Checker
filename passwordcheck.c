#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main()
{
	char password[100];
	int symbol, number, lowerC, upperC, length = 0;	
	int i;
        int strength = 1;
	
	printf(ANSI_COLOR_RED    "=====================================\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN  "=     Password Strength Checker     =\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_YELLOW "=====================================\n" ANSI_COLOR_RESET);
        printf("Please enter the password you would like to have checked:\n");
	scanf("%s", password);
        printf("\n");
	const int string_len = strlen(password);	
	for(i=0; i < string_len; i++){

		if(isdigit(password[i])){
			number=1;
		}

		if(isupper(password[i])){
			upperC=1;
		}	
		
	
		if(islower(password[i])){
			lowerC=1;
		}
	

		if(!isdigit(password[i]) && !isalpha(password[i])){
			symbol=1;
		}


		if(string_len >= 10){
			length=1;
		}

	}


	if(number==1){
		printf("[+]Contains numbers and letters.\n");
		strength++;
	}else{
		printf("[-]Please use numbers and letters.\n");	
	}
	
	if(upperC==1 && lowerC==1){
		printf("[+]Contains uppercase and lowercase letters.\n");
		strength++;	
	}else{
		printf("[-]Please use upper and lower case letters.\n");
	}
	
	if(symbol==1){
		printf("[+]Uses symbols.\n");
		strength++;
	}else{
		printf("[-]Does not include the use of symbols.\n");
	}
	
	if(length==1){
		printf("[+]Proper length.\n");
		strength++;
	}else{
		printf("[-]Not a long enough password.\n");
	}	

	printf("\n");
	
	//Results of the test//

	if(strength == 5){
		printf("Strength: " ANSI_COLOR_GREEN "[==========] Strong" ANSI_COLOR_RESET "\n");
        }else if(strength == 4){
                printf("Strength: " ANSI_COLOR_YELLOW "[=======   ] Somewhat strong" ANSI_COLOR_RESET "\n");
       	}else if(strength == 3){
                printf("Strength: " ANSI_COLOR_YELLOW "[===       ] Weak" ANSI_COLOR_RESET "\n");
     	}else if(strength == 2){
                printf("Strength: " ANSI_COLOR_RED "[=         ] Super weak" ANSI_COLOR_RESET "\n");
        }else{
		printf("Strength: " ANSI_COLOR_RED "You are going to get hacked!" ANSI_COLOR_RESET "\n");       
	}
	
	printf("\n");

	return 0;
}
