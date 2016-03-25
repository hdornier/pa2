/*
 *
 * CS 124
 * Programming Assignment 2
 * Henry Dornier and Matt Beatty
 *
 */


// matrix setup is [row][column]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void conventional(int d, int x[][d], int y[][d], int z[][d]) {
  int entrySum, a, b, c;

  for (a = 0; a < d; a++) {
    for (b=0; b < d; b++) {
      entrySum = 0;
      for (c = 0; c < d; c++) {
        entrySum = entrySum + x[a][c]*y[c][b];
      }
      z[a][b] = entrySum;
    }
  }

}


void strassen(int n, int x[][n], int y[][n], int z[][n]) {

  int P1[n/2][n/2];
  int P2[n/2][n/2];
  int P3[n/2][n/2];
  int P4[n/2][n/2];
  int P5[n/2][n/2]; 
  int P6[n/2][n/2]; 
  int P7[n/2][n/2];

  int p1m1[n/2][n/2];
  int p1m2[n/2][n/2];
  int p2m1[n/2][n/2];
  int p2m2[n/2][n/2];
  int p3m1[n/2][n/2];
  int p3m2[n/2][n/2];
  int p4m1[n/2][n/2];
  int p4m2[n/2][n/2];
  int p5m1[n/2][n/2];
  int p5m2[n/2][n/2];
  int p6m1[n/2][n/2];
  int p6m2[n/2][n/2];
  int p7m1[n/2][n/2];
  int p7m2[n/2][n/2];

  if (n < 2){
    z[0][0] = x[0][0] * y[0][0];
  }

  if (n >= 2) {

    // P1 = A(F-H) (P3)
    for (int a=0; a < n; a++) {
      for (int b=0; b < n; b++) {

        // P1
        p1m1[a][b] = x[a][b];
        p1m2[a][b] = y[a][b + n/2] - y[a + n/2][b + n/2];

        // P2
        p2m1[a][b] = x[a][b] + x[a][b + n/2];
        p2m2[a][b] = y[a + n/2][b + n/2];

        // P3
        p3m1[a][b] = x[a + n/2][b] + x[a + n/2][b + n/2];
        p3m2[a][b] = y[a][b];

        // P4
        p4m1[a][b] = x[a + n/2][b + n/2];
        p4m2[a][b] = y[a + n/2][b] - y[a][b];

        // P5
        p5m1[a][b] = x[a][b] + x[a + n/2][b + n/2];
        p5m2[a][b] = y[a][b] + y[a + n/2][b + n/2];

        // P6
        p6m1[a][b] = x[a][b + n/2] - x[a + n/2][b + n/2];
        p6m2[a][b] = y[a + n/2][b] + y[a + n/2][b + n/2];

        // P7
        p7m1[a][b] = x[a][b] - x[a + n/2][b];
        p7m2[a][b] = y[a][b] + y[a][b + n/2];
      }
    }

    strassen(n/2, p1m1, p1m2, P1);

    strassen(n/2, p2m1, p2m2, P2);

    strassen(n/2, p3m1, p3m2, P3);

    strassen(n/2, p4m1, p4m2, P4);

    strassen(n/2, p5m1, p5m2, P5);

    strassen(n/2, p6m1, p6m2, P6);

    strassen(n/2, p7m1, p7m2, P7);

    for (int a=0; a < n; a++) {
      for (int b=0; b < n; b++) {
        z[a][b] = P5[a][b] + P4[a][b] - P2[a][b] + P6[a][b];
        z[a][b + n/2] = P1[a][b] + P2[a][b];
        z[a + n/2][b] = P3[a][b] + P4[a][b];
        z[a + n/2][b + n/2] = P5[a][b] + P1[a][b] - P3[a][b] - P7[a][b];
      }
    }
  }
}


int main(int argc, char *argv[]) {


  int a[4][4] = {  
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 3, 8, 7} ,
   {4, 5, 6, 1} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
  };

  int b[4][4] = {  
   {5, 5, 5, 5} ,   /*  initializers for row indexed by 0 */
   {1, 5, 2, 9} ,
   {1, 5, 2, 9} ,   /*  initializers for row indexed by 1 */
   {8, 4, 0, 1}   /*  initializers for row indexed by 2 */
  };

  int c[4][4] = {
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 0 */
   {0, 0, 0, 0} ,
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 1 */
   {0, 0, 0, 0}   /*  initializers for row indexed by 2 */
  };

  printf("FDsFDS");
  //conventional(4, a, b, c);
  strassen(4, a, b, c);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d\n", c[i][j]);
    }
  }


  return 0;
}

