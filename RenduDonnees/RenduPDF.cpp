//
// Created by marso on 27/04/2020.
//

#include <stdlib.h>
#include "RenduPDF.hpp"
#include "Personne.hpp"
#include "Membre.h"
#include "Consultant.h"

RenduPDF::RenduPDF(string p_path) {
    path = p_path;
}

void error_handler (HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data)
{
    printf ("ERROR: error_no=%04X, detail_no=%d\n",
            (unsigned int) error_no, (int) detail_no);
    throw std::exception (); /* throw exception on error */
}


void
draw_rect (HPDF_Page     page,
           double        x,
           double        y,
           int           largeur,
           int           hauteur,
           const char   *label)
{
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, x + 10, y - hauteur + 10);
    HPDF_Page_ShowText (page, label);
    HPDF_Page_EndText (page);

//    HPDF_Page_Rectangle(page, x, y - 40, 220, 25);
    HPDF_Page_Rectangle(page, x, y - hauteur, largeur, hauteur);
}

void
draw_image (HPDF_Doc     pdf,
            const char  *filename,
            float        x,
            float        y)
{
    HPDF_Page page = HPDF_GetCurrentPage (pdf);
    HPDF_Image image;

    image = HPDF_LoadJpegImageFromFile (pdf, filename);

    /* Draw image to the canvas. */
    HPDF_Page_DrawImage (page, image, x, y, HPDF_Image_GetWidth (image) / 2,
                         HPDF_Image_GetHeight (image) / 2);
}


