//Aici este programul pentru adaugare de datele
void append();
void categ();
void popl();
void econom();
void terit ();

// Aici este meniul principal
int imp()
{
  while(1)
  {
  Beep(750, 300);
  printf("\n_______________Meniu_______________\n\n");
  printf(" 1. Adauga state.\n");
  printf(" 2. Adauga detali despre state.\n");
  printf(" 0. Iesire.\n");
  printf("___________________________________\n");
  ch = 0;
  printf("\n Introduceti optiunea:");
  scanf("%d",&ch);

  switch (ch)
  {
    case 1: { system("cls"); append(); break;}
    case 2: { system("cls"); categ(); break;}
    case 0: { system("cls"); exit(main()); break;}
    default:printf("\nError 0..2!\n");
  }
  mygetch();
 }
}
// Aici este submeniul
void categ ()
{
  while(1)
  {
     Beep(750, 300);
  printf("\n_______________Meniu_______________\n\n");
  printf(" 1. Adauga detali despre populatie.\n");
  printf(" 2. Adauga detali despre econommie.\n");
  printf(" 3. Adauga detali despre relief.\n");
  printf(" 0. Iesire.\n");
  printf("___________________________________\n");
  ch =0;
  printf("\n Introdoceti optiunea:");
  scanf("%d",&ch);
  switch (ch) {
    case 1: { system("cls"); popl(); break;}
    case 2: { system("cls"); econom(); break;}
    case 3: { system("cls"); terit(); break;}
    case 0: { system("cls"); imp();}
    default:printf("\nError 0..3!");
  }
  mygetch();
}
}

//Aici are loc adaugare datelor despre stat
void append ()
{
  FILE *fp;
  struct emp t1;

  fp=fopen("mydb.dat","ab");
  printf("\n Introduce numarul necesar de articole:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  printf("\n %d.Introdoceti ID:",i+1);
  scanf("%d",&t1.id);

  printf("\n Introduceti denumirea tari:");
  scanf("%s",&t1.name);

  printf("\n Introduceti denumirea capitalei:");
  scanf("%s",&t1.capitala);

  printf("\n Introduceti numele conducatorului statului:");
  scanf("%s",&t1.repre );

  printf("\n Introduceti numarul populatie:");
  scanf("%s",&t1.nrpopula );

  printf("\n Introduceti PIB tari:");
  scanf("%s",&t1.economia);

  printf("\n Introduceti suprafata teritoriul:");
  scanf("%s",&t1.teritoriu);
  fwrite(&t1,sizeof(t1),1,fp);
  }
  fclose(fp);
  printf(" \nDatele au fost introduse cu success!\n");
  printf(" \nApasa Enter pentru a continua");
}

//Aici are loc adaugarea datelor despre populatie
void popl()
{
  fflush(stdin);
  FILE *po;
  struct populat p1;
  po=fopen("popl.dat","ab");//acesta este pentru inscriere
  printf(" Atentie introduce date despre statele care exista in baza de date!\n");
  printf("\n Introduce numarul necesar de articole:");
  scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("\n %d.Introdiceti numele statului:",i+1);
    scanf("%s",&p1.numep );
    printf("\n Introdoce rata natalitatii: ");
    scanf("%s",&p1.natal);
    printf("\n Introdoce rata mortalitatii: ");
    scanf("%s",&p1.mortal);
    printf("\n Introdoce varsta: ");
    scanf("%s",&p1.varsta);
    printf("\n Introduce limba vorbita: ");
    scanf("%s",&p1.limba);
    fwrite(&p1,sizeof(p1),1,po);
    }
  fclose(po);
  printf("\n Apasa Enter pentru a continua");
}
//Aici are loc adaugarea datelor despre economie
void econom()
{
  FILE *ec;
  struct econom e1;
    fflush(stdin);
  ec=fopen("eco.dat","ab");//acesta este pentru inscriere
  printf(" Atentie introduce date despre statele care exista in baza de date!\n");
  printf("\n Introduce numarul necesar de articole:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\n %d.Introduce numele statului:",i+1);
    scanf("%s",&e1.numee);
    printf("\n Introdoce marimea exportului: ");
    scanf("%s",&e1.export);
    printf("\n Introdoce marimea importului: ");
    scanf("%s",&e1.import);
    printf("\n Introdoce salariu mediu: ");
    scanf("%s",&e1.salmediu);
    printf("\n Introduce ramara de industrie principala: ");
    scanf("%s",&e1.induprin);
    fwrite(&e1,sizeof(e1),1,ec);
      }
  fclose(ec);
  printf("\n Apasa Enter pentru a continua");
}
//Aici are loc adaugarea deatelor despre teritoriu
void terit ()
{
  FILE *tr;
  struct teritor s1;
  tr=fopen("teri.dat","ab");//acesta este pentru inscriere
  printf("\n Introduce numarul necesar de articole:");
  scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("\n %d.Introduceti numele statului:",i+1);
    scanf("%s",&s1.numet);
    printf("\n Introdoceti relieful predominant: ");
    scanf("%s",&s1.relief);
    printf("\n Introdoceti clima: ");
    scanf("%s",&s1.clim);
    printf("\n Introdoceti suprafata agricola: ");
    scanf("%s",&s1.acgric);
    printf("\n Introduceti numarul oraselor: ");
    scanf("%d",&s1.nrurbane);
    fwrite(&s1,sizeof(s1),1,tr);
    }
  fclose(tr);
  printf("\n Apasa Enter pentru a continua");
}
