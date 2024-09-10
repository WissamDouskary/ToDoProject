#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TACHES 100
#define MAX 100

typedef struct {
    int identifiant;
    char titre[MAX];
    char description[MAX];
    char deadline[MAX];
    int status;
}tach;
    int t=0;
    tach taches[MAX_TACHES];
//1 .ajouter une taches :
void Ajouter_tache(){
    int more;
    int year,month,day;
    printf("ajouter le nombre de taches que vous souhaite ajouter :");
    scanf("%d",&more);
    if (more + t >= MAX_TACHES ){
        printf("la liste des taches est plien !");
        return;
    }
    for(int i = 0 ; i<more; i++){
        printf("l'id de %d tache : %d \n" , i+1,i+1);
        taches[i].identifiant=i+1;
        printf("ecrire le titre de %d tache : ", i+1);
        scanf(" %[^\n]",taches[t].titre);

        printf("ecrire la description de %d tache : ", i+1);
        scanf(" %[^\n]",taches[t].description);
        do {
            printf("Ecrire la deadline de la tache %d (YYYY-MM-DD) : ", i + 1);
            int result = scanf("%d-%d-%d", &year, &month, &day);

            if (result != 3 || year < 2024 || month < 1 || month > 12 || day < 1 || day > 31) {
                printf("Date invalide ! Veuillez entrer une date correcte (YYYY-MM-DD) et plus que 2024.\n");
            } else {
                snprintf(taches[t].deadline, MAX, "%04d-%02d-%02d", year, month, day);
                break;
            }
        } while (1);



        printf("ecrire le status de %d tach ( 1. a realiser, 2 .en cours de realisation, 3 .finalisee ) : ",i+1);
        scanf("%d",&taches[t].status);
        switch(taches[t].status){
        case 1 :
            printf("statut defini sur a realiser. \n");
            break;
        case 2:
            printf("statut defini sur en cours de realisation. \n");
            break;
        case 3 :
            printf("statut defini sur finalisee . \n");
            break;
        default :
            printf("veuillez saisir une tâche variable (1. 2. 3.) ! \n");
            t--;
            continue;


        }

        t++;

    }
    return;
}

// time :
/**void Publicat_Date() {
    time_t now;
    char temps[20];
 nbj

    time(&now);
    struct tm tm_info = *gmtime(&now);
    strftime(temps, sizeof(temps), "%Y-%m-%d %H:%M:%S", &tm_info);
    return;
}*/


//2 .Afficher la liste de toutes les tâches
void Affiche_taches() {
    if(t <= 0) {
        printf("aucune tache trouvee !\n");
    } else {
        printf("\nles taches sont : \n");
        for(int i = 0; i < t; i++) {
            printf("+++++++++++++++++++++++++++++++++++\n");
            printf("la tache %d informations : \n", i + 1);
            printf("id          : %d \n", i+1);
            printf("titre       : %s \n", taches[i].titre);
            printf("description : %s \n", taches[i].description);
            printf("deadline    : %s \n",taches[i].deadline);
            switch(taches[i].status){
        case 1 :
            printf("status      : a realiser \n");
            break;
        case 2 :
            printf("status      : en cours de realisation \n");
            break;
        case 3 :
            printf("status      : finalisee \n");
            break;
        default :
            printf("status      : inconnue ! ");
            break;
            }
            printf("+++++++++++++++++++++++++++++++++++\n");
        }
    }
}
//3 .recherche un task :
void id_search() {
    int search;
    int trouve = 0;

    printf("Tapez l'id de la tache que vous souhaitez rechercher: ");
    scanf("%d",&search);

    for (int i = 0; i < t; i++) {
        if (search == taches[i].identifiant) {
            printf("Resultat trouver :\n");
            printf("la tache %d informations : \n", i + 1);
            printf("id          : %d \n", taches[i].identifiant);
            printf("titre       : %s \n", taches[i].titre);
            printf("description : %s \n", taches[i].description);
            printf("deadline    : %s \n", taches[i].deadline);
            switch (taches[i].status) {
                case 1:
                    printf("status      : a realiser \n");
                    break;
                case 2:
                    printf("status      : en cours de realisation \n");
                    break;
                case 3:
                    printf("status      : finalisee \n");
                    break;
                default:
                    printf("status      : inconnue ! ");
                    break;
            }
            trouve = 1;
            break;
        }
    }
    if (trouve == 0) {
        printf("Aucune tache disponible avec cet id !\n");
    }
}
void name_search(){
    char sea[100];
    int trouve=0;

    printf("Tapez le titre de la tache que vous souhaitez rechercher: ");
    scanf(" %\[^\n]",sea);
    for(int i = 0 ; i < t ; i++ ){
        if(strcmp(sea,taches[i].titre)==0){
            printf("resultat trouver : \n");
            printf("la tache %d informations :\n" , i+1);
            printf("id          : %d \n",taches[i].identifiant);
            printf("titre       : %s \n",taches[i].titre);
            printf("description : %s \n",taches[i].description);
            printf("deadline    : %s \n",taches[i].deadline);
            switch (taches[i].status) {
                case 1:
                    printf("status      : a realiser \n");
                    break;
                case 2:
                    printf("status      : en cours de realisation \n");
                    break;
                case 3:
                    printf("status      : finalisee \n");
                    break;
                default:
                    printf("status      : inconnue ! ");
                    break;
        }
        trouve=1;
        break;
      }
    }
    if(trouve==0){
        printf("Aucune tache disponible avec ce titre!\n");
    }


}
void task_search(){
    int cho;
        printf("1 .Rechercher une tache par son Identifiant. \n");
        printf("2 .Rechercher une tache par son Titre . \n");
        printf("choisis une choix : ");
        scanf("%d",&cho);
        switch(cho){
        case 1 :
            id_search();
            break;
        case 2 :
            name_search();
            break;
        }

}
//4 .modify task:
void Modifier_Task(){
    task_search();
    int set;
    printf("\n\n1 .Modifier la description de ce tache. \n");
    printf("2 .Modifier le statut de ce tache. \n");
    printf("3 .Modifier le deadline de ce tache. \n");
    printf("choisir un choix : ");
    scanf("%d",&set);
    for(int i = 0 ; i < t ; i++){
    switch(set){
case 1:
    printf("ecrire le nouveaux description :");
    scanf("%s",taches[i].description);
    break;
case 2 :
    printf("ecrire le nouveaux statut :");
    scanf("%s",taches[i].status);
    break;
case 3 :
    printf("ecrire le neuveau deadline (YYYY-MM-DD) :");
    scanf("%s",taches[i].deadline);
    break;
    }
    }
}

int main()
{
    int choice;
    do{
        printf("Menu :----------------------------\n");
        printf("1 .ajouter une nouvelle tache. \n");
        printf("2 .Afficher la liste de toutes les taches. \n");
        printf("3 .Rechercher du taches. \n");
        printf("4 .Modifier la tache. \n");
        printf("0 .Quittez ! \n");
        printf("-----------------------------------\n");
        printf("choisir une choix :");
        scanf("%d",&choice);
        switch(choice){
    case 1:
        Ajouter_tache();
        break;
    case 2:
        Affiche_taches();
        break;
    case 3 :
        task_search();
        break;
    case 4 :
        Modifier_Task();
        break;







        }

    }while(choice!=0);
    return 0;
}
