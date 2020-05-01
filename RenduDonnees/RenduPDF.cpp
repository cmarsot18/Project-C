//
// Created by marso on 27/04/2020.
//

#include "RenduPDF.hpp"
#include "Personne.hpp"
#include "Membre.h"
#include "Consultant.h"

void RenduPDF::Generer_Association() {

}

void RenduPDF::Generer_membre(Personne *p_personne) {
    if (p_personne->getpole().compare("Consultant") == 0) {
        Consultant *p_consultant = static_cast<Consultant *>( p_personne );
        Fiche(p_consultant);
    } else {
        Membre *p_membre = static_cast<Membre *>( p_personne );
        Fiche(p_membre);
    }
}

    void RenduPDF::Fiche(Consultant* p_consultant) {
        int nbHeures = p_consultant->getNotes()[1];
        int chTravail = p_consultant->getNotes()[2];
        double motivation = (1+nbHeures+chTravail)/2;
        int communication = p_consultant->getNotes()[3];
        int relations = p_consultant->getNotes()[4];
        int sat = p_consultant->getNotes()[5];
        double satisfaction = (communication + relations + sat)/3;
        int orga = p_consultant->getNotes()[6];
        int initiatives = p_consultant->getNotes()[7];
        int autonomie = p_consultant->getNotes()[8];
        int adaptation = p_consultant->getNotes()[9];
        int relationel = p_consultant->getNotes()[10];
        double competences = (orga + initiatives + autonomie + adaptation + relationel)/5;
    }

    void RenduPDF::Fiche(Membre* p_membre) {
        int nbHeures = p_membre->getNotes()[1];
        int chTravail = p_membre->getNotes()[2];
        double motivation = (1+nbHeures+chTravail)/2;
        int relations = p_membre->getNotes()[3];
        int sat = p_membre->getNotes()[4];
        int nbTB = p_membre->getNotes()[5];
        int communication = p_membre->getNotes()[6];
        double satisfaction = (relations + sat + nbTB + communication)/4;
        int orga = p_membre->getNotes()[7];
        int initiatives = p_membre->getNotes()[8];
        int autonomie = p_membre->getNotes()[9];
        int adaptation = p_membre->getNotes()[10];
        int relationel = p_membre->getNotes()[11];
        double competences = (orga + initiatives + autonomie + adaptation + relationel)/5;
    }

