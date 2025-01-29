//bibliothèque pour les entrées et sorties des variables
#include <iostream>
//bibliothèque pour l'utilisation des tableaux dynamiques
#include <vector>
//bibliothèque pour l'utilisation des fonctions  
#include <cstdlib>
//bibliothèque contient des définitions de fonctions permettant d'obtenir et de manipuler des informations de date et d'heure.
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

return note +   notessupplementaire ;
}

//Fonction principale
    int main (){

//initialisation de la selection aléatoire si cette instuction disparait alors il n'y aurait plus de generation aleatoire pour le prochain lancement
    std::srand(std::time(0));

//interaction avec l'utilisateur
        int nombrenotes;
        std::cout << "Combien de notes voulez-vous generer ? ";
        std::cin >> nombrenotes;

//appel de la fontion et affichage du résultat
        std::cout << "\n Sequence de notes aleatoires :\n";
    for (int i = 0; i < nombreDeNotes; ++i) {
        std::cout << notealeatoire() << " " ;
    }

        std::cout << "\n";
	return 0 ;

}
