//
// Created by guenole on 03/05/2020.
//

#include "Projet.h"


int main(int argc, char *argv[]) {
    Consultant * pConsultant = new Consultant( "Renault", "Fiche", "Guénolé");

    RenduPDF rendu = RenduPDF( "/tmp/test.pdf");
    rendu.Fiche(pConsultant);
    return 0;
}