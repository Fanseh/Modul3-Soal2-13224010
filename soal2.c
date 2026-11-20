//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2026/2027
// *   Modul               : 3
// *   Hari dan Tanggal    : Rabu, 18 November 2026
// *   Nama (NIM)          : Hezkiel Tarutung Harianja (13224010)
// *   Nama File           : soal2_modul3_sem5.c
// *   Deskripsi           : Program Pesta Besar
// * 
// */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Fungsi untuk mencari langkah minimum 
int minSteps(int m, int n, int d){
    if(d < 0 || d > (m > n ? m : n)){
        return -1;
    }
    int q[10000][3], front = 0, rear = 0;
    bool visited[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            visited[i][j] = false;
        }
    }
    q[rear][0] = 0;
    q[rear][1] = 0;
    q[rear][2] = 0;
    rear++;
    visited[0][0] = true;

    while(front != rear){
        int jug1 = q[front][0];
        int jug2 = q[front][1];
        int steps = q[front][2];
        front++;
        if(jug1 == d || jug2 == d){
            return steps;
        }
        if(!visited[m][jug2]){
            visited[m][jug2] = true;
            q[rear][0] = m;
            q[rear][1] = jug2;
            q[rear][2] = steps + 1;
            rear++;
        }
        if(!visited[jug1][n]){
            visited[jug1][n] = true;
            q[rear][0] = jug1;
            q[rear][1] = n;
            q[rear][2] = steps + 1;
            rear++;
        }
        if(!visited[0][jug2]){
            visited[0][jug2] = true;
            q[rear][0] = 0;
            q[rear][1] = jug2;
            q[rear][2] = steps + 1;
            rear++;
        }
        if(!visited[jug1][0]){
            visited[jug1][0] = true;
            q[rear][0] = jug1;
            q[rear][1] = 0;
            q[rear][2] = steps + 1;
            rear++;
        }
        int pour1to2 = jug1 < (n - jug2) ? jug1 : (n - jug2);
        if(!visited[jug1 - pour1to2][jug2 + pour1to2]){
            visited[jug1 - pour1to2][jug2 + pour1to2] = true;
            q[rear][0] = jug1 - pour1to2;
            q[rear][1] = jug2 + pour1to2;
            q[rear][2] = steps + 1;
            rear++;
        }
        int pour2to1 = jug2 < (m - jug1) ? jug2 : (m - jug1);
        if(!visited[jug1 + pour2to1][jug2 - pour2to1]){
            visited[jug1 + pour2to1][jug2 - pour2to1] = true;
            q[rear][0] = jug1 + pour2to1;
            q[rear][1] = jug2 - pour2to1;
            q[rear][2] = steps + 1;
            rear++;
        }
    }
    return -1;
}

int main(){
    int m, n, d;
    if(scanf("%d %d %d", &m, &n, &d) != 3){
        return 1;
    }
    int result = minSteps(m, n, d);
    printf("%d\n", result);
    return 0;
}

//Reference : 
//1. https://www.geeksforgeeks.org/c/c-program-for-breadth-first-search-or-bfs-for-a-graph/
//2. https://stackoverflow.com/questions/53471588/find-the-minimum-number-of-steps-to-decrease-n-to-zero
//3. https://www.geeksforgeeks.org/dsa/minimize-steps-required-to-reach-the-value-n/
//4. https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/
//5. https://stackoverflow.com/questions/20895596/bfs-algorithm-in-c
//6. https://www.geeksforgeeks.org/c/gcd-in-c/
//7. https://www.geeksforgeeks.org/c/lcm-of-two-numbers-in-c/
//8. https://www.geeksforgeeks.org/dsa/two-water-jug-puzzle/
