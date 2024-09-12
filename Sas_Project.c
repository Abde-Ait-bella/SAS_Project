#include <stdio.h>
#include <string.h>

struct Etudient
{
  int choix;
  int id;
  int counteurId;
  char nom[25];
  char prenom[25];
  char dateNaissance[25];
  char departement[25];
  int note_generale;
};

int numberEtud = 0;
int countId = 0;
int i;

struct Etudient etudient[100];
struct Etudient reserve;
struct Etudient temp[100];

void AddEtud()
{
  printf("======= Ajouter un Etudient ======= \n");
  etudient[numberEtud].id = countId;
  printf("Entrez nom : ");
  scanf("%s", &etudient[numberEtud].nom);
  printf("Entrez prenom : ");
  scanf("%s", &etudient[numberEtud].prenom);
  printf("Entrez dateNaissance : ");
  scanf("%s", &etudient[numberEtud].dateNaissance);
  printf("Entrez departement : ");
  scanf("%s", &etudient[numberEtud].departement);
  printf("Entrez la note generale : ");
  scanf("%d", &etudient[numberEtud].note_generale);

  countId += 1;
  numberEtud++;
  printf("============================== \n");
}

void ShowAll()
{
  printf("=============================================== La liste des Etudients =============================================== \n");
  for (int i = 0; i < numberEtud; i++)
  {
    printf(" Etudient %d : ", i + 1);
    printf(" Id : %d |", etudient[i].id);
    printf(" Nom : %s |", etudient[i].nom);
    printf(" Prenom : %s |", etudient[i].prenom);
    printf(" Date de Naissance : %s DH |", etudient[i].dateNaissance);
    printf(" Departement : %s |", etudient[i].departement);
    printf(" Note generale : %d \n", etudient[i].note_generale);
  }
  printf("====================================================================================================================== \n");
};

int Search_id(int id)
{
  for (i = 0; i < numberEtud; i++)
  {
    if (id == etudient[i].id)
    {
      return i;
    }
  }
  return -1;
};

int Search_name(char searchNom[])
{
  printf("search : %s ", searchNom);
  for (i = 0; i < numberEtud; i++)
  {
    if (strcmp(etudient[i].nom, searchNom) == 0)
    {
      return i;
    }
  }
  return -1;
};

int Search_dep(char searchDep[])
{
  printf("%s", searchDep);
  for (i = 0; i < numberEtud; i++)
  {
    if (strcmp(etudient[i].departement, searchDep) == 0)
    {
      return i;
      break;
    }
    return -1;
  }
};

void ShowEtud(int index)
{
  printf("================================> Etudient releve <========================= \n");
  printf(" Etudient %d : ", index + 1);
  printf(" Id : %d |", etudient[index].id);
  printf(" Nom : %s |", etudient[index].nom);
  printf(" Prenom : %s |", etudient[index].prenom);
  printf(" Date de Naissance : %s DH |", etudient[index].dateNaissance);
  printf(" Departement : %s |", etudient[index].departement);
  printf(" Note generale : %d \n", etudient[index].note_generale);
  printf("========================================================================== \n");
};

void menuShowing()
{
  printf("-1- Rechercher un etudiant par son nom \n");
  printf("-2- Afficher la liste des etudiants inscrits dans un departement specifique \n");
};

void SearchEtud()
{
  int choix;
  int index;
  char SearchName[25];
  char SearchDep[25];
  printf("======= La recherche ======= \n");
  menuShowing();
  printf("Saisie le choix : ");
  scanf("%d", &choix);

  do
  {
    switch (choix)
    {
    case 1:
      choix = 0;
      printf("Entrer le nom : ");
      scanf(" %[^\n]", &SearchName);
      index = Search_name(SearchName);

      if (index != -1)
      {
        ShowEtud(index);
        break;
      }
      else
      {
        printf("==> Desoler Livre non releve !!! <==");
      }
      break;

    case 2:
      choix = 0;
      printf("Entrer le departement : ");
      scanf(" %[^\n]", &SearchDep);
      index = Search_dep(SearchDep);

      if (index != -1)
      {
        ShowEtud(index);
      }
      else
      {
        printf("==> Desoler Livre non releve !!! <==");
      }

      break;

    default:
      printf("saisie les choix de recherche !! \n\n");
      break;
    }
    printf("============================== \n");

  } while (choix < 3 && choix > 0);
};

