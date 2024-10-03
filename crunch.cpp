#include <iostream>
#include <string>

using namespace std;

/* 
 * Fonction crunch : génère toutes les combinaisons possibles d'une longueur donnée 
 * à partir d'un alphabet spécifié, entre une longueur minimale et maximale.
 * 
 * Paramètres :
 * - alphabet : une chaîne de caractères représentant l'ensemble des caractères utilisables.
 * - minLen : longueur minimale des combinaisons à générer.
 * - maxLen : longueur maximale des combinaisons à générer.
 * 
 * Retourne :
 * - Le nombre total de combinaisons générées.
 */
int crunch(const string& alphabet, int minLen, int maxLen) {
    int combinaisons = 0;  // Compteur pour le nombre total de combinaisons
    int totalOctets = 0;   // Compteur pour le nombre total d'octets générés

    // Boucle pour les différentes longueurs de combinaisons
    for (int len = minLen; len <= maxLen; len++) {
        int totalComb = 1;  // Initialisation du compteur de combinaisons pour la longueur actuelle

        // Calcul du nombre total de combinaisons possibles pour la longueur `len`
        for (int i = 0; i < len; i++) {
            totalComb *= alphabet.size();  // Multiplie par la taille de l'alphabet à chaque position
        }

        // Génération et affichage des combinaisons
        for (int i = 0; i < totalComb; i++) {
            string combinaison = "";  // Réinitialisation de la combinaison
            int temp = i;  // Utilisé pour calculer les indices des caractères

            // Construction de la combinaison en fonction de l'index
            for (int j = 0; j < len; j++) {
                combinaison = alphabet[temp % alphabet.size()] + combinaison;  // Récupération du caractère
                temp /= alphabet.size();  // Réduction de l'index pour la prochaine position
            }

            cout << combinaison << endl;  // Affichage de la combinaison générée
            combinaisons++;  // Incrémentation du compteur de combinaisons
            totalOctets += len;  // Chaque combinaison de `len` caractères compte pour `len` octets
        }
    }
    
    // Affichage du nombre total de combinaisons et d'octets
    cout << combinaisons << " combinaisons soit " << totalOctets << " octets" << endl;
    return combinaisons;  // Retourne le nombre total de combinaisons
}

int main(int argc, char* argv[]) {
    // Vérification du nombre d'arguments passés à la ligne de commande
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <minLen> <maxLen> <alphabet>" << endl;  // Message d'erreur
        return 1;  // Retourne une erreur si le nombre d'arguments est incorrect
    }

    // Récupération des arguments depuis la ligne de commande
    int minLen = stoi(argv[1]);  // Convertit la chaîne d'arguments en entier pour la longueur minimale
    int maxLen = stoi(argv[2]);  // Convertit la chaîne d'arguments en entier pour la longueur maximale
    string alphabet = argv[3];    // Récupère l'alphabet passé en argument

    // Appel de la fonction crunch avec les arguments fournis
    crunch(alphabet, minLen, maxLen);

    return 0;  // Fin du programme
}
