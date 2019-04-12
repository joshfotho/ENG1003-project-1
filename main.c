#include <stdio.h>
#include <string.h>
int main(){
    int counter = 0; // used in the for loop
    char text[100]; // the text to be encrypted;
    
    int k = 2;//the amount that that letters are shifted by
    FILE *input;
    input = fopen("test.txt", "r");
    if(input == NULL){
        perror("fopen()");
         }
//    for (int i = 0; i < 4; i++) {
//        fscanf(input, "%c", &text[i]);
//        printf("read from file: %c\n", text[i]);
//    }       
    
        
    
    
    
    //This for loop shifts each element of the string by 'k' letters
    counter = 0;
    for(counter = 0; counter < 10; counter++) {
        fscanf(input, "%c", &text[counter]);
        if(text[counter] >=65 && text[counter] <=90){
            (text[counter]) = ((text[counter] -65 + k + 26)%26) +65;
        }

        }

    
    printf("The encrypted message is: %s \n", text); 
//    
//    
    
}
