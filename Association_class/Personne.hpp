#ifndef PERSONNE_H 
#define PERSONNE_H 

#include <string>

/*!
*\file Personne.hpp
*\brief {Définition d'une personne par ses caractéristiques}
*\author Groupe A4
*\version 0.1
*\date 7 avril 2020

\class Personne
*/

class Personne {   
	protected:
		std::string nom;
		std::string prenom;
		int age;
		std::string adresse;
		std::string mail;
		int annee;
		std::string departement;
		
}; 

#endif // PERSONNE_H