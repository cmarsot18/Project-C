//
// Created by marso on 07/04/2020.
//

#include "Session_Consultant.h"
#include "RenduPDF.hpp"

using namespace std;

Session_Consultant:: Session_Consultant(){

}

Session_Consultant::Session_Consultant(const Consultant p_consultant) {
    consultant = p_consultant;

}
Session_Consultant::~Session_Consultant() {

}

Consultant Session_Consultant::getConsultant() const {
    return consultant;
}

void Session_Consultant::setConsultant(const Consultant p_consultant) {
    consultant = p_consultant;
}

void Session_Consultant::Consulter_fiche(string p_path) {
    RenduPDF rendu = RenduPDF(p_path);
    Consultant *p_consultant = new Consultant(consultant.getMission(),consultant.getNom(),consultant.getPrenom());
    rendu.Fiche(p_consultant);
}