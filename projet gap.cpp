#include <iostream>   
#include <cstdlib>    
#include <ctime>      
#include <vector>     
#include <fstream>    

using namespace std;

vector<string> genererNotes(int nombredenotes) {
    // Liste des notes de musique possibles
    const char notes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    const int numNotes = sizeof(notes) / sizeof(notes[0]);

    // Liste des durées de notes de musique possibles
    const string rythmes[] = {"Noire", "Croche", "Blanche", "Ronde", "Double croche"};
    const int numRythmes = sizeof(rythmes) / sizeof(rythmes[0]);

    vector<string> suiteDeNotes;

    // Afin de générer une séquence aléatoire
    for (int i = 0; i < nombredenotes; i++) {
        char note = notes[rand() % numNotes];       // Sélection aléatoire d'une note
        int octave = 1 + (rand() % 8);             //Sélection aléatoire d'un octave (1 à 8)
        string rythme = rythmes[rand() % numRythmes]; // Sélection aléatoire d'un rythme

        string noteComplete = string(1, note) + to_string(octave) + " - " + rythme;
        suiteDeNotes.push_back(noteComplete);
    }

    return suiteDeNotes;
}

// Fonction pour enregistrer la suite dans un fichier texte si voulu
void enregistrerNotes(const vector<string>& notes) {
    ofstream fichier("notes.txt");

    if (fichier.is_open()) {
        for (const string& note : notes) {
            fichier << note << endl;
        }
        fichier.close();
        cout << "Suite enregistrée dans 'notes.txt'." << endl;
    } else {
        cout << "Erreur" << endl;
    }
}

int main() {
    srand(time(0)); // Initialiser le générateur de nombres aléatoires

    bool recommencer = true;

    while (recommencer == true) {
        int nombredenotes;

        cout << "Combien de notes voulez-vous générer ? ";
        cin >> nombredenotes;

        // Générer la suite de notes
        vector<string> notes = genererNotes(nombredenotes);

        // Pour afficher la suite générée
        cout << "Suite générée :\n";
        for (const string& note : notes) {
            cout << note << endl;
        }

        //Pour demander si l'utilisateur veut enregistrer la suite que nous venons de créer 
        char choix;
        cout << "Voulez-vous enregistrer cette suite dans un fichier ? (o/n) ";
        cin >> choix;

        if (choix == 'o' || choix == 'O') {
            enregistrerNotes(notes);
        }

        // Demander si l'utilisateur veut recommencer
        cout <<"Une nouvelle suite aléatoire ? (o/n)";
        cin >> choix;

        if (choix == 'n' || choix == 'N') {
            recommencer = false; }
        else { recommencer = true; }
        cout << endl; 
    }

    cout << "Programme terminé, ce sera tout.\n";
    return 0;
}