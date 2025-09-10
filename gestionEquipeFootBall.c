#include <stdio.h>
#include <string.h>

#define MAX 100

struct joueur{
    int id;
    char nomPrenom[100];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;

};

int ajouterJoueur(struct joueur j[],int nombreJoueurs){
    int nbrEntre ;
    static int nextId=1;
    printf("Entrez le nombre de joueur(s) pour ajouter : ");
    scanf("%d",&nbrEntre);
    getchar();

   for (int i = 0; i<nbrEntre; i++) {
        if (nombreJoueurs >= MAX) {
            printf("Carnet plein, impossible d'ajouter plus de joueurs.\n");
            return nombreJoueurs;
        }else {
            j[nombreJoueurs].id = nextId++;
            printf("Entrez le nom et prenom du joueur : ");
            scanf("%[^\n]",j[nombreJoueurs].nomPrenom);
            printf("Entrez le numero de Maillot du joueur : ");
            scanf("%d",&j[nombreJoueurs].numeroMaillot);
            getchar();
            printf("Entrez le post du joueur ( gardien, defenseur, milieu, attaquant ): ");
            scanf("%s",j[nombreJoueurs].poste);
            getchar();
            printf("Entrez l'age du joueur : ");
            scanf("%d",&j[nombreJoueurs].age);
            getchar();
            printf("Entrez les buts marqués par le joueur : ");
            scanf("%d",&j[nombreJoueurs].buts);
            getchar();
            
            nombreJoueurs ++;
        }
        
    
    }
    printf("Joueur(s) ajoute avec succes.\n");
    return nombreJoueurs;

}

void triBulleJour(struct joueur jr[],int nombreJoueurs ){
    struct joueur tmp;
    for (int i=0; i<nombreJoueurs -1 ; i++) {
        for (int j=0; j<nombreJoueurs-i-1; j++) {
            if (strcmp(jr[j].nomPrenom, jr[j+1].nomPrenom) > 0) {
                tmp = jr[j];
                jr[j] = jr[j + 1];
                jr[j + 1] = tmp;
            }
        }
    
    }
}
void triBulleJourAge(struct joueur jr[],int nombreJoueurs ){
    struct joueur tmp;
    for (int i=0; i<nombreJoueurs -1 ; i++) {
        for (int j=0; j<nombreJoueurs-i-1; j++) {
            if (jr[j].age>jr[j+1].age) {
                tmp = jr[j];
                jr[j] = jr[j + 1];
                jr[j + 1] = tmp;
            }
        }
    
    }
}
void afficherJoueurPsote(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    
    char rechercher[100] ;
    printf("Entrez le poste du joueur(s) pour afficher : ");
    scanf("%s",rechercher);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i< nombreJoueurs; i++) {
        if (strcmp(jr[i].poste, rechercher) == 0) {
            printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               jr[i].id, jr[i].nomPrenom, jr[i].numeroMaillot,
               jr[i].poste, jr[i].age, jr[i].buts);
            indice = 1;
        
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }

}

void afficherJoueur(struct joueur j[],int nombreJoueurs){
    
    if (nombreJoueurs == 0) {
        printf("Aucun Joueur disponible.\n");
        return;
    }
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i =0; i<nombreJoueurs; i++) {
        printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               j[i].id, j[i].nomPrenom, j[i].numeroMaillot,
               j[i].poste, j[i].age, j[i].buts);
        
    }
   
    
}
void rechecherIdJoueur(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    
    int rechercher;
    printf("Entrez l'Identifiant du joueur pour rechecher : ");
    scanf("%d",&rechercher);
    getchar();
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i< nombreJoueurs; i++) {
        if (jr[i].id==rechercher) {
            printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               jr[i].id, jr[i].nomPrenom, jr[i].numeroMaillot,
               jr[i].poste, jr[i].age, jr[i].buts);
            indice = 1;
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }

}

void rechecherNomJoueur(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    
    char rechercher[100] ;
    printf("Entrez le nom du joueur pour rechecher : ");
    scanf("%[^\n]",rechercher);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i< nombreJoueurs; i++) {
        if (strcmp(jr[i].nomPrenom, rechercher) == 0) {
            printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               jr[i].id, jr[i].nomPrenom, jr[i].numeroMaillot,
               jr[i].poste, jr[i].age, jr[i].buts);
            indice = 1;
        
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }

}

