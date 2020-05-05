//
// Created by guenole on 03/05/2020.
//

#include "Projet.h"


int main(int argc, char *argv[]) {



    Association test = Gestion_membre::Load("AJIR");
    RenduPDF rendu = RenduPDF("/tmp/Fiche" + test.getNom() + ".pdf");
    rendu.Generer_Association(test);


    for (int i =0 ; i<test.getNombre_Membres() ; i++ ){
        Membre *p_test = new Membre(test.getMembres()[i].getpole());
        p_test->setNotes(test.getMembres()[i].getNotes());
        rendu = RenduPDF("/tmp/Fiche " + test.getMembres()[i].getPrenom() + " " + test.getMembres()[i].getNom() + ".pdf");
        rendu.Generer_membre(p_test);
    }


    for (int i =0 ; i<=test.getNombre_Consultants();  i++ ){
        Consultant *p_test = new Consultant(test.getConsultant()[i].getMission());
        p_test->setNotes(test.getConsultant()[i].getNotes());
        rendu = RenduPDF("/tmp/Fiche " + test.getConsultant()[i].getPrenom() + " " + test.getConsultant()[i].getNom() + ".pdf");
        rendu.Generer_membre(p_test);
    }


    return 0;
}