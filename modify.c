void domodmeniu ();
void modpopl ();
void modecon ();
void modteri ();
void modify ();

void upmodmeiu ()
{
  while(1)
  {
    Beep(750, 300);
    printf("\n___________________Meniu___________________\n\n");
    printf(" 1. Modifica datele despre un stat.\n");
    printf(" 2. Modifica date despre datele aditionale.\n");
    printf(" 0. Iesire.\n");
    printf("___________________________________________\n");
    printf("\n Introduti aptiunea:");
    ch = 0;
    scanf("%d",&ch);
    switch (ch)
    {
      //Aici are loc modificarea datelor despre stat
  case 1: {
    system("cls");
    printf("\n\n Introduceti numarul necesar necesar de modificari:");
    n = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     modify();
    }
   printf("Apasa Enter pentru a continua\n");
    break;
    }
    //Aici are loc apelul submeniului
  case 2: { system("cls"); domodmeniu(); break;}
    //Aici are loc iesirea din fiseir
  case 0: { system("cls"); exit(main()); break;}
      default:printf("Error 0..2!!\n");
    }
    mygetch();
  }
}

void domodmeniu ()
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
      // Aici are loc apelul functii pentru meodificarea datelor despre populatie
     case 1:
     {
       system("cls");
       printf("\n\n Introduceti numarul necesar de modificari:");
       n = 0;
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
       modpopl ();
       }
       printf("Apasa Enter pentru a continua\n");
       break;
     }
     // Aici are loc apelul functii pentru meodificarea datelor economice
  case 2: {
     system("cls");
     printf("\n\n Introduceti numarul necesar necesar de modificari:");
     n = 0;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
     modecon();
     }
     printf("Apasa Enter pentru a continua\n");
     break;
     }
     //Aicia are loc apelul functi de modificarea a datelor depsre relief
  case 3: {
     system("cls");
     printf("\n\n Introduceti numarul necesar necesar de modificari:");
     n = 0;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
     modteri ();
     }
     printf("Apasa Enter pentru a continua\n");
     break;
    }
    //Aici are loc returnare la mediul precedent
  case 0: { system("cls"); upmodmeiu (); break;}
     default:printf("Error 0...3!!\n");
   }
   mygetch();
   }
}
//Aici este functia pentru modificarea datelor despre stat
void modify()
{
FILE *fp,*fp1;
struct emp t,t1;
 found =0;

fp=fopen("mydb.dat","rb");
fp1=fopen("temp.dat","wb");
printf("\nIntroduce ID care necesita modificat:");
id =0;
scanf("%d",&id);
while(1)
{
fread(&t,sizeof(t),1,fp);
if(feof(fp))
{
break;
}

if(t.id==id)
{
found=1;
fflush(stdin);

printf("ID curent- %d",t.id);
printf("\nModifica ID tari:");
scanf("%d",&t.id);
printf("\n\n");

printf("Denumire curenta a statului - %s",t.name);
printf("\nModifica denumirea tari:");
scanf("%s",&t.name);
printf("\n");

printf("Denumire curenta a capitale - %s",t.capitala);
printf("\nModifica denumirea capitalei:");
scanf("%s",&t.capitala);
printf("\n");

printf("Denumirea curenta a reprezentantului - %s",t.repre);
printf("\nModificatia numele conducatorului statului:");
scanf("%s",&t1.repre );
printf("\n");

printf("Numarul curent a populatie - %s",t.nrpopula);
printf("\nModifica numarul popopulatie:");
scanf("%s",&t.nrpopula);
printf("\n");

printf("PIB curent - %s",t.economia);
printf("\nModifca PIB tari:");
scanf("%s",&t.economia);
printf("\n");

printf("Marimea curenta a teritoriul tarii - %s",t.teritoriu);
printf("\nIntroduceti noile date despre marimea teritoriul tari:");
scanf("%s",&t.teritoriu);
printf("\n");

fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);
if(found==0)
{
printf("Scuzati, nu sunt gasite inregistrari\n\n");
}
else
{
fp=fopen("mydb.dat","wb");
fp1=fopen("temp.dat","rb");
while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}
}
fclose(fp);
fclose(fp1);
printf("Apasa Enter pentru a continua\n");
}

