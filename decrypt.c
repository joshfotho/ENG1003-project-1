#include<stdio.h>
#include <string.h>
int numberCount(void);
char text [1000];

int decrypt(int k)
{
    int index = 0; // the position of each element in the array
    
    
    //opens file to read from
    FILE *input;
    input = fopen("input.txt", "r");
    if(input == NULL)
    {
        perror("fopen()"); //prints a message if problem with file
    }  
    
    //opens a file to write to
    FILE *output;
    output = fopen("output.txt", "w");
    
    //stores each element of the file to an array
    while(feof(input) != 1 )
    {
        fscanf(input, "%c", &text[index]);
        index++;
    }
    
    //finds length of array
    int length = strlen(text);
    
    /*This for loop shifts each element of the string by 'k' 
    letters one letter at a time */
    for(index = 15; index < length; index++)
    {
    
        
        //capital letters
        if(text[index] >=65 && text[index] <=90)
        {
            (text[index]) = ((text[index] -65 - k + 26)%26) +65;
            printf("%c", text[index]);
            fprintf(output, "%c", text[index]);
        }
        
        //lower case letters. converted to capitals
        else if(text[index] >= 97 && text[index] <=122)//lower case
        {
            (text[index]) = ((text[index] - 97 - k +26)%26) + 65;
            printf("%c", text[index]);
            fprintf(output, "%c", text[index]);
        }
        
        //non letters are not converted
        else
        {
            printf("%c", text[index]);
            fprintf(output, "%c", text[index]);
        }
        fprintf(output, "%c", 10);
    }       
    
    
    return(0);
    
}