void RenduPDF::Generer_Association(Association association) {
    vector<Membre> membres = association.getMembres();
    int nbMembres = association.getNombre_Membres();
    double nbHeures = 0;
    double chTravail = 0;
    double relations = 0;
    double sat = 0;
    double nbTB = 0;
    double communication = 0;
    double orga = 0;
    double initiatives = 0;
    double autonomie = 0;
    double adaptation = 0;
    double relationel = 0;
    for (int i = 0; i < association.getNombre_Membres(); i++) {
        nbHeures += membres[i].getNotes()[0];
        chTravail += membres[i].getNotes()[1];
        relations += membres[i].getNotes()[2];
        sat += membres[i].getNotes()[3];
        nbTB += membres[i].getNotes()[4];
        communication += membres[i].getNotes()[5];
        orga += membres[i].getNotes()[6];
        initiatives += membres[i].getNotes()[7];
        autonomie += membres[i].getNotes()[8];
        adaptation += membres[i].getNotes()[9];
        relationel += membres[i].getNotes()[10];
    }
    nbHeures = nbHeures/nbMembres;
    chTravail = chTravail/nbMembres;
    double motivation = (1 + nbHeures + chTravail) / 2;
    relations = relations/nbMembres;
    sat = sat/nbMembres;
    nbTB = nbTB/nbMembres;
    communication = communication/nbMembres;
    double satisfaction = (relations + sat + nbTB + communication) / 4;
    orga = orga/nbMembres;
    initiatives = initiatives/nbMembres;
    autonomie = autonomie/nbMembres;
    adaptation = adaptation/nbMembres;
    relationel = relationel/nbMembres;
    double competences = (orga + initiatives + autonomie + adaptation + relationel) / 5;
    char czValue[10];

    HPDF_Doc pdf = HPDF_New (error_handler, NULL);
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return;
    }
    HPDF_Font font =  HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page page = HPDF_AddPage (pdf);

    /* print the title of the page (with positioning center). */
    HPDF_Page_SetFontAndSize (page, font, 24);
    float tw = HPDF_Page_TextWidth (page, association.getNom().c_str());
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, (HPDF_Page_GetWidth(page) - tw) / 2,
                           HPDF_Page_GetHeight (page) - 75);
    HPDF_Page_ShowText (page, association.getNom().c_str());
    HPDF_Page_EndText (page);

    draw_image( pdf, LOGO, 450, 725 );

    // Premier Bloc
    HPDF_Page_SetFontAndSize (page, font, 12);
    draw_rect ( page, 20, 720, 100, 50, "Motivation" );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 720, 180, 25, "Nombre d'heures" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", nbHeures );
    draw_rect ( page, 300, 720, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", motivation );
    draw_rect ( page, 400, 720, 100, 50, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 695, 180, 25, "Charge de Travail" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", chTravail );
    draw_rect ( page, 300, 695, 100, 25, czValue );
    HPDF_Page_Stroke (page);

    // Deuxième Bloc
    draw_rect ( page, 20, 670, 100, 100, "Satisfaction" );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 670, 180, 25, "Communication" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", communication );
    draw_rect ( page, 300, 670, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", satisfaction );
    draw_rect ( page, 400, 670, 100, 100, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 645, 180, 25, "Relations" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", relations );
    draw_rect ( page, 300, 645, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 620, 180, 25, "Satisfaction" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", sat );
    draw_rect ( page, 300, 620, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 595, 180, 25, "Team Buildings" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", nbTB );
    draw_rect ( page, 300, 595, 100, 25, czValue );
    HPDF_Page_Stroke (page);

    // Troisième Bloc

    draw_rect ( page, 20, 570, 100, 125, "Competences" );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 570, 180, 25, "Organisation" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", orga );
    draw_rect ( page, 300, 570, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", competences );
    draw_rect ( page, 400, 570, 100, 125, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 545, 180, 25, "Initiatives" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", initiatives );
    draw_rect ( page, 300, 545, 100, 25, czValue );
    HPDF_Page_Stroke (page);

    draw_rect ( page, 120, 520, 180, 25, "Autonomie" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", autonomie );
    draw_rect ( page, 300, 520, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 495, 180, 25, "Adaptation" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", adaptation );
    draw_rect ( page, 300, 495, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 470, 180, 25, "Relationnel" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", relationel );
    draw_rect ( page, 300, 470, 100, 25, czValue );
    HPDF_Page_Stroke (page);


    try {
        /* do page description processes (do not have to check function return codes) */
        HPDF_SaveToFile (pdf, path.c_str());
    } catch (...) {
        HPDF_Free (pdf);
        return;
    }

    HPDF_Free (pdf);
    return;
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
    int nbHeures = p_consultant->getNotes()[0];
    int chTravail = p_consultant->getNotes()[1];
    double motivation = (1+nbHeures+chTravail)/2;
    int communication = p_consultant->getNotes()[2];
    int relations = p_consultant->getNotes()[3];
    int sat = p_consultant->getNotes()[4];
    double satisfaction = (communication + relations + sat)/3;
    int orga = p_consultant->getNotes()[5];
    int initiatives = p_consultant->getNotes()[6];
    int autonomie = p_consultant->getNotes()[7];
    int adaptation = p_consultant->getNotes()[8];
    int relationel = p_consultant->getNotes()[9];
    double competences = (orga + initiatives + autonomie + adaptation + relationel)/5;
    char czValue[10];

    HPDF_Doc pdf = HPDF_New (error_handler, NULL);
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return;
    }
    HPDF_Font font =  HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page page = HPDF_AddPage (pdf);

    /* print the title of the page (with positioning center). */
    HPDF_Page_SetFontAndSize (page, font, 24);
    float tw = HPDF_Page_TextWidth (page, (p_consultant->getNom() + " " + p_consultant->getPrenom()).c_str());
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, (HPDF_Page_GetWidth(page) - tw) / 2,
                           HPDF_Page_GetHeight (page) - 75);
    HPDF_Page_ShowText (page, (p_consultant->getNom()+ " " + p_consultant->getPrenom()).c_str());
    HPDF_Page_EndText (page);

    draw_image( pdf, LOGO, 450, 725 );

    // Premier Bloc
    HPDF_Page_SetFontAndSize (page, font, 12);
    draw_rect ( page, 20, 720, 100, 50, "Motivation" );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 720, 180, 25, "Nombre d'heures" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", nbHeures );
    draw_rect ( page, 300, 720, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", motivation );
    draw_rect ( page, 400, 720, 100, 50, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 695, 180, 25, "Charge de Travail" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", chTravail );
    draw_rect ( page, 300, 695, 100, 25, czValue );
    HPDF_Page_Stroke (page);

    // Deuxième Bloc
    draw_rect ( page, 20, 670, 100, 75, "Satisfaction" );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 670, 180, 25, "Communication" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", communication );
    draw_rect ( page, 300, 670, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", satisfaction );
    draw_rect ( page, 400, 670, 100, 75, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 645, 180, 25, "Relations" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", relations );
    draw_rect ( page, 300, 645, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 620, 180, 25, "Satisfaction" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", sat );
    draw_rect ( page, 300, 620, 100, 25, czValue );
    HPDF_Page_Stroke (page);

    // Troisième Bloc

    draw_rect ( page, 20, 595, 100, 125, "Competences" );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 595, 180, 25, "Organisation" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", orga );
    draw_rect ( page, 300, 595, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%.2f", competences );
    draw_rect ( page, 400, 595, 100, 125, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 570, 180, 25, "Initiatives" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", initiatives );
    draw_rect ( page, 300, 570, 100, 25, czValue );
    HPDF_Page_Stroke (page);

    draw_rect ( page, 120, 545, 180, 25, "Autonomie" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", autonomie );
    draw_rect ( page, 300, 545, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 520, 180, 25, "Adaptation" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", adaptation );
    draw_rect ( page, 300, 520, 100, 25, czValue );
    HPDF_Page_Stroke (page);
    draw_rect ( page, 120, 495, 180, 25, "Relationnel" );
    HPDF_Page_Stroke (page);
    sprintf( czValue, "%d", relationel );
    draw_rect ( page, 300, 495, 100, 25, czValue );
    HPDF_Page_Stroke (page);


    try {
        /* do page description processes (do not have to check function return codes) */
        HPDF_SaveToFile (pdf, path.c_str());
    } catch (...) {
        HPDF_Free (pdf);
        return;
    }

    HPDF_Free (pdf);
    return;
}

    void RenduPDF::Fiche(Membre* p_membre) {
        int nbHeures = p_membre->getNotes()[0];
        int chTravail = p_membre->getNotes()[1];
        double motivation = (1+nbHeures+chTravail)/2;
        int relations = p_membre->getNotes()[2];
        int sat = p_membre->getNotes()[3];
        int nbTB = p_membre->getNotes()[4];
        int communication = p_membre->getNotes()[5];
        double satisfaction = (relations + sat + nbTB + communication)/4;
        int orga = p_membre->getNotes()[6];
        int initiatives = p_membre->getNotes()[7];
        int autonomie = p_membre->getNotes()[8];
        int adaptation = p_membre->getNotes()[9];
        int relationel = p_membre->getNotes()[10];
        double competences = (orga + initiatives + autonomie + adaptation + relationel)/5;
        char czValue[10];

        HPDF_Doc pdf = HPDF_New (error_handler, NULL);
        if (!pdf) {
            printf ("error: cannot create PdfDoc object\n");
            return;
        }
        HPDF_Font font =  HPDF_GetFont (pdf, "Helvetica", NULL);
        HPDF_Page page = HPDF_AddPage (pdf);

        /* print the title of the page (with positioning center). */
        HPDF_Page_SetFontAndSize (page, font, 24);
        float tw = HPDF_Page_TextWidth (page, (p_membre->getNom() + " " + p_membre->getPrenom()).c_str());
        HPDF_Page_BeginText (page);
        HPDF_Page_MoveTextPos (page, (HPDF_Page_GetWidth(page) - tw) / 2,
                               HPDF_Page_GetHeight (page) - 75);
        HPDF_Page_ShowText (page, (p_membre->getNom()+ " " + p_membre->getPrenom()).c_str());
        HPDF_Page_EndText (page);

        draw_image( pdf, LOGO, 450, 725 );

        // Premier Bloc
        HPDF_Page_SetFontAndSize (page, font, 12);
        draw_rect ( page, 20, 720, 100, 50, "Motivation" );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 720, 180, 25, "Nombre d'heures" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", nbHeures );
        draw_rect ( page, 300, 720, 100, 25, czValue );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%.2f", motivation );
        draw_rect ( page, 400, 720, 100, 50, czValue );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 695, 180, 25, "Charge de Travail" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", chTravail );
        draw_rect ( page, 300, 695, 100, 25, czValue );
        HPDF_Page_Stroke (page);

        // Deuxième Bloc
        draw_rect ( page, 20, 670, 100, 100, "Satisfaction" );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 670, 180, 25, "Communication" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", communication );
        draw_rect ( page, 300, 670, 100, 25, czValue );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%.2f", satisfaction );
        draw_rect ( page, 400, 670, 100, 100, czValue );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 645, 180, 25, "Relations" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", relations );
        draw_rect ( page, 300, 645, 100, 25, czValue );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 620, 180, 25, "Satisfaction" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", sat );
        draw_rect ( page, 300, 620, 100, 25, czValue );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 595, 180, 25, "Team Buildings" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", nbTB );
        draw_rect ( page, 300, 595, 100, 25, czValue );
        HPDF_Page_Stroke (page);

        // Troisième Bloc

        draw_rect ( page, 20, 570, 100, 125, "Competences" );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 570, 180, 25, "Organisation" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", orga );
        draw_rect ( page, 300, 570, 100, 25, czValue );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%.2f", competences );
        draw_rect ( page, 400, 570, 100, 125, czValue );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 545, 180, 25, "Initiatives" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", initiatives );
        draw_rect ( page, 300, 545, 100, 25, czValue );
        HPDF_Page_Stroke (page);

        draw_rect ( page, 120, 520, 180, 25, "Autonomie" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", autonomie );
        draw_rect ( page, 300, 520, 100, 25, czValue );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 495, 180, 25, "Adaptation" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", adaptation );
        draw_rect ( page, 300, 495, 100, 25, czValue );
        HPDF_Page_Stroke (page);
        draw_rect ( page, 120, 470, 180, 25, "Relationnel" );
        HPDF_Page_Stroke (page);
        sprintf( czValue, "%d", relationel );
        draw_rect ( page, 300, 470, 100, 25, czValue );
        HPDF_Page_Stroke (page);


        try {
            /* do page description processes (do not have to check function return codes) */
            HPDF_SaveToFile (pdf, path.c_str());
        } catch (...) {
            HPDF_Free (pdf);
            return;
        }

        HPDF_Free (pdf);
        return;
    }