//Aici este functia pentru modifcare a datelor despre populatie
void modpopl ()
{
  FILE *po,*po1;
  struct populat p, p1;
  int id, found=0;
  char poname[30];
  po=fopen("popl.dat","rb");
  po1=fopen("mptemp.dat","wb");

  printf("\nIntroduce denumirea statului care necesita modificat:");
  scanf("%s",&poname);
  while(1)
  {
  fread(&p,sizeof(p),1,po);

  if(feof(po))
  {
  break;
  }
  if(strcmp(poname,p.numep)==0)
  {
  fflush(stdin);
  found=1;
  printf("\n _____Modificarea datele despre populatie_______________________\n\n");
  printf(" Denumirea curenta a statului - %s",p.numep);
  printf("\n Modifica denumirea statului:");
  scanf("%s",&p.numep);

  printf("\n Curenta reta a natalitatii - %s",p.natal);
  printf("\n Modifica rata natalitatii:");
  scanf("%s",&p.natal);

  printf("\n Curenta rata a mortalitatii - %s",p.mortal);
  printf("\n Modifica rata mortalitatii:");
  scanf("%s",&p.mortal);

  printf("\n Speranta de viata curenta - %s",p.varsta);
  printf("\n Modificarea spernatei de viata:");
  scanf("%s",&p.varsta);

  printf("\n Limba curenta - %s",p.limba);
  printf("\n Modifcarea limbii:");
  scanf("%s",&p.limba);
  fwrite(&p,sizeof(p),1,po1);
  }
  else
  {
  fwrite(&p,sizeof(p),1,po1);
  }
  }
  fclose(po);
  fclose(po1);

  if(found==0)
  {
  printf("Scuzati, nu sunt gasite inregistrari\n\n");
  }
  else
  {
  po=fopen("popl.dat","wb");
  po1=fopen("mptemp.dat","rb");

  while(1)
  {
  fread(&p,sizeof(p),1,po1);

  if(feof(po1))
  {
  break;
  }
  fwrite(&p,sizeof(p),1,po);
  }

  }
  fclose(po);
  fclose(po1);
  printf("Apasa Enter pentru a continua\n");
}
//Aici este functia de modificarea a datelor despre economie
void modecon ()
{
  FILE *ec,*ec1;
  struct econom e, e1;
  int id, found=0;
  char ecname[30];
  ec=fopen("eco.dat","rb");
  ec1=fopen("metemp.dat","wb");
  printf("\nIntroduce denumirea statului care necesita modificat:");
  scanf("%s",&ecname);
  while(1)
  {
  fread(&e,sizeof(e),1,ec);

  if(feof(ec))
  {
  break;
  }
  if(strcmp(ecname,e.numee)==0)
  {
  fflush(stdin);
  found=1;
  printf("\n _____Modificarea datele despre economie_______________________\n");
  printf(" Denumirea statului curent - %s",&e.numee);
  printf("\n Modifica denumirea statului:");
  scanf("%s",&e.numee);

  printf("\n Exeportul curent - %s\n",&e.export);
  printf(" Modifica exportul:");
  scanf("%s",&e.export);

  printf("\n Improtul curent - %s\n",&e.import);
  printf(" Modifica improtul:");
  scanf("%s",&e.import);

  printf("\n Salariru mediu curent - %s\n",&e.salmediu);
  printf(" Modificarea salariu mediu:");
  scanf("%s",&e.salmediu);

  printf("\n Industria prima curenta - %s\n",&e.induprin);
  printf(" Modifcarea industria prima:");
  scanf("%s",&e.induprin);
  fwrite(&e,sizeof(e),1,ec1);
  }
  else
  {
  fwrite(&e,sizeof(e),1,ec1);
  }
  }

  fclose(ec);
  fclose(ec1);

  if(found==0)
  {
  printf("Scuzati, nu sunt gasite inregistrari\n\n");
  }
  else
  {
  ec=fopen("eco.dat","wb");
  ec1=fopen("metemp.dat","rb");

  while(1)
  {
  fread(&e,sizeof(e),1,ec1);

  if(feof(ec1))
  {
  break;
  }
  fwrite(&e,sizeof(e),1,ec);
  }

  }
  fclose(ec);
  fclose(ec1);

}
//Aici este functia de modificaree a datelor despre teritoriu
void modteri ()
{
  FILE *tr,*tr1;
  struct teritor s,s1;
  int id,found=0;
  char tername[30];
  tr=fopen("teri.dat","rb");
  tr1=fopen("tetemp.dat","wb");
  printf("\n Introduce denumirea statului care necesita modificat:");
  scanf("%s",&tername);
  while(1)
  {
  fread(&s,sizeof(s),1,tr);

  if(feof(tr))
  {
  break;
  }
  if(strcmp(tername,s.numet)==0)
  {
  found=1;
  fflush(stdin);
  printf("\n_____Modificarea datele despre suprafta terestra_______________________\n");

  printf("\n Curenta denumire a statului - %s\n",s.numet);
  printf(" Modifica denumirea statului:");
  scanf("%s",&s.numet);

  printf("\n Curentele date despre relief - %s\n",s.relief);
  printf(" Modifica detelii despre relief:");
  scanf("%s",&s.relief);

  printf("\n Curentele date despre clima - %s\n",s.clim);
  printf(" Modifica detali despre clima:");
  scanf("%s",&s.clim);

  printf("\n Curentele date despre suprafata agricola - %s\n",s.acgric);
  printf(" Modifica detali despre suprafata agricola:");
  scanf("%s",&s.acgric);

  printf("\n Numarul curent despre asezarile urbane - %d\n",s.nrurbane);
  printf(" Modifca detalii despre asezariel urbane:");
  scanf("%d",&s.nrurbane);

  fwrite(&s,sizeof(s),1,tr1);
  }
  else
  {
  fwrite(&s,sizeof(s),1,tr1);
  }
  }

  fclose(tr);
  fclose(tr1);

  if(found==0)
  {
  printf("Scuzati, nu sunt gasite inregistrari\n\n");
  }
  else
  {
  tr=fopen("teri.dat","wb");
  tr1=fopen("tetemp.dat","rb");

  while(1)
  {
  fread(&s,sizeof(s),1,tr1);

  if(feof(tr1))
  {
  break;
  }
  fwrite(&s,sizeof(s),1,tr);
  }

  }
  fclose(tr);
  fclose(tr1);

}
