#include <math.h>
#include <stdio.h>
#define INFILE  "infile"
#include "type.h"


void initialize(char *argv[], POPULATION *p);
void generation(POPULATION *p, int gen);
void report(int gen, POPULATION *p, IPTR  pop);
void statistics(POPULATION *p, IPTR pop);

main(int argc, char *argv[])
{
  IPTR tmp, op, np, ndim;
  POPULATION population;
  POPULATION *p = &population;

  p->gen = 0;
  //if(argc != 2) erfunc("Usage: ga <inputfile name> ", argc);
  initialize(argv, p);
  printf("beginning \n");
  while(p->gen < p->maxGen){
    p->gen++;
    generation(p, p->gen);
    statistics(p, p->np);
    report(p->gen, p, p->np);
    tmp = p->op;
    p->op = p->np;
    p->np = tmp;
  }
}