void UpdateEtud()
{
  int searchId, newNom[25], newPrenom[25], newdateNaissance[25], newDepartement[25], newNotegenerale;
  int m;
  printf("Entrez id de etudient pour modifier : ");
  scanf("%d", &searchId);

  int index = Search_id(searchId);

  if (index != -1)
  {
    ShowEtud(index);

    printf("========== \n");
    printf("-1- Modifier le nom \n");
    printf("-2- Modifier Prenom \n");
    printf("-3- Modifier date de naissance \n");
    printf("-4- Modifier la departement \n");
    printf("-5- Modifier note generale \n");
    printf("========== \n");

    printf(" Entrez le chempe que tu veux modifier : ");
    scanf("%d", &m);

    switch (m)
    {
    case 1:
      printf("modifier le nom : ");
      scanf("%s", newNom);
      if (strlen(newNom) > 0)
      {
        strcpy(etudient[i].nom, newNom);
      }
      break;
    case 2:
      printf("modifier Prenom : ");
      scanf("%s", newPrenom);
      if (strlen(newPrenom) > 0)
      {
        strcpy(etudient[i].prenom, newPrenom);
      }
      break;
    case 3:
      printf("modifier date de naissance : ");
      scanf("%s", newdateNaissance);
      if (strlen(newdateNaissance) > 0)
      {
        strcpy(etudient[i].dateNaissance, newdateNaissance);
      }
      break;
    case 4:
      printf("modifier departement : ");
      scanf("%s", newDepartement);
      if (strlen(newDepartement) > 0)
      {
        strcpy(etudient[i].departement, newDepartement);
      }
      break;
    case 5:
      printf("modifier la moyenne : ");
      scanf("%d", &newNotegenerale);

      etudient[i].note_generale = newNotegenerale;

      break;

    default:
      break;
    }
  }
  else
  {
    printf("==> Désoler Livre non releve !!! <==");
  }
};

void RemoveEtud()
{
  printf("======= Remove un livre ======= \n");
  int searchId;
  int removeClick;
  printf("Recherche etudient que vous souhaitez supprimez : ");
  scanf("%d", &searchId);

  int index = Search_id(searchId);

  if (index != -1)
  {
    ShowEtud(index);

    printf(" Alors spprimez ici en cliquant sur : -1- : ");

    scanf("%d", &removeClick);

    if (removeClick == 1)
    {
      for (int j = index; j <= numberEtud - 1; j++)
      {
        etudient[j] = etudient[j + 1];
      }
      numberEtud--;
      printf("Le live est supprimez \n");
    }
  }
  else
  {
    printf("==> Désoler Livre non releve !!! <==");
  }

  printf("============================== \n");
}

int countDep = 0;

void CalculMoyenne()
{
  char T[20][50];

  for (int i = 0; i < numberEtud; i++)
  {
    int alreadyPrinted = 0;
    for (int j = 0; j < i; j++)
    {
      if (strcmp(etudient[i].departement, etudient[j].departement) == 0)
      {
        alreadyPrinted = 1;
        break;
      }
    }
    if (!alreadyPrinted)
    {
      printf("%s\n", etudient[i].departement);
      strcpy(T[countDep], etudient[i].departement);
      countDep++;
    }
  }

  for (int i = 0; i < countDep; i++)
  {
    float somme = 0;
    int lengthDep = 0;

    for (int j = 0; j < numberEtud; j++)
    {
      if (strcmp(T[i], etudient[j].departement) == 0)
      {
        somme += etudient[j].note_generale;
        lengthDep++;
      }
    }
    printf("Departement %d %s %.2f \n: ", i + 1, etudient[i].departement, somme / lengthDep);
  }
}

void Show_nb_Etud()
{
  printf("le nombre des etudiants est: %d\n", numberEtud);
}

