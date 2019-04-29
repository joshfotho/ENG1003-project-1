#include<stdio.h>
#include <string.h>
int substitutionDecrypt()
{
    int index = 0;
    char text [1000];
    int key;
    
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
            
            for(key = 20; key <= 45; key ++)
            {
                if(text[index] == text[key])
                {
                    printf("%c", key-20+65);
                    fprintf(output, "%c", key-20+65);
                }
            }
            
        }
        else
        {
            printf("%c", text[index]);
        }
        
    }
    return(0);
    
}
