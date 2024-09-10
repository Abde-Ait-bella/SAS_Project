#include <stdio.h>
#include <string.h>


    struct Contact{
      char name[25];
      int number;
      char email[25];
    };
    struct Contact contact[100];
    int i, count = 1;
    
    void AddContact(){
     printf("Entrez nom : ");
     scanf("%s", &contact[count].name);
     count++;
    };
    void UpdateContact(){};
    void ShowContact(){
            for(int i=1 ; i <= count; i++){
                // printf(" Livre %d : ", i);
                printf(" Titre : %s", contact[i].name);
        }
    };
    void SearchContact(){};


int main()
{
  
  int n;


  
  do{
    
    printf("******************* \n");
    printf("-1- Ajouter un étudiant \n");
    printf("-2- Modifier un étudiant \n");
    printf("-3- Supprimer un étudiant \n");
    printf("-4- Afficher les détails d'un étudiant \n");
    printf("-5- Calculer la moyenne générale \n");
    printf("-5- Statistiques \n");
    printf("-5- Rechercher un étudiant par \n");
    printf("-5- Trier un étudiant par \n");
    printf("******************* \n");
    
    printf(" ===> choisizsez un service : ");
    scanf("%d", &n);
    
    
    switch(n){
      case 1 :
      AddEtud();
      break;
      
      case 2 :
      UpdateEtud();
      break;
      
      case 3 :
      ShowEtud();
      break;
      
      case 4 :
      SearchEtud();
      break;

        case 5 :
      SearchEtud();
      break;

        case 6 :
      SearchEtud();
      break;
    }
    
  }while( n < 6);

    return 0;
}