void Show_nb_dep()
{
  char T[20][50];

  for (int i = 0; i < numberEtud; i++)
  {
    int already = 0;
    for (int j = 0; j < i; j++)
    {
      if (strcmp(etudient[i].departement, etudient[j].departement) == 0)
      {
        already = 1;
        break;
      }
    }
    if (!already)
    {
      strcpy(T[countDep], etudient[i].departement);
      countDep++;
    }
  }

  for (int i = 0; i < countDep; i++)
  {
    float somme = 0;
    int lengthDep = 0;

    for (int j = 0; j < numberEtud; j++)
    {
      if (strcmp(T[i], etudient[j].departement) == 0)
      {
        lengthDep++;
      }
    }
    printf("le nombre des etudient de departement %s est : %d \n: ", etudient[i].departement, lengthDep);
  }
};

void Show_sup_seuil()
{
  int seuil;

  printf("Entrez le seuil : ");
  scanf("%d", &seuil);

  for (int i = 0; i < numberEtud; i++)
  {
    if (etudient[i].note_generale > seuil)
    {
      printf("Etudient : %s la note : %d \n", etudient[i].nom, etudient[i].note_generale);
    }
  }
};

void Show_tree_max()
{
  for (i = 0; i < numberEtud - 1; i++)
  {
    for (int j = i + 1; j < numberEtud; j++)
    {
      if (etudient[i].note_generale < etudient[j].note_generale)
      {
        reserve = etudient[i];
        etudient[i] = etudient[j];
        etudient[j] = reserve;
      }
    }
  }
  for (int i = 0; i < 3; i++)
  {
    printf("Etudient numero %d %s la note : %d \n", i + 1, etudient[i].nom, etudient[i].note_generale);
  }
};

void Show_sup_dix_dep()
{
  char T[20][50];

  for (int i = 0; i < numberEtud; i++)
  {
    int exist = 0;
    for (int j = 0; j < i; j++)
    {
      if (strcmp(etudient[i].departement, etudient[j].departement) == 0)
      {
        exist = 1;
        break;
      }
    }
    if (!exist)
    {
      strcpy(T[countDep], etudient[i].departement);
      countDep++;
    }
  }

  for (int i = 0; i < countDep; i++)
  {
    float somme = 0;
    int lengthDep = 0;

    for (int j = 0; j < numberEtud; j++)
    {
      if (strcmp(T[i], etudient[j].departement) == 0 && etudient[j].note_generale >= 10)
      {
        lengthDep++;
      }
    }

    printf("le nombre des etudient de departement %s est : %d \n: ", etudient[i].departement, lengthDep);
  }
};

