#include <iostream>
#include <string>

int crunch(const std::string& alphabet, int minLen, int maxLen) {
    int combinaisons = 0;
    int totalOctets = 0;

    // Boucle pour les différentes longueurs
    for (int len = minLen; len <= maxLen; len++) {
        // Boucle pour chaque combinaison possible de longueur `len`
        int totalComb = 1;
        for (int i = 0; i < len; i++) {
            totalComb *= alphabet.size();  // Calcul du nombre de combinaisons
        }
        
        // Génération et affichage des combinaisons
        for (int i = 0; i < totalComb; i++) {
            std::string combinaison = "";
            int temp = i;
            for (int j = 0; j < len; j++) {
                combinaison = alphabet[temp % alphabet.size()] + combinaison;
                temp /= alphabet.size();
            }
            std::cout << combinaison << std::endl;
            combinaisons++;
            totalOctets += len;  // Chaque combinaison prend `len` octets
        }
    }
    
    std::cout << combinaisons << " combinaisons soit " << totalOctets << " octets" << std::endl;
    return combinaisons;
}

int main(int argc, char* argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <minLen> <maxLen> <alphabet>" << std::endl;
        return 1;
    }

    // Récupération des arguments depuis la ligne de commande
    int minLen = std::stoi(argv[1]);  // Convertit la chaîne en entier
    int maxLen = std::stoi(argv[2]);
    std::string alphabet = argv[3];   // Alphabet passé en argument

    // Appel de la fonction crunch avec les arguments
    crunch(alphabet, minLen, maxLen);

    return 0;
}
