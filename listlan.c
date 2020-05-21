// Aici are loc adaugarea datelor
nod *adauga(nod*prim, char *nume,  char *repre, char *capitala)
{
  nod *q,*p;
  p=(nod*)malloc(sizeof(nod));
  p->name=(char*)malloc(strlen(nume)+1);
    p->repre=(char*)malloc(strlen(repre)+1);
      p->capitala=(char*)malloc(strlen(capitala)+1);
  strcpy(p->name,nume);
  strcpy(p->repre,repre);
  strcpy(p->capitala,capitala);
  p->urm=NULL;
  if(p==NULL)
  {
  printf("Eroare la alocare!");
  exit(0);
  }
  if (p->name==NULL)
  {
    printf("Eroare la alocare pentru denumire!");
    exit(0);
  }
  if (p->repre==NULL)
  {
    printf("Eroare la alocare pentru reprezentant!");
    exit(0);
  }
  if(p->capitala==NULL)
  {
    printf("Eroare la alocare pentru capitala!");
    exit(0);
  }

  if(prim==NULL)
  return p;
  else if(strcmp(prim->name,p->name)>0)
  {
    p->urm=prim;
    return p;
  }
  else
  {
      q=prim;
      while(q->urm!=NULL && strcmp(q->urm->name,p->name)<0)
      q=q->urm;
      p->urm=q->urm;
      q->urm=p;
      return prim;
  }
}

//Aici are loc afisarea datelor
void afisare(nod *prim)
{
  nod *q;
  q=prim;
  printf("\n______STATELE____________________________\n\n");
  printf(" Denumirea\tReprezentantul\tCapitala\n");
  while(q!=NULL)
  {
    printf("\n %s\t\t%s\t%s",q->name, q->repre, q->capitala);
    q=q->urm;
  }
  printf("\n_________________________________________\n");
}
//Aici are loc afisarea
nod* cautare(nod *prim, char *nume)
{
   nod *q;
   q=prim;
   while(q!=NULL && strcmp(q->name,nume)!=0)
   q=q->urm;
   return q;
}

//Aici are loc stergerea datelor
nod* stergere(nod *prim,char *nume)
{
  nod *q,*p;
  if(prim!=NULL)
{
  if(strcmp(prim->name,nume)==0)
  {
    q=prim;
    prim=prim->urm;
    free(q->name);
    free(q);
    return prim;
  }
    q=prim;
  while(q->urm!=NULL && strcmp(q->urm->name,nume)!=0)
  q=q->urm;
  if(q->urm!=NULL && strcmp(q->urm->name,nume)==0)
  {
    p=q->urm;
    q->urm=q->urm->urm;
    free(p->name);
    free(p);
  }
  return prim;
}
  else
  return prim;
}

//Aici este mainul
void list ()
{
  nod *prim,*p;
prim=NULL;
while(1)
{printf("___________MENIU_____________________\n");
printf("\n 1. Introducerea unui stat.");
printf("\n 2. Afisarea alfabetica a statelor.");
printf("\n 3. Cautarea unui stat.");
printf("\n 4. Stergerea unui stat.");
printf("\n 0. Iesire.\n");
printf("_____________________________________\n");
printf("Optiunea -->");
ch = 0;
scanf("%d",&ch);
fflush(stdin);
switch(ch)
{
case 1:
{
  system("cls");
  printf("\n Introduce numarul necesar de inregisrari:");
  n =0;
  scanf("%d",&n);
  fflush(stdin);
  for(i=0;i<n;i++)
  {
    printf("\n Inregisrarea %d\n\n",i+1);
    fflush(stdin);
    puts(" Denumirea statului: ");
    gets(nume);
    puts(" Introduce numele reprezentantului: ");
    gets(repre);
    puts(" Introduce denumirea capitalei: ");
    gets(capitala);
    prim=adauga(prim, nume, repre, capitala);
    }
  break;
}
case 2:
{
  system("cls");
  afisare(prim);
  break;
}
  case 3:
  {
    system("cls");
    printf("Introduceti denumirea statului:");
    gets(nume);
    p=cautare(prim,nume);
    if(p==NULL){
    printf("Statul nu a fost gasit in lista");
    printf("Apasa Enter pentru a continua...\n");
    }
    else
    {
    printf("Datele despre statul cautat:\n");
    printf("______________________________________________________________________\n");
    printf("\n | Statul: %s | Reprezentantul: %s | Capitala: %s |\n", p->name, p->repre, p->capitala);
    printf("______________________________________________________________________\n\n");
    printf("Apasa Enter pentru a continua...\n");
    }
    break;
  }
  case 4:
  {
    system("cls");
    printf("Introduceti denumirea statului:");
    gets(nume);
    prim=stergere(prim,nume);
    afisare(prim);
    printf("Apasa Enter pentru a continua...\n");
  break;
  }
  case 0:
  {
    system("cls");
    exit(main());
  }
  default:printf("\n0..4!");
  }
  getch();
  }
  }
