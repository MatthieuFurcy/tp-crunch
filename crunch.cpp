#include <iostream>
#include <string>

using namespace std;

int crunch(const string& alphabet, int minLen, int maxLen) {
    int combinaisons = 0;
    int totalOctets = 0;

    // Boucle pour les différentes longueurs
    for (int len = minLen; len <= maxLen; len++) {
        int totalComb = 1;

        // Calcul du nombre total de combinaisons possibles pour la longueur `len`
        for (int i = 0; i < len; i++) {
            totalComb *= alphabet.size();
        }

        // Génération et affichage des combinaisons
        for (int i = 0; i < totalComb; i++) {
            string combinaison = "";
            int temp = i;
            for (int j = 0; j < len; j++) {
                combinaison = alphabet[temp % alphabet.size()] + combinaison;
                temp /= alphabet.size();
            }
            cout << combinaison << endl;
            combinaisons++;
            totalOctets += len;  // Chaque combinaison de `len` caractères compte pour `len` octets
        }
    }
    
    cout << combinaisons << " combinaisons soit " << totalOctets << " octets" << endl;
    return combinaisons;
}

int main(int argc, char* argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <minLen> <maxLen> <alphabet>" << endl;
        return 1;
    }

    // Récupération des arguments depuis la ligne de commande
    int minLen = stoi(argv[1]);  // Convertit la chaîne en entier
    int maxLen = stoi(argv[2]);
    string alphabet = argv[3];   // Alphabet passé en argument

    // Appel de la fonction crunch avec les arguments
    crunch(alphabet, minLen, maxLen);

    return 0;
}
