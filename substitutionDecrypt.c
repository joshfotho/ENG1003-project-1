#include<stdio.h>
#include <string.h>
int substitutionDecrypt()
{
    int index = 0; 
    char text [1000];
    int key;
    
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
    
    //writes each element of the file to an array
    while(feof(input) != 1 )
    {
        fscanf(input, "%c", &text[index]);
        index++;
    }
    //finds length of array
    int length = strlen(text);
    
    index = 46; //the first 45 characters are the array are information. We don't want to decrypt them.
    
   /* This section of code checks each character of the code to be decrypted. It then determines which element in the substitution key this 
   character corresponds with. It then prints out the letter that is determined by the position of the element in the key. For example,
   if a character in the encrypted code matched the first letter in the key, then the program would print out the letter 'A'.*/
   
   for(index > 46; index < length; index ++) 
    {
        if(text[index] >= 65 && text[index]<= 90) //only decrypts letters
        {
            
            for(key = 20; key <= 45; key ++) // Finds the position of the current character in the key
            {
                if(text[index] == text[key])
                {
                    printf("%c", key-20+65); 
                    fprintf(output, "%c", key-20+65); /*prints the letter corresponding to the characters position in the key. Prints to 
                    both the terminal and the output file*/
                }
            }
            
        }
        else
        {
            printf("%c", text[index]); //non - letters are not altered. 
        }
        
    }
    return(0);
    
}
