#include <iostream>
#include <string>

using namespace std;

// Fonction qui génère les combinaisons possibles et calcule le nombre d'octets
void crunch(string current, int min_len, int max_len, string characters, int &total_octets, int &total_combinations) {
    if (current.length() >= min_len) {
        cout << current << endl; // Affichage des combinaisons sur la sortie écran
        total_combinations++;    // Compte du nombre de combinaisons
        total_octets += current.length() + 1; // Calcul des octets (chaîne + '\n')
    }

    if (current.length() == max_len) {
        return;
    }

    for (char c : characters) {
        crunch(current + c, min_len, max_len, characters, total_octets, total_combinations);
    }
}

int main() {
    string bibliotheque_systeme = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string bibliotheque_utilisateur;
    int longueur_min, longueur_max;
    bool valide = true;
    int total_octets = 0;       // Total des octets utilisés
    int total_combinations = 0; // Total des combinaisons générées
// Entrée des caractères
    cout << "Entrez les caracteres que vous voulez utiliser pour composer vos combinaisons: ";
    cin >> bibliotheque_utilisateur;

    // Vérification des caractères
    for (char c : bibliotheque_utilisateur) {
        if (bibliotheque_systeme.find(c) == string::npos) {
            valide = false;
            break;
        }
    }

    if (!valide) {
        cout << "Votre bibliotheque contient des caracteres non autorises" << endl;
        return 1;
    }

    // Entrée des longueurs
    cout << "Entrez la longueur minimale et maximale des combinaisons: ";
    cin >> longueur_min >> longueur_max;

    // Appel de la fonction crunch pour générer les combinaisons
    crunch("", longueur_min, longueur_max, bibliotheque_utilisateur, total_octets, total_combinations);

    // Affichage des résultats
    cout << total_combinations << " combinaisons soit " << total_octets << " octets" << endl;

    return 0;
}
