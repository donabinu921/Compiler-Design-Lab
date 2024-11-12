#include <stdio.h> 
#include <string.h> 
int z = 0, i = 0, j = 0, c = 0; 
char input[16], stack[15];  
void check(); 
int main() 
{ 
 
    puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id"); 
    puts("enter input string "); 
    scanf("%s", input); 
    c = strlen(input); 
    puts("stack \t input \t action"); 
    for ( i = 0; j < c; i++, j++) 
      { 
         printf("\n$%s\t%s$\tSHIFT", stack, input); 
            stack[i] = input[j]; 
            stack[i + 1] = '\0'; 
            input[j] = ' '; 
           check(); 
      } 
        printf("\n$%s\t%s$\tDONE\n", stack, input); 
            if(strcmp(stack,"E") == 0) 
  printf("String Accepted\n"); 
            else 
printf("String Rejected\n"); 
 } 
         
void check() 
{ 
    for (z = 0; z < c; z++) 
        if (stack[z] >= 'a' && stack[z] <= 'z') 
        {printf("\n$%s\t%s$\tREDUCE BY E->id", stack, input); 
            stack[z] = 'E'; 
            stack[z + 1] = '\0'; 
 } 
    for (z = 0; z < c; z++) 
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E') 
        {printf("\n$%s\t%s$\tREDUCE BY E->E+E", stack, input); 
            stack[z] = 'E'; 
            stack[z + 1] = '\0'; 
            stack[z + 2] = '\0'; 
            i = i - 2; 
        } 
 for (z = 0; z < c; z++) 
        if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E') 
        {printf("\n$%s\t%s$\tREDUCE BY E->E*E", stack, input); 
            stack[z] = 'E'; 
            stack[z + 1] = '\0'; 
            stack[z + 2] = '\0'; 
            i = i - 2; 
        } 
    for (z = 0; z < c; z++) 
        if (stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')') 
        {printf("\n$%s\t%s$\tREDUCE BY E->(E)", stack, input); 
            stack[z] = 'E'; 
            stack[z + 1] = '\0'; 
            stack[z + 2] = '\0'; 
            i = i - 2; 
        } 
} 