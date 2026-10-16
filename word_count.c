#include <stdio.h>
void count_char(char *fp){
	//helper function to count # of characters
	int ch = fgetc(fp);
	int count = 0;

	//loop unitl EOF and increment counter every iteration
	while(ch != EOF){
		count++;
		ch = fgetc(fp);
	}

}
int main(int argc, char *argv[]){
	//accept 0 or 1 command line argument
	if(argc == 0){
		//if no file specified, read from stdin
		

	}
	else if(argc == 1){
		//read from the specified file
		char filename = argv[1];
                FILE *fp = fopen(filename, "r");
        
                //check if file opened successfully
                if(fp == NULL){
                        printf("ERROR: file could not be opened");
                        return 0;
                }


                fclose(fp);
                return 0;
	
	}	
	else{//accept exatly 1 or no command line arguments
		printf("ERROR: cannot contain more than 2 command line arguments");
	
	
	}

}
