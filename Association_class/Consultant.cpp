#include "Consultant.h"

Consultant::Consultant(string p_Mission){
    pole = p_Mission;
};

Consultant::Consultant( string p_Mission, string p_nom, string p_prenom ){
    mission = p_Mission;
    nom = p_nom;
    prenom = p_prenom;
};

Consultant::Consultant( string p_Mission, string p_nom, string p_prenom,
                string p_mail, string p_departement ){
    mission = p_Mission;
    nom = p_nom;
    prenom = p_prenom;
    mail = p_mail;
    departement = p_departement;

};

Consultant::~Consultant(){

};

string Consultant::getMission() const
{
    return mission;
}

void Consultant::setMission(std::string p_Mission){
    mission = p_Mission;
};

string Consultant::getNom() const
{
    return nom;
}

void Consultant::setNom(std::string p_nom){
    nom = p_nom;
};

string Consultant::getPrenom() const
{
    return prenom;
}

void Consultant::setPrenom(std::string p_prenom){
    prenom = p_prenom;
};

string Consultant::getMail() const
{
    return mail;
}

void Consultant::setMail(std::string p_mail){
    mail = p_mail;
};

string Consultant::getDepartement() const
{
    return departement;
}

void Consultant::setDepartement(std::string p_departement){
    departement = p_departement;
};

