void search();
void upserchmenu();
void serpopu ();
void serecon ();
void serteri ();

//Aici este meniu principal
void topsearchmenu ()
{
  while(1)
  {
  Beep(750, 300);
  printf("\n_______________Meniu_______________\n\n");
  printf(" 1. Cautarea state.\n");
  printf(" 2. Cautarea detali despre state.\n");
  printf(" 0. Iesire.\n");
  printf("___________________________________\n");
  ch = 0;
  printf("\n Introduceti optiunea:");
  scanf("%d",&ch);
  switch (ch)
  {
  case 1:
    {
    system("cls");
    printf("\n\n Introduceti numarul necesar de stergere:");
    n = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    search ();
    }
    printf("Apasa Enter pentru a continua\n");
    break;
    }
    case 2: { system("cls"); upserchmenu(); break;}
    case 0: { system("cls"); exit(main()); break;}
    default:printf("\nError 0..2!\n");
  }
  mygetch();
  }
}
//Aici este submeniul
void upserchmenu()
{
  while(1)
  {
     Beep(750, 300);
  printf("\n_______________Meniu_______________\n\n");
  printf(" 1. Cautarea detali despre populatie.\n");
  printf(" 2. Cautarea detali despre econommie.\n");
  printf(" 3. Cautarea detali despre relief.\n");
  printf(" 0. Iesire.\n");
  printf("___________________________________\n");
  ch =0;
  printf("\n Introdoceti optiunea:");
  scanf("%d",&ch);
  switch (ch) {
    //Aici are loc cautarea datelor despre populatie
  case 1:
    {
    system("cls");
    printf("\n\n Introduceti numarul necesar de stergere:");
    n = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    serpopu();
    }
    printf(" Apasa Enter pentru a continua");
    break;
    }
    //Aici are loc cautarea datelor despre economie
  case 2:
    {
    system("cls");
    printf("\n\n Introduceti numarul necesar de stergere:");
    n = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    serecon ();
    }
    printf(" Apasa Enter pentru a continua");
    break;
    }
    //Aici are loc caitarea datelor despre teritoriu
  case 3:
    {
    system("cls");
    printf("\n\n Introduceti numarul necesar de stergere:");
    n = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    serteri();
    }
    printf(" Apasa Enter pentru a continua");
    break;
    }
    case 0: { system("cls"); topsearchmenu ();}
    default:printf("\nError 0..3!");
  }
  mygetch();
  }
}

//Functia de cautarea e tarii
void search()
{
FILE *fp;
struct emp t;
found=0;
char sname[20];
fp=fopen("mydb.dat","rb");
printf("\n Introduce numele tari:");
scanf("%s",&sname);
while(1)
{
  fread(&t,sizeof(t),1,fp);
  if(feof(fp))
{
  break;
}

if(strcmp(sname,t.name)==0)
{
  found = 1;
printf("\n______________________________________________________________________________________________________________\n\n");
printf("\t\t\t\t\t Detalile despre tara %d\n\n",t.id);
printf("______________________________________________________________________________________________________________\n\n");
printf(" Denumirea\tConducatorul\tCapitala\tNumarul Populatie\tEconimia\tSuprafata tari\n\n");
printf(" %s  \t ",t.name);
printf("%s\t",t.repre);
printf("%s\t\t",t.capitala);
printf("%s Mili\t\t",t.nrpopula);
printf("%s Marde\t",t.economia);
printf("%s Km^2\t\n\n",t.teritoriu);
printf("______________________________________________________________________________________________________________\n\n");
}
}
if(found==0)
{
printf("\n - Scuzati nu sa gasit nici o inregistrare\n");
}
fclose(fp);

}

// Functia de cautarea date despre populatii
void serpopu ()
{
  fflush(stdin);
  FILE *po;
  struct populat p;
  int found=0;
  char pname[30];
  po=fopen("popl.dat","rb");

    printf("\n Introduceti numele tari pentru cautarea datelor despre populatie:");
    scanf("%s",&pname);
  while(1)
  {
  fread(&p,sizeof(p),1,po);

  if(feof(po))
  {
  break;
  }
  if(strcmp(pname,p.numep)==0)
  {
  found=1;
  printf("\n______________________________________________________________________\n\n");
  printf("\t\t Detalile despre Populatia %s\n\n",p.numep);
  printf("______________________________________________________________________\n\n");

  printf(" Natalitatea\tMortalitatea\tSperatan de viata\tLimba\n\n");

  printf(" %s \t\t",p.natal);
  printf("%s\t\t",p.mortal);
  printf("%s ani  \t\t",p.varsta);
  printf("%s\n\n",p.limba);

  printf("______________________________________________________________________\n\n");
  }
  }
  if(found==0)
  {
  printf("\n - Scuzati nu sa gasit nici o inregistrare\n\n");
  }

  fclose(po);

}
// Functia de cautarea a date despre economie
void serecon ()
{
  fflush(stdin);
  FILE *ec;
  struct econom e;
  found=0;
  char ename[30];
  ec =fopen("eco.dat","rb");

  printf("\n Introduceti numele tari pentru cautarea datelor economice:");
  scanf("%s",&ename);
  while(1)
  {
  fread(&e,sizeof(e),1,ec);
  if(feof(ec))
  {
  break;
  }
  if(strcmp(ename,e.numee)==0)
  {
  found=1;
  printf("\n_____________________________________________________________________________________\n\n");
  printf("\t\t\t\t Detalile despre Economia %s\n\n",e.numee);
  printf("_____________________________________________________________________________________\n\n");

  printf(" \tExport\t\t\tImport\t\tSalariu mediu\t\t\tIndustria\n\n");

  printf(" \t%s$ Marde\t\t",e.export);
  printf("%s$ Marde\t\t",e.import);
  printf("%s$\t\t\t",e.salmediu);
  printf("%s\n\n",e.induprin);

  printf("_____________________________________________________________________________________\n\n");
  }
  }
  if(found==0)
  {
  printf("\n - Scuzati nu sa gasit nici o inregistrare\n\n");
  }

  fclose(ec);
  printf(" Apasa Enter pentru a continua");
}
//Functia de cautrea da datelor despre relief
void serteri ()
{
  fflush(stdin);
  FILE *tr;
  struct teritor s;
  found = 0;
  char tename[30];
  tr = fopen("teri.dat","rb");

    printf("\n Introduceti numele tari pentru cautare datelor despre relief:");
    scanf("%s",&tename);
    while(1)
    {
    fread(&s,sizeof(s),1,tr);

    if(feof(tr))
    {
    break;
    }
    if(strcmp(tename,s.numet)==0)
    {
    found=1;
    printf("\n_____________________________________________________________________________________________________________________\n\n");
    printf("\t\t\t Detalile despre relief %s\n\n",s.numet);
    printf("_____________________________________________________________________________________________________________________\n\n");
    printf("\t\tOrase\t\tSuprafata agricola\t\tRelieful\t\tClima\n\n");
    printf("\t\t%d\t\t%s mil ha\t\t\t%s \t%s\n\n",s.nrurbane,s.acgric, s.relief, s.clim);
      printf("\n_____________________________________________________________________________________________________________________\n\n");

    }
    }
    if(found==0)
    {
    printf("\n - Scuzati nu sa gasit nici o inregistrare\n\n");
    }

    fclose(tr);
printf(" Apasa Enter pentru a continua");
}
