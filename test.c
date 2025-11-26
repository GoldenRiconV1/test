#include <stdio.h>
#include <stdlib.h> // Nécessaire pour malloc et free

// 1. Définition de la structure du Noeud
typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;

// --- FONCTIONS UTILITAIRES ---
void libererListe(Noeud* tete) {
    Noeud* temp;
    
    while (tete != NULL) {
        temp = tete;        // On garde une référence sur le noeud actuel
        tete = tete->suivant; // On avance la tête vers le suivant D'ABORD
        free(temp);         // Maintenant on peut supprimer l'ancien noeud
    }
}
// Fonction pour créer un nouveau noeud (allocation mémoire)
Noeud* creerNoeud(int data) {
    // On demande à l'ordinateur de la place en mémoire
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud)); 
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->valeur = data;
    nouveau->suivant = NULL;
    return nouveau;
}

// Fonction pour afficher la liste
void afficherListe(Noeud* tete) {
    Noeud* temp = tete;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// --- LES FONCTIONS DEMANDÉES ---

// A. AJOUTER (au début, pour simplifier la construction)
// On utilise Noeud** (pointeur de pointeur) car on modifie la tête de liste
void ajouterDebut(Noeud** tete_ref, int data) {
    Noeud* nouveau = creerNoeud(data);
    nouveau->suivant = *tete_ref; // Le nouveau pointe vers l'ancienne tête
    *tete_ref = nouveau;          // La tête devient le nouveau noeud
}

// B. INSÉRER ENTRE DEUX (Après un noeud spécifique)
void insererApres(Noeud* noeud_precedent, int data) {
    if (noeud_precedent == NULL) {
        printf("Le noeud précédent ne peut pas être NULL\n");
        return;
    }
    
    // 1. Créer le nouveau noeud
    Noeud* nouveau = creerNoeud(data);
    
    // 2. Le nouveau pointe vers ce que pointait le précédent
    nouveau->suivant = noeud_precedent->suivant;
    
    // 3. Le précédent pointe vers le nouveau
    noeud_precedent->suivant = nouveau;
}

// C. SUPPRIMER UN NOEUD (par valeur)
void supprimerNoeud(Noeud** tete_ref, int key) {
    Noeud *temp = *tete_ref, *prev = NULL;

    // Cas 1 : La tête contient la valeur à supprimer
    if (temp != NULL && temp->valeur == key) {
        *tete_ref = temp->suivant; // On déplace la tête
        free(temp); // On libère la mémoire ! Important en C
        return;
    }

    // Cas 2 : Chercher la valeur ailleurs
    while (temp != NULL && temp->valeur != key) {
        prev = temp;
        temp = temp->suivant;
    }

    // Si la valeur n'était pas dans la liste
    if (temp == NULL) return;

    // On délie le noeud
    prev->suivant = temp->suivant;
    free(temp); // Libération mémoire
}

// D. TRIER LA LISTE (Tri à bulles - Bubble Sort)
void trierListe(Noeud* tete) {
    int echange;
    Noeud* ptr1;
    Noeud* lptr = NULL; // Pointeur vers le dernier noeud trié

    if (tete == NULL) return;

    do {
        echange = 0;
        ptr1 = tete;

        while (ptr1->suivant != lptr) {
            if (ptr1->valeur > ptr1->suivant->valeur) {
                // Échange des DONNÉES (plus simple que d'échanger les noeuds)
                int temp = ptr1->valeur;
                ptr1->valeur = ptr1->suivant->valeur;
                ptr1->suivant->valeur = temp;
                echange = 1;
            }
            ptr1 = ptr1->suivant;
        }
        lptr = ptr1; // Le dernier élément est maintenant à sa place
    } while (echange);
}

// --- MAIN ---

int main() {
    Noeud* maListe = NULL; // Au début, la liste est vide

    // 1. Construction de la liste : 3 -> 2 -> 1 -> NULL
    ajouterDebut(&maListe, 30);
    ajouterDebut(&maListe, 20);
    ajouterDebut(&maListe, 10);
    
    printf("Liste initiale :\n");
    afficherListe(maListe);

    // 2. Insertion entre deux (Ajouter 25 après 20)
    // On doit d'abord trouver le noeud 20. Pour l'exemple, c'est le 2ème (maListe->suivant)
    printf("\nInsertion de 25 après 20...\n");
    insererApres(maListe->suivant, 25); 
    afficherListe(maListe);

    // 3. Suppression
    printf("\nSuppression de 20...\n");
    supprimerNoeud(&maListe, 20);
    afficherListe(maListe);

    // 4. Tri
    printf("\nTri de la liste...\n");
    trierListe(maListe);
    afficherListe(maListe);
    libererListe(maListe);
    maListe = NULL;
    return 0;
}