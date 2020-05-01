//
// Created by marso on 07/04/2020.
//

#include "Session_Consultant.h"

using namespace std;

Session_Consultant:: Session_Consultant(){

}

Session_Consultant::Session_Consultant(const Consultant) {
    consultant = Consultant;

}
Session_Consultant::~Session_Consultant() {

}

Consultant Session_Consultant::getConsultant() const {
    return Consultant;
}

void Session_Consultant::setConsultant(const Consultant) {
    consultant = Consultant;
}

void Session_Consultant::Consulter_fiche() {

}