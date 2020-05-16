
//Aici este declar structura principala
typedef struct emp
{
    int id;
    char name[30];
    char repre[30];
    char capitala[30];
    char nrpopula[30];
    char economia[30];
    char teritoriu[30];
}t, t1;
//Aici este declarata srtuctura pentru populatie
typedef struct populat
{
    char numep[30];
    char natal[30];
    char mortal[30];
    char varsta[30];
    char limba[30];
}p, p1;
//Aici este declart structura petru economie
 typedef struct econom
   {
     char numee[30];
     char	export[30];
     char import[30];
     char salmediu[30];
     char induprin[30];
   }e, e1;
//Aici este declarat structura pentru teritoriu
typedef struct teritor
  {
    char numet[30];
    char relief[30];
    char clim[30];
    char acgric[30];
    int nrurbane;
  }s,s1;

//////////////////////////////////
//Aic are loc legatura dintre documente
#include "varglob.h"
#include "fuastop.c"
#include "search.c"
#include "append1.c"
#include "rname.c"
#include "rremove.c"
#include "modify.c"
#include "del.c"
#include "display.c"
#include "displayAll.c"
//fgets
