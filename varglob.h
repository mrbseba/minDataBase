//Aici este declarat bibliotecilor pentru sunet
#include "windows.h"
#include "direct.h"
//Aici sunt declarate biblotecile de lucru
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "errno.h"
//Aceste failuri suntpentru struct principala
FILE *fp, *fp1;
//Aceste failuri sunt declarate pentru structura populatie
FILE *po, *po1;
//Acesta failuri sunt declarate pentru structura economie
FILE *ec, *ec1;
//Aceste failuri sunt declarate pentru structura teritoriu
FILE *tr, *tr1;
//File pentru structura principala
//pentru modificare temp.dat
char fname[]={"mydb.dat"};
//File pentru structura populatie
// pentru modificare mptemp.dat
char pname[]={"popl.dat"};
// Fiel pentru structura economie
// pentru modifcare metemp.dat
char ename[]={"eco.dat"};
//File pentru structura teritoriu
// pentru modifcare tetemp.dat
char tname[]={"teri.dat"};
//Aici sunt decalrate variabiele de lucru standarte
int i = 0, n = 0, ch = 0;
int found = 0, val =0, id = 0;
