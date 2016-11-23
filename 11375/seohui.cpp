#include <iostream>
#include <string.h>

#define MAX 1000

using namespace std;

int g_adj[MAX][MAX];
bool visited[MAX];

int g_employee;
int g_work;
int g_emp_arr[MAX];
int g_work_arr[MAX];

bool dfs (int emp) {
    if (visited[emp]) {
        return false;
    }

    visited[emp] = true;
    
    int j = 0;

    for (int i = 0; i < g_adj[emp][0]; i++) {
        j = g_adj[emp][i+1];
        
        if (g_work_arr[j] == -1 || dfs(g_work_arr[j])) {

            g_emp_arr[emp] = j;
            g_work_arr[j] = emp;

            return true;
        }
    }

    return false;
}

int main() {
    int value = 0;
    int flag = 0;
    int max_work = 0;

    cin >> g_employee >> g_work;
    memset(g_emp_arr, -1, sizeof(int)*MAX);
    memset(g_work_arr, -1, sizeof(int)*MAX);

    for (int i = 1; i <= g_employee; i++) {
        cin >> flag;
        g_adj[i][0] = flag;
        
        for (int j = 0; j < flag; j++) {
            cin >> value;
            g_adj[i][j+1] = value;
        } 
    }

    //do dfs
    for (int n = 1; n <= g_employee; n++) {
        if (g_emp_arr[n] == -1) {
            memset(visited, false, sizeof(bool)*MAX);
            
            if (dfs(n)) {
                max_work++;
            }
        }
    }

    cout << max_work << endl;

    return 0;
}

