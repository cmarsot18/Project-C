//
// Created by guenole on 03/05/2020.
//

#include "Projet.h"


int main(int argc, char *argv[]) {
    Consultant * pConsultant = new Consultant( "Renault", "Fiche", "Guenole");
    Membre * pMembre = new Membre("Devco" , "Marsot", "Corentin");

    RenduPDF rendu1 = RenduPDF( "/tmp/testConsultant.pdf");
    rendu1.Generer_membre(pConsultant);
    RenduPDF rendu2 = RenduPDF("/tmp/testMembre.pdf");
    rendu2.Generer_membre(pMembre);


    return 0;
}