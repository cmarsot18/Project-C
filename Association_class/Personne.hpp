#ifndef PERSONNE_H 
#define PERSONNE_H 

#include <string>

/*!
*\file Personne.hpp
*\brief Definition d'une personne par ses caractéristiques
*\author Groupe A4
*\version 0.1
*\date 7 avril 2020

\class Personne
*/

class Personne {   
	protected:
		std::string nom = " ";
		std::string prenom= " ";
		std::string mail= " ";
		std::string departement= " ";
        std::string Id= " ";
        std::string pass= " ";
        int saves = 0;

public :
    /*!
   *  \brief Redefinition de l'opérateur ==
   *
   *  Des personnes sont identiques si elles ont le meme nom et le meme prénom
   */
    bool operator == (const Personne obj1)
    {
        return (this->nom == obj1.nom
                && this->prenom == obj1.prenom);
    }
}; 

#endif // PERSONNE_H