void modifierJoueurPoste(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    
    char rechercher[100] ;
    printf("Entrez le nom du joueur pour modifier le poste : ");
    scanf("%[^\n]",rechercher);

    for (int i = 0; i< nombreJoueurs; i++) {
        if (strcmp(jr[i].nomPrenom, rechercher) == 0) {
            printf("Entrez Nouveau poste du joueur : ");
            scanf("%s",jr[i].poste);
            indice = 1;
        
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }

}

void modifierJoueurAge(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    
    char rechercher[100] ;
    printf("Entrez le nom du joueur pour modifier l'age : ");
    scanf("%[^\n]",rechercher);

    for (int i = 0; i< nombreJoueurs; i++) {
        if (strcmp(jr[i].nomPrenom, rechercher) == 0) {
            printf("Entrez Nouveau l'age du joueur : ");
            scanf("%d",&jr[i].age);
            indice = 1;
        
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }

}

void modifierJoueurButs(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    
    char rechercher[100] ;
    printf("Entrez le nom du joueur pour modifier les buts marques : ");
    scanf("%[^\n]",rechercher);

    for (int i = 0; i< nombreJoueurs; i++) {
        if (strcmp(jr[i].nomPrenom, rechercher) == 0) {
            printf("Entrez Nouveau  le nombre de buts marques : ");
            scanf("%d",&jr[i].buts);
            indice = 1;
        
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }

}

int supprimerJoueur(struct joueur jr[],int nombreJoueurs){
    int indice =0;
    
    int rechercher;
    printf("Entrez l' identifiant du joueur pour supprimer : ");
    scanf("%d",&rechercher);
    getchar();

    for (int i = 0; i< nombreJoueurs; i++) {
        if (jr[i].id==rechercher) {
            for (int j = i; j < nombreJoueurs - 1; j++) {
                jr[j] = jr[j + 1];
            }
            nombreJoueurs--;
            printf("Joueur supprime avec succes \n");
            indice = 1;
        
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }
    return nombreJoueurs;

}

int calculerMoyenAge(struct joueur jr[],int nombreJoueurs){
    int moyenAge = 0;
    int somme = 0;
    for (int i=0; i<nombreJoueurs; i++) {
        somme += jr[i].age;
    
    }
    return moyenAge = (somme / nombreJoueurs);
}

void afficherButeMarqueJoueur(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    int x;
    printf("entrez le nombre pour affiche les joueurs ayant marqué plus de nombre buts : ");
    scanf("%d",&x);
    getchar();
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i< nombreJoueurs; i++) {
        if (jr[i].buts>=x) {
            printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               jr[i].id, jr[i].nomPrenom, jr[i].numeroMaillot,
               jr[i].poste, jr[i].age, jr[i].buts);
            indice=1;
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }
}

void afficherMeilleurButeur(struct joueur jr[],int nombreJoueurs){
    int butsMax=jr[0].buts;
    int position =0;
    for (int i=0; i<nombreJoueurs; i++) {
        if (jr[i].buts>butsMax) {
            butsMax=jr[i].buts;
            position = i;
        }
    
    }
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               jr[position].id, jr[position].nomPrenom, jr[position].numeroMaillot,
               jr[position].poste, jr[position].age, jr[position].buts);
    

}
void afficherPlusJeune(struct joueur jr[],int nombreJoueurs){
    int ageMin=jr[0].age;
    int position =0;
    for (int i=0; i<nombreJoueurs; i++) {
        if (jr[i].age<ageMin) {
            //ageMin=jr[i].age;
            position = i;
        }
    
    }
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               jr[position].id, jr[position].nomPrenom, jr[position].numeroMaillot,
               jr[position].poste, jr[position].age, jr[position].buts);

}
void afficherPlusAge(struct joueur jr[],int nombreJoueurs){
    int ageMax=jr[0].buts;
    int position =0;
    for (int i=0; i<nombreJoueurs; i++) {
        if (jr[i].age>ageMax) {
            ageMax=jr[i].buts;
            position = i;
        }
    
    }

    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts");
    printf("----------------------------------------------------------------------------------------------\n");

    printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |\n",
               jr[position].id, jr[position].nomPrenom, jr[position].numeroMaillot,
               jr[position].poste, jr[position].age, jr[position].buts);

}

