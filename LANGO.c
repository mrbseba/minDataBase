//Este declara biblioteca proprie unde are loc legarea tuturor date
#include "stfis.h"
//Aici este meniul de baza
int main()
{
while(1)
{
  Beep(750, 300);

printf("\n _____________Sistemul de Management al Bazei de Date_______________\n");
printf(" | 1. Adaugarea datelor.                                           |\n");
printf(" | 2. Modificarea datelor.                                         |\n");
printf(" | 3. Modificarea unui element din date.                           |\n");
printf(" | 4. Stergerea datelor.                                           |\n");
printf(" | 5. Cautarea datelor.                                            |\n");
printf(" | 6. Afisarea datelor alese.                                      |\n");
printf(" | 7. Afisarea tutor datelor.                                      |\n");
printf(" | 8. Sortare datelor.                                             |\n");
printf(" | 9. Crearea unei liste temporare.                                |\n");
printf(" | 10. Crearea unei liste temporare print copiere.                 |\n");
printf(" | 0. Iesire.                                                      |\n");
printf(" ___________________________________________________________________\n");
printf("\n Introduceti optiunea:");
scanf("%d",&ch);

switch(ch)
{
case 1: { system("cls"); imp (); break;}
case 2: { system("cls"); upmodmeiu (); break;}
case 3: { system("cls"); upmodelem (); break;}
case 4: { system("cls"); demeniu (); break;}
case 5: { system("cls"); topsearchmenu (); break;}
case 6: { system("cls"); menuafisarea (); break;}
case 7: { system("cls"); displayAll (); break;}
case 8: { system("cls"); sortmenu (); break;}
case 9: { system("cls"); list (); break;}
case 10: { system("cls"); listenod (); break;}
case 0: { system("cls"); Beep(1000, 100), exit(0);}
default:printf("\nError 0..9!");
}
mygetch();
}
return 0;
}
