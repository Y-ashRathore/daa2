#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int w[N][N] = {
    {0, 2, 3, 0, 0},
    {2, 0, 1, 0, 5},
    {3, 0, 0, 1, 0},
    {1, 0, 0, 0, 2},
    {0, 0, 3, 0, 0}
};

void print(int q[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (q[i][j] == INT_MAX)
                cout << "inf ";
            else
                cout << q[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

int main() {
    int Q[N][N];

    // Initialize the intermediate matrix Q with the given weights
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(w[i][j] == 0 && i!=j)
                Q[i][j] = INT_MAX;
            else
                Q[i][j] = w[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (Q[i][k] != INT_MAX && Q[k][j] != INT_MAX) {
                    Q[i][j] = min(Q[i][j], Q[i][k] + Q[k][j]);
                }
            }
        }
        cout << "Q" << k << " is" << endl;
        print(Q);
    }

    return 0;
}