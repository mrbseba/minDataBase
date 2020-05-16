//Aici este functia de afisarea a tuturor date
void displayAll()
{
FILE *fp, *po, *ec, *tr;
struct emp t;
struct populat p;
struct econom e;
struct teritor s;
fp=fopen("mydb.dat","rb");
po = fopen("popl.dat","rb");
ec = fopen ("eco.dat","rb");
tr = fopen("teri.dat","rb");


while(1)
{
fread(&t,sizeof(t),1,fp);
fread(&p,sizeof(p),1,po);
fread(&e,sizeof(e),1,ec);
fread(&s,sizeof(s),1,tr);
if(feof(fp))
{
break;
}
printf("\n______________________________________________________________________________________________________________________________\n\n");
printf("\t\t\t\t\t\t Toate detalile despre tara\n");
printf("______________________________________________________________________________________________________________________________\n\n");

printf(" ID\tNumele\t\tCapitala\tConducatorul\t\tNr.Populatie\tEconomia \t\tTeritoriul Tari\n\n");


printf(" %d\t",t.id);
printf("%s\t\t",t.name);
printf("%s\t\t",t.capitala);
printf("%s\t\t",t.repre);
printf("%s Mil\t",t.nrpopula);
printf("%s Marde\t\t",t.economia);
printf("%s Km^2\n\n",t.teritoriu);
printf("__________Populatia___________________________________________________________________________________________________________\n\n");
printf("\t\tStatul\t\tNatalitatea\tMortalitatea\t\tSperanta de viata\tLimba\n\n");
printf("\t\t%s\t\t%s\t\t%s\t\t\t%s ani.\t\t%s\n\n",p.numep, p.natal, p.mortal, p.varsta, p.limba);
printf("__________Economia___________________________________________________________________________________________________________\n\n");
printf("\t\tStatul\t\tExportul\t\tImporul\t\t\tSalariu mediu\t\tIdustria principala\n\n");
printf("\t\t%s\t\t%s Marde $\t\t%s Marde $\t\t%s $\t\t\t%s\n\n",e.numee, e.export, e.import, e.salmediu, e.induprin);
printf("__________Teritoriu___________________________________________________________________________________________________________\n\n");
printf("\t\tStatul\t\tOrase\t\tSuprafata agricola\tRelieful\t\tClima\n\n");
printf("\t\t%s\t\t%d\t\t%s\t\t\t%s\t%s\n\n",s.numet,s.nrurbane,s.acgric, s.relief, s.clim);
}
printf("______________________________________________________________________________________________________________________________\n\n");
fclose(fp);
fclose(po);
fclose(ec);
fclose(tr);
printf("Apasa Enter pentru a continua\n");
}
