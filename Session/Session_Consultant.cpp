//
// Created by marso on 07/04/2020.
//

#include "Session_Consultant.h"

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

void Session_Consultant::Consulter_fiche() {

}