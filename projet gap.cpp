#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//fonction pour la generation des notes aléatoires
std::string notealeatoire(){
    //liste des notes de base
		std::vector<std::string>notes= {"A","B","C","D","E","F","G"};

	//ajout des bemols et dièses,l'ajout du vide ("") pour plus de combinaisons
        std::vector<std::string> notessupplementaires= {"","#","b",};

    //selection aléatoire d'une note de base
        std::string note = notes[rand() % notes.size()];

    //selection aléatoire des notes supplémentaires
        std::string notessupplementaire = notessupplementaires[rand() % notessupplementaires.size()];

return note +   notessupplementaire;
}

//Fonction principale
    int main (){

//initialisation de la seclection aléatoire
    std::srand(std::time(0));

//interaction avec l'utilisateur
        int nombreDeNotes;
        std::cout << "Combien de notes voulez-vous generer ? ";
        std::cin >> nombreDeNotes;

//appel de la fontion et affichage du résultat
        std::cout << "\n Sequence de notes aleatoires :\n";
    for (int i = 0; i < nombreDeNotes; ++i) {
        std::cout << notealeatoire() << " ";
    }

        std::cout << "\n";
	return 0 ;

}