void Statistiques()
{

  int choix;

  printf("1 : afficher le nombre total d\'etudiants inscrits.\n");
  printf("2 : afficher le nombre d\'etudiants dans chaque departement.\n");
  printf("3 : afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
  printf("4 : afficher les 3 etudiants ayant les meilleures notes.\n");
  printf("5 : afficher le nombre d\'etudiants ayant reussi dans chaque departement.\n");

  printf("entrer un choix : ");
  scanf("%d", &choix);

  switch (choix)
  {
  case 1:
    Show_nb_Etud();
    break;
  case 2:
    Show_nb_dep();
    break;
  case 3:
    Show_sup_seuil();
    break;
  case 4:
    Show_tree_max();
    break;
  case 5:
    Show_sup_dix_dep();
    break;
  default:
    printf("entrer un autre  choix.\n");
    break;
  }
};

void Trie_aphabetiqur()
{
  for (int i = 0; i < numberEtud; i++)
  {
    etudient[i].nom[0] + 32;
    for (int j = i + 1; j < numberEtud; j++)
    {
      if (etudient[i].nom[0] > etudient[j].nom[0])
      {
        reserve = etudient[j];
        etudient[j] = etudient[i];
        etudient[i] = reserve;
      }
      else if (etudient[i].nom[0] == etudient[j].nom[0])
      {
        int r = i;
        do
        {
          ++r;
          if (etudient[i].nom[r] > etudient[j].nom[r])
          {
            reserve = etudient[j];
            etudient[j] = etudient[i];
            etudient[i] = reserve;
          }
        } while (etudient[i].nom[r] == etudient[j].nom[r]);
      }
    }
  }
};

void Trie_sup_10()
{
  int count = 0;

  for (int i = 0; i < numberEtud; i++)
  {
    if (etudient[i].note_generale >= 10)
    {
      temp[count] = etudient[i];
      count++;
    }
  }

  for (i = 0; i < count - 1; i++)
  {
    for (int j = i + 1; j < count; j++)
    {
      if (temp[i].note_generale > temp[j].note_generale)
      {
        reserve = temp[i];
        temp[i] = temp[j];
        temp[j] = reserve;
      }
    }
  }

  for (i = 0; i < count; i++)
  {
    printf("Etudient : %s la note : %d \n", temp[i].nom, temp[i].note_generale);
  }
};

void Trie_etud_moyenne()
{
  int somme = 0;
  int moyenne = 0;
  int countDep = 0;
  int countTemp = 0;

  for (int i = 0; i < numberEtud; i++)
  {
    somme += etudient[i].note_generale;
  }

    for (int i = 0; i < numberEtud; i++)
  {
    int already = 0;
    for (int j = 0; j < i; j++)
    {
      if (strcmp(etudient[i].departement, etudient[j].departement) == 0)
      {
        already = 1;
        break;
      }
    }
    if (!already)
    {
      countDep++;
    }
  }

  moyenne = somme / countDep;

  printf("La moyenne est : %d \n", moyenne );


  for (int i = 0; i < numberEtud; i++)
  {
    if (etudient[i].note_generale >= moyenne)
    {
      temp[countTemp] = etudient[i];
      countTemp++;
    }
  }

  for (i = 0; i < countTemp - 1; i++)
  {
    for (int j = i + 1; j < countTemp; j++)
    {
      if (temp[i].note_generale > temp[j].note_generale)
      {
        reserve = temp[i];
        temp[i] = temp[j];
        temp[j] = reserve;
      }
    }
  }

  for (i = 0; i < countTemp; i++)
  {
    printf("Etudient : %s la note : %d \n", temp[i].nom, temp[i].note_generale);
  }
  
};

void TriersEtud()
{
  int choix;

  printf("1 : Tri alphabetique des etudiants en fonction de leur nom (de A a Z ou de Z a A).\n");
  printf("2 : Tri des etudiants par moyenne generale, du plus eleve au plus faible ou inversement.\n");
  printf("3 : Tri des etudiants selon leur statut de reussite (ceux ayant une moyenne superieure ou egale a 10/20).\n");

  printf("Entrer un choix : ");
  scanf("%d", &choix);
  switch (choix)
  {
  case 1:
    Trie_aphabetiqur();
    break;
  case 2:
    Trie_etud_moyenne();
    break;
  case 3:
    Trie_sup_10();
    break;
  default:
    printf("Entrer un autre  choix.\n");
    break;
  }
};

int main()
{

  struct Etudient etudient;

  do
  {
    printf("***************************************** \n");
    printf("-1- Ajouter un etudiant \n");
    printf("-2- Modifier un etudiant \n");
    printf("-3- Supprimer un etudiant \n");
    printf("-4- Afficher les details d'un etudian \n");
    printf("-5- Calculer la moyenne generale \n");
    printf("-6- Statistiques \n");
    printf("-7- Rechercher un etudiant par \n");
    printf("-8- Trier un etudiant par \n");
    printf("*********************************************** \n");

    printf("======> choisissez un servise : ");
    scanf("%d", &etudient.choix);

    switch (etudient.choix)
    {
    case 1:
      AddEtud();
      break;
    case 2:
      UpdateEtud();
      break;
    case 3:
      RemoveEtud();
      break;
    case 4:
      ShowAll();
      break;
    case 5:
      CalculMoyenne();
      break;
    case 6:
      Statistiques();
      break;
    case 7:
      SearchEtud();
      break;
    case 8:
      TriersEtud();
      break;
    default:
      printf("Entrez le nombre entre 1 et 8");
      break;
    }

  } while (etudient.choix != 0);

  return 0;
}
