#include<stdio.h>
#include <string.h>
int substitutionEncrypt()
{
    int index = 0;
    char text [1000];
    
    FILE *input;
    input = fopen("input.txt", "r");
    if(input == NULL)
    
    {
        perror("fopen()"); //prints a message if problem with file
    } 
    
    //opens a file to write to
    FILE *output; 
    output = fopen("output.txt", "w");
    
    //writes each element of file to an array
    while(feof(input) != 1 )
    {
        fscanf(input, "%c", &text[index]);
        index++;
    }
    int length = strlen(text); //finds length of array
    
    index = 46; //elements of the file before 46 are information and we don't want to encrypt them
    
    for(index > 46; index < length; index ++) 
    
    {
        if(text[index] >= 65 && text[index]<= 90) //only want to encrypt letters
        {
            //swaps each element of the message to be encrypted with its corresponding letter in the key. Prints to terminal and output file
            printf("%c", text[20 + (text[index]-65)]); 
            fprintf(output, "%c", text[20 + (text[index]-65)]);  
        }   
        
    }
    return(0);
    
}