int main(){
    int nombreJoueurs=4;
    struct joueur jr[MAX]= {
        {1, "Yassine Bounou", 1, "gardien", 34, 0},
        {2, "Achraf Hakimi", 2, "defenseur", 26, 20},
        {3, "Hakim Ziyech", 7, "milieu", 31, 50},
        {4, "Youssef En-Nesyri", 11, "attaquant", 28, 120}
    };
    int choix,sousChoix;

    menu:{
        printf("\n=== Menu ===\n");
        printf("1. Ajouter un joueur(s)\n");
        printf("2. Afficher tous les joueur disponibles\n");
        printf("3. Rechercher un joueur\n");
        printf("4. Mettre a jour le joueur(s)\n");
        printf("5. Supprimer un joueur(s)\n");
        printf("6. Statistiques\n");
        printf("7. Quitter\n");
    }

    printf("Votre choix : ");
    scanf("%d", &choix);
    getchar();

    switch (choix) {
    case 1:{ // ajouter
        nombreJoueurs = ajouterJoueur(jr, nombreJoueurs);
        
        goto menu;  // retour au menu
    }
    case 2:{ // affichage
        menu1:{
            printf("\n=== Sous Menu ===\n");
            printf("1. Afficher les joueurs tri par ordre alphabétique (Nom).\n");
            printf("2. Afficher les joueurs tri par âge.\n");
            printf("3. Afficher les joueurs par poste.\n");
            printf("4. retour au menu principale.\n");
        }
        printf("Votre sous choix : ");
        scanf("%d", &sousChoix);
        getchar();
        switch (sousChoix) {
            case 1:
                triBulleJour(jr, nombreJoueurs);
                afficherJoueur(jr, nombreJoueurs);
                goto menu1;
            break;
            case 2:
                triBulleJourAge(jr, nombreJoueurs);
                afficherJoueur(jr, nombreJoueurs);
                goto menu1;
            break;
            case 3:
                afficherJoueurPsote(jr, nombreJoueurs);
                goto menu1;
            break;
            case 4:
                goto menu;
            break;
            default:
                printf("Choix invalide !\n");
            break;
        
        }
        goto menu;  
    } 
    case 3:{ // recherche 
        menu2:{
            printf("\n=== Sous Menu ===\n");
            printf("1. Rechercher un joueur par Identifiant.\n");
            printf("2. Rechercher un joueur par Nom.\n");
            printf("3. retour au menu principale.\n");
        }
        printf("Votre sous choix : ");
        scanf("%d", &sousChoix);
        getchar();
        switch (sousChoix) {
            case 1:
                rechecherIdJoueur(jr, nombreJoueurs);
                goto menu1;
            break;
            case 2:
                rechecherNomJoueur(jr, nombreJoueurs);
                goto menu2;
            break;
            case 3:
                goto menu;
            break;
            
            default:
                printf("Choix invalide !\n");
            break;
        
        }
        goto menu;
         
    }
    case 4:{ // modification 
        menu3:{
            printf("\n=== Sous Menu ===\n");
            printf("1. Modifier le poste d'un joueur.\n");
            printf("2. Modifier l'age d'un joueur.\n");
            printf("3. Modifier le nombre de buts marqués par un joueur.\n");
            printf("4. retour au menu principale.\n");
        }
        printf("Votre sous choix : ");
        scanf("%d", &sousChoix);
        getchar();
        switch (sousChoix) {
            case 1:
                modifierJoueurPoste(jr, nombreJoueurs);
                goto menu3;
            break;
            case 2:
                modifierJoueurAge(jr, nombreJoueurs);
                goto menu3;
            break;
            case 3:
                modifierJoueurButs(jr, nombreJoueurs);
                goto menu3;
            break;
            case 4:
                goto menu;
            break;
            default:
                printf("Choix invalide !\n");
            break;
        
        } 
        goto menu;  
    }
    case 5:{
        nombreJoueurs = supprimerJoueur(jr, nombreJoueurs);
        goto menu;  
    }
    case 6:{ // Statistiques 
        menu4:{
            printf("\n=== Sous Menu ===\n");
            printf("1. Afficher le nombre total de joueurs dans l'equipe.\n");
            printf("2. Afficher l'age moyen des joueurs.\n");
            printf("3. Afficher les joueurs ayant marqué plus de X buts.\n");
            printf("4. Afficher le meilleur buteur.\n");
            printf("5. Afficher le joueur le plus jeune et le plus age.\n");
            printf("6. retour au menu principale.\n");
        }
        printf("Votre sous choix : ");
        scanf("%d", &sousChoix);
        getchar();
        switch (sousChoix) {
            case 1:
                printf("le nombre total de joueurs dans l'equipe est : %d",nombreJoueurs);
                goto menu4;
            break;
            case 2:
                printf("L'age moyen des joueurs est : %d ", calculerMoyenAge(jr, nombreJoueurs));
                goto menu4;
            break;
            case 3:
                afficherButeMarqueJoueur(jr, nombreJoueurs);
                goto menu4;
            break;
            case 4:
                printf("le meilleur buteur est : \n");
                afficherMeilleurButeur(jr, nombreJoueurs);
                goto menu4;
            break;
            case 5:
                printf("le joueur le plus jeune .\n");
                afficherPlusJeune(jr, nombreJoueurs);
                printf("le joueur le plus age.\n");
                afficherPlusAge(jr, nombreJoueurs);
                
                goto menu4;
            break;
            case 6:
                goto menu;
            break;
            default:
                printf("Choix invalide !\n");
            break;
        
        } 
        goto menu;  
    }
    case 7:{
       printf("au revoir !");
       break;
    }
    default:
        printf("Choix invalide.\n");
        goto menu;   
    }
    return 0;
}