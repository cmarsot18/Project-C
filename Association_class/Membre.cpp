#include "Membre.h"

Membre::Membre(string p_pole){
    pole = p_pole;
};

Membre::Membre( string p_pole, string p_nom, string p_prenom ){
    pole = p_pole;
    nom = p_nom;
    prenom = p_prenom;
};

Membre::Membre( string p_pole, string p_nom, string p_prenom,
string p_mail, string p_departement ){
    pole = p_pole;
    nom = p_nom;
    prenom = p_prenom;
    mail = p_mail;
    departement = p_departement;

};

Membre::~Membre(){

};

string Membre::getpole() const
{
    return pole;
}

void Membre::setpole(std::string p_pole){
    pole = p_pole;
};

string Membre::getNom() const
{
    return nom;
}

void Membre::setNom(std::string p_nom){
    nom = p_nom;
};

string Membre::getPrenom() const
{
    return prenom;
}

void Membre::setPrenom(std::string p_prenom){
    prenom = p_prenom;
};

string Membre::getMail() const
{
    return mail;
}

void Membre::setMail(std::string p_mail){
    mail = p_mail;
};

string Membre::getDepartement() const
{
    return departement;
}

void Membre::setDepartement(std::string p_departement){
    departement = p_departement;
};
