#include <stdio.h> 
 
int et[100][100], visited[100]; 
void dfs(int v, int n) { 
    visited[v] = 1; 
    for (int i = 1; i <= n; i++) 
        if (et[v][i] && !visited[i]) dfs(i, n); 
} 
 
int main() { 
    int n_states, n_trans, m, n; 
    char symbol; 
    printf("Enter the number of states and transitions: "); 
    scanf("%d %d", &n_states, &n_trans); 
    printf("Enter transitions (i e j for epsilon):\n"); 
    for (int i = 0; i < n_trans; i++) { 
        scanf("%d %c %d", &m, &symbol, &n); 
        if (symbol == 'e') et[m][n] = 1; 
    } 
    for (int i = 1; i <= n_states; i++) { 
        printf("Epsilon closure of state %d: { ", i); 
        for (int j = 1; j <= n_states; j++) visited[j] = 0; 
        dfs(i, n_states); 
        for (int j = 1; j <= n_states; j++) if (visited[j]) printf("%d ", j); 
        printf("}\n"); 
    } 
    return 0; 
} 