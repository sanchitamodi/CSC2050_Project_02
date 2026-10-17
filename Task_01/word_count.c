#include <stdio.h>

void count(FILE *fp){
	//helper function to count # of characters, words and lines
	int ch = fgetc(fp);
	int count_char = 0;
	int count_word = 0;
	int count_line = 0;
	int in_word = 0;

	while(ch != EOF){
		//# of char increments by 1 until you get to EOF
		count_char++;

		if(ch == '\n'){
			//increment #of lines every time you see a /n
			count_line++;
			//this is done after cause \n also counts as a char
		}
		
		//check for whitespaces
		if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v'){
			in_word = 0; //in whitespace
		}
		else if (in_word == 0){
			in_word = 1; //stepped out of whitespace into a new word
			count_word++;
		}	

		ch = fgetc(fp); //read the next char
	}
	printf("characters: %d\nwords: %d\nlines: %d\n", count_char, count_word, count_line);
}//end count

int main(int argc, char *argv[]){
	//accept 0 or 1 command line argument
	if(argc == 1){
		//if no file specified, read from stdin
		count(stdin);
		return 0;
		//or count(stdin) since stdin is already a file pointer		

	}
	else if(argc == 2){
		//read from the specified file
		//char filename = argv[1];
                FILE *fp = fopen(argv[1], "r");
        
                //check if file opened successfully
                if(fp == NULL){
                        printf("ERROR: file could not be opened\n");
                        return 1;
                }

		count(fp);

                fclose(fp);
                return 0;
	
	}	
	else{//accept exatly 1 or no command line arguments
		printf("ERROR: cannot contain more than 2 command line arguments\n");
		return 1;
	}
	

}
