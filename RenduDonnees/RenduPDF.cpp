//
// Created by marso on 27/04/2020.
//

#include "RenduPDF.hpp"
#include "Personne.hpp"
#include "Membre.h"
#include "Consultant.h"

void RenduPDF::Generer_Association() {

}

void RenduPDF::Generer_membre(Personne p_personne) {
    double satisfaction;
    double motivation;
    double competences;
    if (p_personne.pole == "Consultant"){
        int nbHeures = (Consultant)p_personne.getNotes()[1];
        int chTravail = (Consultant)p_personne.getNotes()[2];
        motivation = (1+nbHeures+chTravail)/2;
        int communication = (Consultant)p_personne.getNotes()[3];
        int relations = (Consultant)p_personne.getNotes()[4];
        int sat = (Consultant)p_personne.getNotes()[5];
        satisfaction = (communication + relations + sat)/3;
        int orga = (Consultant)p_personne.getNotes()[6];
        int initiatives = (Consultant)p_personne.getNotes()[7];
        int autonomie = (Consultant)p_personne.getNotes()[8];
        int adaptation = (Consultant)p_personne.getNotes()[9];
        int relationel = (Consultant)p_personne.getNotes()[10];
        competences = (orga + initiatives + autonomie + adaptation + relationel)/5;
    }
    else{
        nbHeures = (Membre)p_personne.getNotes()[1];
        chTravail = (Membre)p_personne.getNotes()[2];
        motivation = (1+nbHeures+chTravail)/2;
        relations = (Membre)p_personne.getNotes()[3];
        sat = (Membre)p_personne.getNotes()[4];
        int nbTB = (Membre)p_personne.getNotes()[5];
        communication = (Membre)p_personne.getNotes()[6];
        satisfaction = (relations + sat + nbTB + communication)/4;
        orga = (Consultant)p_personne.getNotes()[7];
        initiatives = (Consultant)p_personne.getNotes()[8];
        autonomie = (Consultant)p_personne.getNotes()[9];
        adaptation = (Consultant)p_personne.getNotes()[10];
        relationel = (Consultant)p_personne.getNotes()[11];
        competences = (orga + initiatives + autonomie + adaptation + relationel)/5;
    }
}
