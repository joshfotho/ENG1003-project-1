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
    
    FILE *output;
    output = fopen("output.txt", "w");
    
    while(feof(input) != 1 )
    {
        fscanf(input, "%c", &text[index]);
        index++;
    }
    int length = strlen(text);
    
    index = 46;
    
    for(index > 46; index < length; index ++)
    
    {
        if(text[index] >= 65 && text[index]<= 90)
        {
            printf("%c", text[20 + (text[index]-65)]);
            fprintf(output, "%c", text[20 + (text[index]-65)]);
        }   
        
    }
    return(0);
    
}
