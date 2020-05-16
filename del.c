//Fiserele de stergere
void sdemeniu ();
void delpop ();
void delecon ();
void delterit ();
void del ();
//Meniu principal de stergere
int demeniu ()
{
  while(1)
  {
  Beep(750, 300);
  printf("\n_______________Meniu_______________\n\n");
  printf(" 1. Stergerea state.\n");
  printf(" 2. Stergerea detali despre state.\n");
  printf(" 0. Iesire.\n");
  printf("___________________________________\n");
  ch = 0;
  printf("\n Introduceti optiunea:");
  scanf("%d",&ch);
  switch (ch)
  {
    //Aici are loc steregerea unui stat
case 1:
  {
  system("cls");
  printf("\n\n Introduceti numarul necesar de stergere:");
  n = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    del();
  }
  printf("Apasa Enter pentru a continua\n");
  break;
  }
  //Aici are loc redictonarea catre submeniu
case 2: { system("cls"); sdemeniu (); break;}
  //Aici are loc iesirea din fisier
case 0: { system("cls"); exit(main()); break;}
default:printf("\nError 0..2!\n");
  }
  mygetch();
  }
}
//Submeniu de stergere
void sdemeniu ()
{
  while(1)
  {
     Beep(750, 300);
  printf("\n_______________Meniu_______________\n\n");
  printf(" 1. Stergerea detali despre populatie.\n");
  printf(" 2. Stergerea detali despre econommie.\n");
  printf(" 3. Stergerea detali despre relief.\n");
  printf(" 0. Iesire.\n");
  printf("___________________________________\n");
  ch =0;
  printf("\n Introdoceti optiunea:");
  scanf("%d",&ch);
  switch (ch)
  {
      //Aici are loc stergerea datelor despre populatie
case 1:
  {
  system("cls");
  printf("\n\n Introduceti numarul necesar de stergere:");
  n = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  delpop();
  }
  printf("Apasa Enter pentru a continua\n");
  break;
  }
    // Aici are loc stergerea datelor despre economie
case 2:
  {
  system("cls");
  printf("\n\n Introduceti numarul necesar de stergere:");
  n = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  delecon();
  }
  printf("Apasa Enter pentru a continua\n");
  break;
  }
   //Aici are loc stergerea datelor despre relief
case 3: {
  system("cls");
  printf("\n\n Introduceti numarul necesar de stergere:");
  n = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  delterit();
  }
  printf("Apasa Enter pentru a continua\n");
  break;
  }
case 0: { system("cls"); demeniu();}
    default:printf("\nError 0..3!");
  }
  mygetch();
  }
}

//Fuctia pentru stergerea datelor despre un stat
void del()
{
FILE *fp,*fp1;
struct emp t,t1;
int id,found=0;

fp=fopen("mydb.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nIntrdoceti ID care e nevoie de sters:");
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
printf("Scuzati nu sunt gasite inregistrari\n\n");
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

}

//Functia pentru stergerea datelor desrep populatie
void delpop ()
{
  FILE *po,*po1;
  struct populat p, p1;
  found = 0;
  n=0;
  char delpop[30];
  po=fopen("popl.dat","rb");
  po1=fopen("mptemp.dat","wb");
  printf("\nIntrdoceti denumirea statului care necesita sters:");
  scanf("%s",&delpop);
  while(1)
  {
  fread(&p,sizeof(p),1,po);

  if(feof(po))
  {
  break;
  }
  if(strcmp(delpop,p.numep)==0)
  {
  found=1;
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
  printf("Scuzati nu sunt gasite inregistrari\n\n");
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

}
//Functia pentru stergerea datelor despre economie
void delecon ()
{

  FILE *ec,*ec1;
  struct econom e, e1;
  found = 0;
  char ecname[30];
  ec=fopen("eco.dat","rb");
  ec1=fopen("metemp.dat","wb");
  printf("\nIntrdoceti denumirea statului necesar de sters:");
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
  found=1;
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
  printf("Scuzati nu sunt gasite inregistrari\n\n");
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
//Fucntia pentru stergerea datelor despre relief
void delterit ()
{
  FILE *tr,*tr1;
  struct teritor s, s1;
  found = 0;
  char tername[30];
  tr=fopen("teri.dat","rb");
  tr1=fopen("tetemp.dat","wb");

  printf("\nIntrdoceti denumirea statului necesar de sters:");
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
  printf("Scuzati nu sunt gasite inregistrari\n\n");
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
