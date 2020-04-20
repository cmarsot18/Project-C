#include "Association.hpp"

Association::Association(){

};

Association::Association(string p_nom){
    nom = p_nom;
};

/*!
 * \brief Constructeur de la classe association
 * Crée une association pour laquelle on connait le nom, le lieu du siège et les membres
 */
Association::Association(string p_nom,string p_lieu){
    nom = p_nom;
    lieu = p_lieu;
};

Association::~Association(){

};

string Association::getNom() const{
    return nom;
};

string Association::setNom(string p_nom){
    nom = p_nom;
    return nom;
};

string Association::getLieu() const{
    return lieu;
};


string Association::setLieu(string lieu){

};

int Association::getNombre_Membres() const{
    return membres.size();
};

vector<Membre> Association::getMembres() const{

};

vector<Membre> Association::setMembres(vector<Membre> listeMembres) {
    membres = listeMembres;
    return membres;
//    copy(listeMembres.begin(), listeMembres.end(), back_inserter(membres));
};

void Association::ajouterMembre(const Membre p_membre){
    membres.push_back( p_membre );
};

void Association::supprimerMembre(Membre membre){

};
