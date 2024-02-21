#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"

int main(){
  BiblioH* b=creer_biblio(1000);
  inserer(b,1,"Le corbeaux et le renards","Jean");
  inserer(b,2,"La cigale et la fourmi","Jean");
  inserer(b,1,"Therese Raquin","Emile");
  return 0;
  }