#include <stdio.h>
#include <string.h>
int numberCount(void);
int encrypt(int k);
int decrypt(int k);
int substitutionEncrypt(void);
int substitutionDecrypt(void);
int letterCount(void);
int main()
{   
    char mode; 
    printf("Would you like to encrypt or decrypt? ('e'/'d'):\n "); //asks user what they want to do
    scanf("%c", &mode); //records the users choice
    
    if(mode == 101) // e (i.e. user wants to encrypt) is equal to 101
    {
        
        int index = 0;
        char text [1000]; //array to hold text
    
        //prepares file to read
        FILE *input; 
        input = fopen("input.txt", "r");
        if(input == NULL)
    
        {
            perror("fopen()"); //prints a message if problem with file
        } 
        
        //stores each element of the file into an array
        while(feof(input) != 1 )
        {
            fscanf(input, "%c", &text[index]);
            index++;
        }
        
        //reads the mode (substitution or caesar) from the file and executes corresponding function.
        if(text[6] == 67 )
        {
            int k = text[14] - 65; //reads key from file
            encrypt(k);    
        }
        
        else
        {
            substitutionEncrypt();
        }
          
    }
    
    if(mode == 100) // d (i.e. user wants to decrypt) is equal to 100
    {
        int index = 0;
        char text [1000];
    
        FILE *input;
        input = fopen("input.txt", "r");
        if(input == NULL)
    
        {
            perror("fopen()"); //prints a message if problem with file
        } 
    
        while(feof(input) != 1 )
        {
            fscanf(input, "%c", &text[index]);
            index++;
        }
    
        if(text[6] == 67 )
        {
           /*if a '?' is in the 'key' section of the header, then the program will detemine themost common letter and assume
           it is an 'E'*/
           
           if(text[14] == 63) 
            {
                int k = letterCount() -69; //most common letter - 'E' will determine the key to be used
                decrypt(k);
            }
            
            else 
            {
                int k = text[14] - 65; //if a key is given, it is read from array and used
                decrypt(k);   
            }

        }
        
        else
        {
            substitutionDecrypt(); //If the file is not a caesar cipher, then it must be substitution.
        }
        
    }
    
    return(0);
}
