void idiul ();
void denum ();
void cond ();
void capit ();
void speranta ();
void pibul ();
void supraf ();


void upmodelem ()
{
  while(1)
  {
    Beep(750, 300);
    printf("\n___________________Meniu___________________\n\n");
    printf(" 1. Modificarea idiul.\n");
    printf(" 2. Modificarea denumirea statului.\n");
    printf(" 3. Modifica numele reprezentantului.\n");
    printf(" 4. Modifica denumirea capitalei.\n");
    printf(" 5. Modifica numarului populatie.\n");
    printf(" 6. Modifica PIB-ul.\n");
    printf(" 7. Modifica suprafata teritoriului.\n");
    printf(" 0. Iesire.\n");
    printf("___________________________________________\n");
    printf("\n Introduti aptiunea:");
    ch = 0;
    scanf("%d",&ch);
    switch (ch)
    {
      //Aici are loc modificarea datelor despre stat
  case 1: {system("cls"); idiul (); break;}
  case 2: {system("cls"); denum (); break;}
  case 3: {system("cls"); cond (); break;}
  case 4: {system("cls"); capit (); break;}
  case 5: {system("cls"); speranta (); break;}
  case 6: {system("cls"); pibul (); break;}
  case 7: {system("cls"); supraf (); break;}
  case 0: {system("cls"); exit(main());break;}
      default:printf("Error 0..2!!\n");
    }
    mygetch();
  }
}
//Aici are loc modifcarea idiului.
void idiul ()
{

  FILE *fp,*fp1;
  struct emp t,t1;
   found =0;
  fp=fopen("mydb.dat","rb");
  fp1=fopen("temp.dat","wb");
  printf("\n\n Introduce ID care necesita modificat:");
  id = 0;
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
      printf("\n\n Modifica ID tari:");
      scanf("%d",&t.id);
      printf("\n\n Datele au fost modificate cu success!\n");
      printf("\n Apasa Enter pentru a continua");
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
}
//Aici are loc modificarea denumirea statului
void denum()
{
  FILE *fp,*fp1;
  struct emp t,t1;
  found =0;
  fp=fopen("mydb.dat","rb");
  fp1=fopen("temp.dat","wb");
  printf("\nIntroduce ID care necesita modificat:");
  id = 0;
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
        printf("Denumire curenta a statului - %s",t.name);
        printf("\nModifica denumirea tari:");
        scanf("%s",&t.name);
        printf("\n\n Datele au fost modificate cu success!\n");
        printf("\n Apasa Enter pentru a continua");
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

}
//Aici are loc midificarea numele reprezentantului
void cond ()
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

  printf(" Denumirea curenta a reprezentantului - %s",t.repre);
  printf("\n Modificatia numele conducatorului statului:");
  scanf("%s",&t.repre );
  printf("\n\n Datele au fost modificate cu success!\n");
  printf("\n Apasa Enter pentru a continua");

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
  printf(" Scuzati, nu sunt gasite inregistrari\n\n");
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
//Aici are loc modificarea denumirei capitalei
void capit ()
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


  printf("Denumire curenta a capitale - %s",t.capitala);
  printf("\nModifica denumirea capitalei:");
  scanf("%s",&t.capitala);
  printf("\n\n Datele au fost modificate cu success!\n");
  printf("\n Apasa Enter pentru a continua");

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

}
//Aici are loc mofificarea numarului popopulatie
void speranta ()
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

  printf("Numarul curent a populatie - %s",t.nrpopula);
  printf("\nModifica numarul popopulatie:");
  scanf("%s",&t.nrpopula);
  printf("\n\n Datele au fost modificate cu success!\n");
  printf("\n Apasa Enter pentru a continua");
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

}
//Aici are loc modificarea pibului
void pibul ()
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
  printf("PIB curent - %s",t.economia);
  printf("\nModifca PIB tari:");
  scanf("%s",&t.economia);
  printf("\n\n Datele au fost modificate cu success!\n");
  printf("\n Apasa Enter pentru a continua");

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


}
//Aici are loc modificarea suprafata teristra a statului
void supraf ()
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

  printf("Marimea curenta a teritoriul tarii - %s",t.teritoriu);
  printf("\nIntroduceti noile date despre marimea teritoriul tari:");
  scanf("%s",&t.teritoriu);
  printf("\n\n Datele au fost modificate cu success!\n");
  printf("\n Apasa Enter pentru a continua");

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

}
