#include <stdio.h> 
#include <string.h> 
int z = 0, i = 0, j = 0, c = 0; 
char a[16], ac[20], stk[15], act[10];  
void check(); 
int main() 
{ 
 
    puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id"); 
    puts("enter input string "); 
    scanf("%s", a); 
    c = strlen(a); 
    strcpy(act, "SHIFT"); 
    puts("stack \t input \t action"); 
    for ( i = 0; j < c; i++, j++) 
      { 
         printf("\n$%s\t%s$\t%s", stk, a, act); 
            stk[i] = a[j]; 
            stk[i + 1] = '\0'; 
            a[j] = ' '; 
           check(); 
      } 
        printf("\n$%s\t%s$\tDONE\n", stk, a); 
            if(strcmp(stk,"E") == 0) 
  printf("String Accepted\n"); 
            else 
printf("String Rejected\n"); 
 } 
         
void check() 
{ 
    strcpy(ac, "REDUCE by E"); 
    for (z = 0; z < c; z++) 
        if (stk[z] >= 'a' && stk[z] <= 'z') 
        {printf("\n$%s\t%s$\t%s->id", stk, a, ac); 
            stk[z] = 'E'; 
            stk[z + 1] = '\0'; 
 } 
    for (z = 0; z < c; z++) 
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') 
        {printf("\n$%s\t%s$\t%s->E+E", stk, a, ac); 
            stk[z] = 'E'; 
            stk[z + 1] = '\0'; 
            stk[z + 2] = '\0'; 
            i = i - 2; 
        } 
 for (z = 0; z < c; z++) 
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') 
        {printf("\n$%s\t%s$\t%s->E*E", stk, a, ac); 
            stk[z] = 'E'; 
            stk[z + 1] = '\0'; 
            stk[z + 2] = '\0'; 
            i = i - 2; 
        } 
    for (z = 0; z < c; z++) 
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') 
        {printf("\n$%s\t%s$\t%s->(E)", stk, a, ac); 
            stk[z] = 'E'; 
            stk[z + 1] = '\0'; 
            stk[z + 2] = '\0'; 
            i = i - 2; 
        } 
} 