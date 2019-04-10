#include <stdio.h>
#include <string.h>
int main(){
    int length;
    int counter = 0; // used in the for loop
    char text[100]; // the text to be encrypted;
    int k = 2;//the amount that that letters are shifted by
    length = strlen(text);
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
    for(counter = 0; counter < length; counter++) {
        (text[counter]) = ((text[counter] -65 + k + 26)%26) +65;  
        }
    counter = 0;
    printf("The encrypted message is: %s \n", text); 
    
    
    
}
