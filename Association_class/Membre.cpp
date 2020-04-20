#include "Membre.h"

Membre::Membre(string p_pole){
    pole = p_pole;
};

Membre::Membre( string p_pole, string p_nom, string p_prenom ){
    pole = p_pole;
    nom = p_nom;
    prenom = p_prenom;
};

Membre::Membre( string p_pole, string p_nom, string p_prenom, int p_age, string p_adresse,
string p_mail, int p_annee, string p_departement ){

};

Membre::~Membre(){

};

string Membre::getpole() const
{
    return pole;
}

void Membre::setNom(std::string p){

};
