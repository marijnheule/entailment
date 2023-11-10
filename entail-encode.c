#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
  int tmp, lit;
  int nVar, nCls, lVar, lCls, rVar, rCls, rLit;

  FILE *left, *right;

  left  = fopen (argv[1], "r");
  right = fopen (argv[2], "r");

//  while (1) {
    tmp = fscanf (left, " p cnf %i %i ", &lVar, &lCls);
    if (tmp != 2) {
      printf ("c ERROR: no header file detected in %s\n", argv[1]);
      exit (1); }
//  }

//  while (1) {

    rLit = 0;
    tmp = fscanf (right, " p cnf %i %i ", &rVar, &rCls);
    if (tmp != 2) {
      printf ("c ERROR: no header file detected in %s\n", argv[2]);
      exit (1); }

    while (1) {
      tmp = fscanf (right, " %i ", &lit);
      if (tmp == EOF) break;
      if (lit != 0) rLit++;
    }
    fclose (right);

    nVar = rVar + rCls;
    nCls = lCls + rLit + 1;
    printf ("p cnf %i %i\n", nVar, nCls);

  while (1) {
    tmp = fscanf (left, " %i ", &lit);
    if (tmp == EOF) break;
    if (lit != 0) printf ("%i ", lit);
    else          printf ("0\n");
  }
  fclose (left);

  for (int i = 1; i <= rCls; i++)
    printf ("%i ", rVar + i);
  printf ("0\n");

  right = fopen (argv[2], "r");

  tmp = fscanf (right, " p cnf %i %i ", &rVar, &rCls);
  if (tmp != 2) {
    printf ("c ERROR: no header file detected in %s\n", argv[2]);
    exit (1); }

  int aux = rVar+1;
  while (1) {
    tmp = fscanf (right, " %i ", &lit);
    if (tmp == EOF) break;
    if (lit != 0) printf ("%i %i 0\n", -aux, -lit);
    if (lit == 0) aux++;
  }
  fclose (right);


//  }

}
