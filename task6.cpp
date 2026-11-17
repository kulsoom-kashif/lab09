#include <stdio.h>
#include <string.h>

int main(){
	char english[10][20] ={
	"water", "book", "house", "food", "work", "friend", "clock", "tree", "leaf", "glasses"
	};
	
	char urdu[10][20]={
	"pani", "kitab", "ghar", "khana", "kaam", "dost", "gharhi", "darakht", "patta", "chashma"
	};
	
	char word[20]; 
	int i, found ;
	int success = 0, failed = 0;
	
	printf("Enter a word (to stop, write end):");
	scanf("%s", word);
	
	while(strcmp(word, "end")!= 0){
		found = 0;
		for (i = 0; i < 10; i++){
			if (strcmp(word, english[i])==0){
				printf("Language: English \n Translation: %s\n", urdu[i]);
				success++;
				found = 1;
				break;
			}
		}
		
	if (found == 0){
		for (i = 0; i<10; i++){
			if(strcmp(word, urdu[i])==0){
				printf("Language: Urdu\n Translation: %s\n", english[i]);
				success++;
				found=1;
				break;
			
			}
		}	
	}
	
	if (found == 0){
		printf("?\n");
		failed++;	
	}
	printf("\nEnter another word (end to stop): ");
    scanf("%19s", word);
	}
    printf("\nSuccessful lookups: %d\n", success);
    printf("Failed lookups: %d\n", failed);
    return 0;
	

}