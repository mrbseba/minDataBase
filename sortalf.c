void sortshel ();
void sortbubble ();

int sortmenu()
{
    while(1)
    {
    Beep(750, 300);
    printf("\n_______________Meniu_______________\n\n");
    printf(" 1. Sortarea alfabetica a statelor.\n");
    printf(" 2. Sortrea numerica a oraselor.\n");
    printf(" 0. Iesire.\n");
    printf("___________________________________\n");
    ch = 0;
    printf("\n Introduceti optiunea:");
    scanf("%d",&ch);

    switch (ch)
    {
      case 1: { system("cls"); sortshel(); break;}
      case 2: { system("cls"); sortbubble(); break;}
      case 0: { system("cls"); exit(main()); break;}
      default:printf("\nError 0..2!\n");
    }
    mygetch();
   }
}

//Aici are loc sortatea statelor in ordina alfabetica A->Z
void sortshel ()
{
  FILE *fp;
      struct emp t;
        fp=fopen("mydb.dat","rb");
        fread(&t, sizeof(t), 1, fp);
        y=0;
        while(!feof(fp))
        {
            if(strcmp(t.name, denumire)!=0)
            {
                 strcpy(str[y], t.name);
               y++;
            }
             fread(&t, sizeof(t),1,fp);
        }
        top=y;
        for (int y = 0; y < top; ++y) {
            for (int j = y + 1; j < top; ++j) {
                if (strcmp(str[y], str[j]) > 0) {
                    strcpy(temp, str[y]);
                    strcpy(str[y], str[j]);
                    strcpy(str[j], temp);
                }
            }
        }

  /*   for(y=0; y<top; y++)
        {
          printf("%s\n", str[y]);
        }*/
             fseek(fp, 0, SEEK_SET);
             printf("\n______________________________________________________________________________________________________________________________\n\n");
             printf("\t\t\t\t\t\t Toate detalile despre tara\n");
             printf("______________________________________________________________________________________________________________________________\n\n");
             printf(" ID\tNumele\t\tCapitala\tConducatorul\t\tNr.Populatie\tEconomia \t\tTeritoriul Tari\n\n");
             i = 1;
              for(y=0; y<top; y++)
              {
             fseek(fp, 0, SEEK_SET);
                  fread(&t, sizeof(t),1,fp);
             while(!feof(fp))
             {
                  if(strcmp(t.name, str[y])==0)
                 {
                   //printf("%s.\n",&t.name);
                   printf(" %d\t",t.id);
                   printf("%s\t\t",t.name);
                   printf("%s\t\t",t.capitala);
                   printf("%s\t\t",t.repre);
                   printf("%s Mil\t",t.nrpopula);
                   printf("%s Marde\t\t",t.economia);
                   printf("%s Km^2\n\n",t.teritoriu);
                 }
                  fread(&t, sizeof(t),1,fp);
             }
           }
           printf("______________________________________________________________________________________________________________________________");
        fclose(fp);
printf("\n\nApasa Enter pentru a continua");
}

// AIci are loc sortarea numerica sortbubble
void sortbubble ()
{

  FILE *tr;
struct teritor s;
    int index=0;
    int a[100];
    int k=0;
    float num;

    tr=fopen("teri.dat","rb");

    fread(&s,sizeof(s),1,tr);

    while(!feof(tr))
    {
        if(s.nrurbane > index)
        {
            a[k] = s.nrurbane;
            k=k+1;
        }
         fread(&s, sizeof(s),1,tr);
    }
    n=k;
//Bublle sort
            int f;
    int aux;
             do
             {
                 f=1;
                 for(k=0; k<n-1; k++)
                 {
                 if(a[k]>a[k+1])
                 {
                     aux = a[k];
                     a[k] = a[k+1];
                     a[k+1] = aux;
                     f=0;
                 }
                 }
             }while(!f);
       fseek(tr, 0, SEEK_SET);
    printf("\n\n");
       printf("_____________________________________________________________________________________________________________________\n\n");
       printf("\t\t\t\t\t Detalile despre numarul de orase.\n\n");
       printf("_____________________________________________________________________________________________________________________\n\n");
       printf("\t\tStatul\t\tOrase\t\tSuprafata agricola\tRelieful\t\tClima\n\n\n");
       i = 1;
        for(k=0; k<n; k++)
        {
       fseek(tr, 0, SEEK_SET);
            num=a[k];
       while(1)
       {
         fread(&s, sizeof(s),1,tr);
         if(feof(tr)){
           break;
         }
           if(s.nrurbane==num)
           {

             printf("\t\t%s\t\t%d\t\t%s\t\t\t%s \t%s\n\n",s.numet,s.nrurbane,s.acgric, s.relief, s.clim);
           }
       }
         }
   fclose(tr);
   printf("_____________________________________________________________________________________________________________________\n\n");
}
