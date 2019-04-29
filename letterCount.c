#include<stdio.h>
#include <string.h>
int numberCount()
{
    int elementIndex = 0, letterIndex = 65, letterCount = 0, maxLetterCount = 0; 
    char currentLetter = 65;
    char text[1000];
    FILE *input;
    input = fopen("input.txt", "r");
    if(input == NULL)
    {
        perror("fopen()"); //prints a message if problem with file
    }  
    while(feof(input) != 1 )
    {
        fscanf(input, "%c", &text[elementIndex]);
        elementIndex++;
    }
    int length = strlen(text);

    
    
    
    for(letterIndex = 65; letterIndex  <90; letterIndex ++)
    {   letterCount = 0;
       for(elementIndex = 14; elementIndex < length; elementIndex ++)
       {
           if((int)text[elementIndex] == (int)letterIndex)
           {
               letterCount ++;
               
           }
           if(letterCount > maxLetterCount){
               maxLetterCount = letterCount;
               currentLetter = letterIndex;
           }
        
       }
      
    }
    
    return(currentLetter);
    
}
