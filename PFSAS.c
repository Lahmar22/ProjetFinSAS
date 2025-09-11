#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

struct Date {
    int jour;
    int mois;
    int annee;
};

struct joueur{
    int id;
    char nomPrenom[100];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
    struct Date inscription; 

};

void remplirDateSysteme(struct joueur *jr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    jr->inscription.jour  = tm.tm_mday;
    jr->inscription.mois  = tm.tm_mon + 1;              
    jr->inscription.annee = tm.tm_year + 1900;
}


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
            remplirDateSysteme(&j[nombreJoueurs]);
            
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
void afficherEntete() {
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-10s | %-12s | %-5s | %-5s | %-12s |\n",
           "ID", "Nom & Prénom", "Maillot", "Poste", "Age", "Buts", "Inscription");
    printf("----------------------------------------------------------------------------------------------\n");
}
void afficherUnJoueur(struct joueur j) {
    printf("| %-3d | %-25s | %-10d | %-12s | %-5d | %-5d |  %02d/%02d/%04d  |\n",
           j.id, j.nomPrenom, j.numeroMaillot,
           j.poste, j.age, j.buts,
           j.inscription.jour, j.inscription.mois, j.inscription.annee);
}

void afficherJoueurPsote(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    
    char rechercher[100] ;
    printf("Entrez le poste du joueur(s) pour afficher : ");
    scanf("%s",rechercher);
    afficherEntete();
    for (int i = 0; i< nombreJoueurs; i++) {
        if (strcmp(jr[i].poste, rechercher) == 0) {
            afficherUnJoueur(jr[i]);
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
    afficherEntete();

    for (int i =0; i<nombreJoueurs; i++) {
        afficherUnJoueur(j[i]);
        
    }
}

int rechecherIdJoueur(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    int position=0;
    int rechercher;
    printf("Entrez l'Identifiant du joueur pour rechecher : ");
    scanf("%d",&rechercher);
    getchar();

    for (int i = 0; i< nombreJoueurs; i++) {
        if (jr[i].id==rechercher) {
            position=i;
            indice = 1;
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }
    return position;

}

void afficherJoueurID(struct joueur j[],int nombreJoueurs){
    int position = rechecherIdJoueur(j, nombreJoueurs);
    afficherEntete();

    afficherUnJoueur(j[position]);
    
}

int rechecherNomJoueur(struct joueur jr[], int nombreJoueurs){
    int indice =0;
    int position =0;
    char rechercher[100] ;
    printf("Entrez le nom du joueur pour rechecher : ");
    scanf("%[^\n]",rechercher);

    for (int i = 0; i< nombreJoueurs; i++) {
        if (strcmp(jr[i].nomPrenom, rechercher) == 0) {
            position = i;
            indice = 1;
        
        }
    
    }
    if (!indice) {
        printf("Joueur introuvable \n");
    
    }
    return position;

}
void afficherJoueurNom(struct joueur j[],int nombreJoueurs){
    int position = rechecherNomJoueur(j, nombreJoueurs);
    afficherEntete();

    afficherUnJoueur(j[position]);
    
}

void modifierJoueurPoste(struct joueur jr[], int nombreJoueurs){
    int position = rechecherNomJoueur(jr, nombreJoueurs);
    printf("Entrez Nouveau poste du joueur : ");
    scanf("%s",jr[position].poste);

}

void modifierJoueurAge(struct joueur jr[], int nombreJoueurs){
    int position = rechecherNomJoueur(jr, nombreJoueurs);
    printf("Entrez Nouveau l'age du joueur : ");
    scanf("%d",&jr[position].age);
}

void modifierJoueurButs(struct joueur jr[], int nombreJoueurs){
    int position = rechecherNomJoueur(jr, nombreJoueurs);
    printf("Entrez Nouveau nombre des buts marque du joueur : ");
    scanf("%d",&jr[position].buts);

}

int supprimerJoueur(struct joueur jr[],int nombreJoueurs){
    
    int position = rechecherIdJoueur(jr, nombreJoueurs);
        
    for (int j = position ; j < nombreJoueurs - 1; j++) {
        jr[j] = jr[j + 1];
    }
    nombreJoueurs--;
    printf("Joueur supprime avec succes \n");
    
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
    afficherEntete();
    for (int i = 0; i< nombreJoueurs; i++) {
        if (jr[i].buts>=x) {
             afficherUnJoueur(jr[i]);
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
    afficherEntete();
    afficherUnJoueur(jr[position]);
    

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
    afficherEntete();
    afficherUnJoueur(jr[position]);

}
void afficherPlusAge(struct joueur jr[],int nombreJoueurs){
    int ageMax=jr[0].buts;
    int position =0;
    for (int i=0; i<nombreJoueurs; i++) {
        if (jr[i].age>ageMax) {
           // ageMax=jr[i].buts;
            position = i;
        }
    
    }
    afficherEntete();
    afficherUnJoueur(jr[position]);

}

int main(){
    int nombreJoueurs=0;
    struct joueur jr[MAX];
    // struct joueur jr[MAX]= {
    //     {1, "Yassine Bounou", 1, "gardien", 34, 0,jr[0].inscription = remplirDateSysteme()},
    //     {2, "Achraf Hakimi", 2, "defenseur", 26, 20},
    //     {3, "Hakim Ziyech", 7, "milieu", 31, 50},
    //     {4, "Youssef En-Nesyri", 11, "attaquant", 28, 120}
    // };
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
            printf("1. Afficher les joueurs tri par ordre alphabétique.\n");
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
                afficherJoueurID(jr, nombreJoueurs);
                goto menu2;
            break;
            case 2:
                afficherJoueurNom(jr, nombreJoueurs);
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