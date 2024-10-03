#include <iostream>
#include <string>

int crunch(const std::string& alphabet, int minLen, int maxLen) {
    int combinaisons = 0;

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
        }
    }
    
    std::cout << combinaisons << " combinaisons soit " << (combinaisons * (minLen + maxLen) / 2) << " octets" << std::endl;
    return combinaisons;
}

int main() {
    std::string alphabet = "ab";
    int minLen = 2;
    int maxLen = 4;
    
    crunch(alphabet, minLen, maxLen);

    return 0;
}
