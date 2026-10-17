//compare next line to prev line, if same do nothing, and if different then print the new line
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void uniq(FILE *fp){
        //helper function to identify and print unique lines
	char *curr_line  = NULL;
	char *prev_line = NULL;
	ssize_t bytes_read = 0;
	size_t curr_size = 0;
	
	//read first line of input
	bytes_read = getline(&curr_line, &curr_size, fp);
	if(bytes_read != -1){
		//if something was read, then always print the first line
		printf("%s", curr_line);
	
		//move curr_line to prev_line
		prev_line = curr_line;
		//reset curr so the next invocation of getline can overwite it
		curr_line = NULL;
		curr_size = 0;
	}

	while((bytes_read = getline(&curr_line, &curr_size, fp)) != -1){
                //compare curr line to previous line
		if(strcmp(prev_line, curr_line) != 0){
			printf("%s", curr_line);
		}
		
        
		free(prev_line);//free it of the previous value
		prev_line = curr_line; //immediately update with new value

		curr_line = NULL;
		curr_size = 0;
	}
	free(prev_line);
	free(curr_line);
	
}//end uniq

int main(int argc, char *argv[]){
        //accept 0 or 1 command line argument
        if(argc == 1){
                //if no file specified, read from stdin
                uniq(stdin);
                return 0;
                //or count(stdin) since stdin is already a file pointer         
        }
        else if(argc == 2){
                //read from the specified file
                //char filename = argv[1];
                FILE *fp = fopen(argv[1], "r");
                //check if file opened successfully
                if(fp == NULL){
                        printf("ERROR: file could not be opened");
                        return 1;
                }
                
		uniq(fp);
                fclose(fp);
                
		return 0;
        }
        else{//accept exatly 1 or no command line arguments
                printf("ERROR: cannot contain more than 2 command line arguments");
		return 1;
	}
}

