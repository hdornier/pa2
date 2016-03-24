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

void conventional(int d, int x[][n], int y[][n], int z[][n]) {
  int entrySum, a, b, c;

  for (a = 0; a < n; a++) {
    for (b=0; b < n; b++) {
      entrySum = 0;
      for (c = 0; c < n; c++) {
        entrySum = entrySum + x[a][c]*y[c][b];
      }
      z[a][b] = entrySum;
    }
  }
}

int paddedValue(int n) {

}

void strassen(int n, int x[][d], int y[][n], int z[][n]) {
  int P1[n/2][n/2];
  int P2[n/2][n/2];
  int P3[n/2][n/2];
  int P4[n/2][n/2];
  int P5[n/2][n/2]; 
  int P6[n/2][n/2]; 
  int P7[n/2][n/2];
  int m1[n/2][n/2];
  int m2[n/2][n/2];

  if (n < 2){
    z[0][0] = x[0][0] * y[0][0];
  }

  if (n >= 2) {
    // P1 = A(F-H) (P3)
    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        m1[a][b] = x[a][b];
        m2[a][b] = y[a][b + n/2] - y[a + n/2][b + n/2];
      }
    }
    strassen(n/2, m1, m2, P1);

    // P2 = (A+B)H (P5)
    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        m1[a][b] = x[a][b] + x[a][b + n/2];
        m2[a][b] = y[a + n/2][b + n/2];
      }
    }

    strassen(n/2, m1, m2, P2);

    // P3 = (C+D)E (P2)
    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        m1[a][b] = x[a + n/2][b] + x[a + n/2][b + n/2];
        m2[a][b] = y[a][b];
      }
    }

    strassen(n/2, m1, m2, P3);

    // P4 = D(G - E) (P4)
    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        m1[a][b] = x[a + n/2][b + n/2];
        m2[a][b] = y[a + n/2][b] - y[a][b];
      }
    }

    strassen(n/2, m1, m2, P4);

    // P5 = (A+D)(E+H) (P1)
    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        m1[a][b] = x[a][b] + x[a + n/2][b + n/2];
        m2[a][b] = y[a][b] + y[a + n/2][b + n/2];
      }
    }

    strassen(n/2, m1, m2, P5);

    // P6 = (B-D)(G+H) (P7)
    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        m1[a][b] = x[a][b + n/2] - x[a + n/2][b + n/2];
        m2[a][b] = y[a + n/2][b] + y[a + n/2][b + n/2];
      }
    }

    strassen(n/2, m1, m2, P6);

    // P7 = (A-C)(E+F) (P6)
    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        m1[a][b] = x[a][b] - x[a + n/2][b];
        m2[a][b] = y[a][b] + y[a][b + n/2];
      }
    }

    strassen(n/2, m1, m2, P7);

    for (a=0; a < n; a++) {
      for (b=0; b < n; b++) {
        z[a][b] = P5[a][b] + P4[a][b] - P2[a][b] + P6[a][b];
        z[a][b + n/2] = P1[a][b] + P2[a][b];
        z[a + n/2][b] = P3[a][b] + P4[a][b];
        z[a + n/2][b + n/2] = P5[a][b] + P1[a][b] - P3[a][b] - P7[a][b];
      }
    }
  }
}



main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Invalid input.");
    return -1;
  }

  int dimension = atoi(argv[1]);
  int dimensionOld = dimension;

  dimension = paddedValue(dimension);

  numValues = 2 * dimensionOld * dimensionOld;
  int values[numValues];

  int m1[dimension][dimension];
  int m2[dimension][dimension];

  FILE *fp;

  if ((fp = fopen ("matrix.txt", "r")) == NULL) {
    printf("Could not read input data. \n");
    return -1;
  }

  int entry;
  int c = 0;
  while (!feof (fp) && fscanf (fp, "%d", &entry) && c < numValues) {
    values[i] = entry;
    c++;
  }

  fclose(fp);


 

}