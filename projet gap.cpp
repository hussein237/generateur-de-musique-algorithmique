#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//fonction pour la generation des notes al�atoires
std::string notealeatoire(){
    //liste des notes de base
		std::vector<std::string>notes= {"A","B","C","D","E","F","G"};

	//ajout des bemols et di�ses,l'ajout du vide ("") pour plus de combinaisons
        std::vector<std::string> notessupplementaires= {"","#","b",};

    //selection al�atoire d'une note de base
        std::string note = notes[rand() % notes.size()];

    //selection al�atoire des notes suppl�mentaires
        std::string notessupplementaire = notessupplementaires[rand() % notessupplementaires.size()];

return note +   notessupplementaire;
}

//Fonction principale
    int main (){

//initialisation de la seclection al�atoire
    std::srand(std::time(0));

//interaction avec l'utilisateur
        int nombreDeNotes;
        std::cout << "Combien de notes voulez-vous generer ? ";
        std::cin >> nombreDeNotes;

//appel de la fontion et affichage du r�sultat
        std::cout << "\n Sequence de notes aleatoires :\n";
    for (int i = 0; i < nombreDeNotes; ++i) {
        std::cout << notealeatoire() << " ";
    }

        std::cout << "\n";
	return 0 ;

}
