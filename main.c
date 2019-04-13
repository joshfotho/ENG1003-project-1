#include <stdio.h>
#include <string.h>
int main()
{
    int index = 0; // the position of each element int the array
    char text[100]; // the text to be encrypted;
    
    int k = 3;//the amount that that letters are shifted by
    FILE *input;
    input = fopen("test.txt", "r");
    if(input == NULL)
    {
        perror("fopen()"); //prints a message if problem with file
    }  
    
    /*This for loop shifts each element of the string by 'k' 
    letters one letter at a time */
    for(index = 0; index < 100; index++)
    {
        fscanf(input, "%c", &text[index]);
        
        //capital letters
        if(text[index] >=65 && text[index] <=90)
        {
            (text[index]) = ((text[index] -65 + k + 26)%26) +65;
        }
        
        //lower case letters. converted to capitals
        else if(text[index] >= 97 && text[index] <=122)//lower case
        {
            (text[index]) = ((text[index] - 97 + k +26)%26) + 65;
        }

    }
    
    printf("The encrypted message is: %s \n", text);//prints adjusted string
    
}
