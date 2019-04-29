int substitutionEncrypt(void);
int substitutionDecrypt(void);
int numberCount(void);
int main()
{   
    char mode; 
    printf("Would you like to encrypt or decrypt? ('e'/'d'):\n ");
    scanf("%c", &mode);
    
    if(mode == 101) // e is equal to 101
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
            int k = text[14] - 65;
            encrypt(k);    
        }
        
        else
        {
            substitutionEncrypt();
        }
          
    }
    
    if(mode == 100) // d is equal to 100
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
            if(text[14] == 63)
            {
                int k = numberCount() -69;
                decrypt(k);
            }
            
            else 
            {
                int k = text[14] - 65;
                decrypt(k);   
            }

        }
        
        else
        {
            substitutionDecrypt();
        }
        
    }
    
    return(0);
}
