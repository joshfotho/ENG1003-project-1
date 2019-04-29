#include<stdio.h>
#include <string.h>
int letterCount()
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
    
    //scans each element of file to an array
    while(feof(input) != 1 )
    {
        fscanf(input, "%c", &text[elementIndex]);
        elementIndex++;
    }
    //finds length of array
    int length = strlen(text);

    //For each letter, the array is checked to see how frequent that letter is. 
    for(letterIndex = 65; letterIndex  <90; letterIndex ++) //i.e. starts at A and goes to Z
    {   letterCount = 0; //counter for each time the current letter is found
       for(elementIndex = 14; elementIndex < length; elementIndex ++) 
       {
           if((int)text[elementIndex] == (int)letterIndex)
           {
               letterCount ++; //increments counter when the array element is the letter that is currently being checked for
               
           }
           //when a letter is more frequent than the previously most frequent letter, it becomes the most frequent letter
           if(letterCount > maxLetterCount){
               maxLetterCount = letterCount;
               currentLetter = letterIndex;
           }
        
       }
      
    }
    
    return(currentLetter);
    
}
