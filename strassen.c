/*
 *
 * CS 124
 * Programming Assignment 2
 * Henry Dornier and Matt Beatty
 *
 */

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

void strassen(int d, int x[][d], int y[][n], int z[][n]) {
  
}

main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Invalid input. Pass arguments flag, dimension, and input file.");
    return 0;
  }

  dimension = atoi(argv[1]);

  FILE *fp;

}