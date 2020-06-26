
//Aici este declarat structura pentru liste
struct linked_list
{
    int numar;
    struct linked_list *mru;
};
typedef struct linked_list node;
node *head = NULL, *last = NULL;


void adsfarsit(int value)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));
    temp_node->numar=value;
    temp_node->mru=NULL;
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->mru=temp_node;
        last=temp_node;
    }
}
void crearelista()
{
    int val,i,n;
    printf("Indica nr de noduri: ");
    scanf("%d",&n);
    for(i=0; i < n; i++)
    {
    p:
    printf("Idul pentru nodul %d -> ",i+1);
    scanf("%d",&val);
        if(val>contor)
        {
            printf("Valoarea nu exista in lista!\n");
            goto p;
        }
    adsfarsit(val);
    }
    }
void adinceput(int value)
{
    node *temp_node = (node *) malloc(sizeof(node));
    temp_node->numar=value;
    temp_node->mru = head;
    head = temp_node;
}
void addupa(int key, int value)
{
    node *myNode = head;
    int flag = 0;
    while(myNode!=NULL)
    {
        if(myNode->numar==key)
        {
            node *newNode = (node *) malloc(sizeof(node));
            newNode->numar = value;
            newNode->mru = myNode->mru;
            myNode->mru = newNode;
            printf("%d este introdus dupa %d\n", value, key);
            flag = 1;
            break;
        }
        else
            myNode = myNode->mru;
    }
    if(flag==0)
    {
        printf("Elementul nu a fost gasit!\n");
    }
}
void stergenumar(int value)
{
    node *myNode = head, *previous=NULL;
    int flag = 0;
q:
    printf("\nIntroduceti nodul pe care doriti sa-l stergeti: ");
    scanf("%d", &value);
    if(value>contor)
    {
        printf("Valoarea nu exista in lista!\n");
        goto q;
    }
    while(myNode!=NULL)
    {
        if(myNode->numar==value)
        {
            if(previous==NULL)
                head = myNode->mru;
            else
            previous->mru = myNode->mru;
            printf("Nodul %d a fost sters din lista\n", value);
            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }
        previous = myNode;
        myNode = myNode->mru;
    }
    if(flag==0)
        printf("Nodul nu a fost gasit!\n");
}
void afisarelista()
{
    FILE *fp;
    struct emp t;
    int abp[100];
    int y=0;
    int stop;
    node *myList;
    myList = head;
    while(myList!=NULL)
    {
        abp[y] = myList->numar;
        myList = myList->mru;
        y++;
    }
    stop = y ;
    printf("\n\n\n");
    fp=fopen("mydb.dat", "rb");

    printf("                                               LISTA STATELOR \n");
    printf(" -----------------------------------------------------------------------------------------------------------\n");
    printf(" |  ID  |   Denumire   |   Reprezentant       |  Capitala   |  Nr. Populatie   |  PIB       |  Suprafata   |\n");
    printf(" -----------------------------------------------------------------------------------------------------------\n");
    for(y=0; y<stop; y++)
    {
        i = 1;
      fseek(fp, 0, SEEK_SET);
      fread(&t, sizeof(t), 1, fp);

      while(!feof(fp))
      {
          if(abp[y] == i)
          {

              printf(" |%4d  |   %-10s |   %-18s |  %-10s |  %-15s |  %-8s  |  %-10s  |\n",t.id, t.name, t.repre, t.capitala, t.nrpopula, t.economia, t.teritoriu);
          i++;
        printf(" -----------------------------------------------------------------------------------------------------------\n");
          }
                i++;
                 fread(&t, sizeof(t),1,fp);
      }
    }
    fclose(fp);
}

void listenod()
{
      FILE *fp;
      fp=fopen("mydb.dat", "rb");
      struct emp t;
      printf("\n\n");
      printf("                                               LISTA STATELOR \n");
      printf(" -----------------------------------------------------------------------------------------------------------\n");
      printf(" |  ID  |   Denumire   |   Reprezentant       |  Capitala   |  Nr. Populatie   |  PIB       |  Suprafata   |\n");
      printf(" -----------------------------------------------------------------------------------------------------------\n");
      i = 1;
      fread(&t, sizeof(t), 1, fp);

      while(!feof(fp))
      {
          printf(" |%4d  |   %-10s |   %-18s |  %-10s |  %-15s |  %-8s  |  %-10s  |\n",t.id, t.name, t.repre, t.capitala, t.nrpopula, t.economia, t.teritoriu);
          i++;
          fread(&t, sizeof(t),1,fp);
          printf(" -----------------------------------------------------------------------------------------------------------\n");
      }
    contor = i-1;
    fclose(fp);

       while(1)
       {
        printf("\n\n");
        printf("          _______________________________   \n");
        printf("          |        LISTE SI NODURI      |   \n");
        printf("          |    1  - Creare lista        |   \n");
        printf("          |    2  - Afisare lista       |   \n");
        printf("          |    3  - Adaugare la inceput |   \n");
        printf("          |    4  - Adaugare la sfarsit |   \n");
        printf("          |    5  - Adaugare in mijloc  |   \n");
        printf("          |    6  - Sterge nod          |   \n");
        printf("          |    0  - Iesire              |   \n");
        printf("          -------------------------------   \n");
        printf("          ----> ");
        scanf("%d",&x);
    switch (x)
    {
        case 1:
        crearelista();
        break;

        case 2:
        afisarelista();
        break;

        case 3:
        o:
        printf("Nod inceput: ");
        scanf("%d", &value);
            if(value>contor)
            {
                printf("Valoarea nu exista in lista!\n");
                goto o;
            }
        adinceput(value);
        break;

        case 4:
        u:
        printf("Nod sfarsit: ");
        scanf("%d", &value);
            if(value>contor)
            {
                printf("Valoarea nu exista in lista!\n");
                goto u;
            }
        adsfarsit(value);
        break;


        case 5:
        printf("\nNodul dupa care doriti sa introduceti alt nod: ");
        scanf("%d", &key);
        printf("\nIntroduceti un nod dupa %d:  ", key);
        scanf("%d", &value);
        addupa(key, value);
        break;


        case 6:
        stergenumar(value);
        break;
        case 0: exit(main());
        break;
        }
}
}
