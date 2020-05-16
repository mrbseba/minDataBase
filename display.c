void display();
void sumenius();
void affpopl();
void affecon ();
void affteri();

//Meniul principal pentru afisare
int menuafisarea ()
{
  while(1)
  {
    Beep(750, 300);
    printf("\n___________________Meniu___________________\n\n");
    printf(" 1. Afiseaza date despre un stat.\n");
    printf(" 2. Afiseaza date despre datele aditionale.\n");
    printf(" 0. Iesire.\n");
    printf("___________________________________________\n");
    printf("\n Introduti aptiunea:");
    ch = 0;
    scanf("%d",&ch);
    switch (ch)
    {
      case 1: { system("cls"); display(); break;}
      case 2: { system("cls"); sumenius(); break;}
      case 0: { system("cls"); exit(main()); break;}
      default:printf("Error 0..2!!\n");
    }
    mygetch();
  }
}
//Sub submeniul de afisare
void sumenius()
{
  while(1)
  {
  Beep(750,300);
  printf("\n___________________Meniu___________________\n\n");
  printf(" 1. Afiasare date despre populatie.\n");
  printf(" 2. Afisarea date despre economie.\n");
  printf(" 3. Afisarea date despre teritoriu.\n");
  printf(" 0. Iesire.\n");
  printf("___________________________________________\n");
  printf("\n Introduti optiunea:");
  ch = 0;
  scanf("%d",&ch);
  switch (ch)
  {
    case 1: { system("cls"); affpopl(); break;}
    case 2: { system("cls"); affecon(); break;}
    case 3: { system("cls"); affteri(); break;}
    case 0: { system("cls"); menuafisarea(); break;}
    default:printf("Error 0...3!!\n");
  }
  mygetch();
  }
}

//Aici este functia de afisarea pentru stat
void display()
{
fflush(stdin);
FILE *fp;
struct emp t;
int found=0;
fp=fopen("mydb.dat","rb");
while(1)
{
fread(&t,sizeof(t),1,fp);
if(feof(fp))
{
break;
}
printf("\n___________________________________________________________________________________________________________\n\n");
printf("\t\t\t\t\t Detalile despre ID %d\n\n",t.id,found=1);
printf("___________________________________________________________________________________________________________\n\n");
printf(" Denumirea\tCapitala\tConducatorul\t\tNr.Populatia\tEconomia\tSuprafata Tari\n\n");
printf(" %s  \t",t.name);
printf("%s\t\t",t.capitala);
printf("%s\t\t",t.repre);
printf("%s\t",t.nrpopula);
printf("%s Marde\t",t.economia);
printf("%s Km^2\t\n\n",t.teritoriu);
printf("___________________________________________________________________________________________________________\n\n");

}
if(found==0)
{
printf("\n Scuzati nu a fost introdusa nici o inregistrare.");
}

fclose(fp);
printf("\n\n Apasa Enter pentru a continua");
}

//Aici este funcita de afisarea pentru populatia
void affpopl ()
{
  fflush(stdin);
  FILE *po;
  struct populat p;
  int found=0;
  po=fopen("popl.dat","rb");
  while(1)
  {
  fread(&p,sizeof(p),1,po);
  if(feof(po))
  {
  break;
  }
  printf("\n______________________________________________________________________\n\n");
  printf("\t\t Detalile despre Populatia %s\n\n",p.numep, found=1);
  printf("______________________________________________________________________\n\n");
  printf(" Natalitatea\tMortalitatea\tSperatan de viata\tLimba\n\n");
  printf(" %s\t\t",p.natal);
  printf("%s\t\t",p.mortal);
  printf("%s ani\t\t",p.varsta);
  printf("%s\n\n",p.limba);
  printf("______________________________________________________________________\n\n");

  }
  if(found==0)
  {
  printf("\n Scuzati nu sa gasit nici o inregistrare");
  }
  fclose(po);
printf(" Apasa Enter pentru a continua");
}
//Aici este funcita de afisare pentru economie
void affecon ()
{
  fflush(stdin);
  FILE *ec;
  struct econom e;
  found=0;
  ec =fopen("eco.dat","rb");
  while(1)
  {
  fread(&e,sizeof(e),1,ec);
  if(feof(ec))
  {
  break;
  }
  printf("\n_____________________________________________________________________________________\n\n");
  printf("\t\t\t Detalile despre Economia %s\n\n",e.numee,  found=1);
  printf("_____________________________________________________________________________________\n\n");

  printf(" Export\t\t\tImport\t\tSalariu mediu\t\tIndustria\n\n");

  printf(" %s$ Marde\t\t",e.export);
  printf("%s$ Marde\t",e.import);
  printf("%s$ \t\t",e.salmediu);
  printf("%s\n\n",e.induprin);

  printf("_____________________________________________________________________________________\n\n");
  }
  if(found==0)
  {
  printf("\n Scuzati nu sa gasit nici o inregistrare");
  }
  fclose(ec);
  printf("\n\n Apasa Enter pentru a continua");
}

void affteri()
{
    fflush(stdin);
    FILE *tr;
    struct teritor s;
    found = 0;
    tr = fopen("teri.dat","rb");
    printf("_____________________________________________________________________________________________________________________\n\n");
      while(1)
      {
      fread(&s,sizeof(s),1,tr);
      if(feof(tr))
      {
      break;
      }
      printf("\t\t Detalile despre relieful %s\n\n",s.numet, found=1);
        printf("_____________________________________________________________________________________________________________________\n\n");
      printf("\t\tStatul\t\tOrase\t\tSuprafata agricola\tRelieful\t\tClima\n\n");
      printf("\t\t%s\t\t%d\t\t%s\t\t\t%s \t%s\n\n",s.numet,s.nrurbane,s.acgric, s.relief, s.clim);
        printf("\n_____________________________________________________________________________________________________________________\n\n");
      }
      if(found==0)
      {
      printf("\n Scuzati nu sa gasit nici o inregistrare");
      }

      fclose(tr);
printf("\n\nApasa Enter pentru a continua");
}
