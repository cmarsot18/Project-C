//
// Created by marso on 07/04/2020.
//

#include "Session_Admin.h"
#include "RenduPDF.hpp"

Session_Admin::Session_Admin(Membre pMembre) {

}

void Session_Admin::Consulter_fiche(string p_path , Personne *pMembre) {
    RenduPDF rendu = RenduPDF(p_path);
    rendu.Generer_membre(pMembre);
}

Session_Admin::~Session_Admin() {

}