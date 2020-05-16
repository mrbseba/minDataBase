//Este declara biblioteca proprie unde are loc legarea tuturor date
#include "stfis.h"
//Aici este meniul de baza
int main()
{
while(1)
{
  Beep(750, 300);
  
printf("\n_____________Sistemul de Management al Bazei de Date_____________\n\n");
printf(" 1. Adaugarea datelor.\n\n");
printf(" 2. Modificarea datelor.\n\n");
printf(" 3. Stergerea datelor.\n\n");
printf(" 4. Cautarea datelor.\n\n");
printf(" 5. Afisarea detaliilor alese.\n\n");
printf(" 6. Afisarea tutor datelor.\n\n");
printf(" 7. Redenumirea.\n\n");
printf(" 8. Stergerea fisierelor.\n\n");
printf(" 0. Iesire.\n\n");
printf("_________________________________________________________________\n\n");
printf("\n Introduceti optiunea:");
scanf("%d",&ch);

switch(ch)
{
case 1: { system("cls"); imp(); break;}
case 2: { system("cls"); upmodmeiu (); break;}
case 3: { system("cls"); demeniu (); break;}
case 4: { system("cls"); topsearchmenu (); break;}
case 5: { system("cls"); menuafisarea(); break;}
case 6: { system("cls"); displayAll(); break;}
case 7: { system("cls"); rname(); break;}
case 8: { system("cls"); rremove(); break;}
case 0: { system("cls"); Beep(1000, 100), exit(0);}
default:printf("\n0..9!");
}
mygetch();
}
return 0;
}
