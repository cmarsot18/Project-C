//
// Created by marsot on 07/04/2020.
//

#include "Session_Membre.h"
#include "RenduPDF.hpp"

Session_Membre::Session_Membre() {

}

Session_Membre::Session_Membre(const Membre) {

}
Session_Membre::~Session_Membre() {

}

Personne Session_Membre::getMembre() const {

}

void Session_Membre::setMembre(const Membre) {

}

void Session_Membre::Consulter_fiche_asso(string p_path) {
    RenduPDF rendu = RenduPDF(p_path);
    rendu.Generer_Association(association);
}