#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#define MAX_EXPR 10 
 
int main() { 
    int n; 
    char op[2], op1[5], op2[5], res[5]; 
    char const_val[5], const_var[5]; 
    printf("Enter the maximum number of expressions: "); 
    scanf("%d", &n); 
 
    char expressions[MAX_EXPR][4][5]; 
    printf("Enter the input:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%s %s %s %s", expressions[i][0], expressions[i][1], expressions[i][2], expressions[i][3]); 
 
    for (int i = 0; i < n; i++) { 
        if (strcmp(expressions[i][0], "=") == 0) { 
            strcpy(const_val, expressions[i][1]); 
            strcpy(const_var, expressions[i][3]); 
        } else { 
            if (strcmp(expressions[i][1], const_var) == 0) strcpy(expressions[i][1], const_val); 
            if (strcmp(expressions[i][2], const_var) == 0) strcpy(expressions[i][2], const_val); 
 
            if (isdigit(expressions[i][1][0]) && isdigit(expressions[i][2][0])) { 
                int a = atoi(expressions[i][1]), b = atoi(expressions[i][2]); 
                sprintf(expressions[i][3], "%d",  
                    (expressions[i][0][0] == '+') ? a + b : 
                    (expressions[i][0][0] == '-') ? a - b : 
                    (expressions[i][0][0] == '*') ? a * b : 
                    (expressions[i][0][0] == '/') ? a / b : a); 
            } 
        } 
    } 
    printf("\nOptimized code is:\n"); 
    for (int i = 0; i < n; i++) 
        if (strcmp(expressions[i][0], "=") != 0) { 
            printf("%s %s %s %s\n", expressions[i][0], expressions[i][1], expressions[i][2], 
expressions[i][3]); 
        } 
    return 0; 
}