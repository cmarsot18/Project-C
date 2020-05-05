cmake_minimum_required(VERSION 3.16)
project(Project_C)

set(CMAKE_CXX_STANDARD 14)

include_directories(Association_class)
include_directories(CollecteurDonnees)
include_directories(RenduDonnees)
include_directories(Session)

add_executable(Project_C
        Association_class/Association.hpp
        Association_class/Consultant.cpp
        Association_class/Consultant.h
        Association_class/Personne.hpp
        Association_class/Personne.cpp
        CollecteurDonnees/CollecteurCSV.hpp
        CollecteurDonnees/CollecteurDonnees.hpp
        RenduDonnees/RenduDonnees.hpp
        RenduDonnees/RenduPDF.hpp
        RenduDonnees/RenduPDF.cpp
        Session/Session.cpp
        Session/Session.h
        Session/Session_Admin.cpp
        Session/Session_Admin.h
        Session/Session_Consultant.cpp
        Session/Session_Consultant.h
        Session/Session_Membre.cpp
        Session/Session_Membre.h
        Association_class/Membre.h
        Association_class/Membre.cpp
        Association_class/Association.cpp
        ProjetMain/Projet.cpp
        ProjetMain/Projet.h)

add_executable(Test
        Association_class/Association.hpp
        Association_class/Consultant.cpp
        Association_class/Consultant.h
        Association_class/Personne.hpp
        Association_class/Personne.cpp
        Association_class/TestAssociation.h
        CollecteurDonnees/CollecteurCSV.hpp
        CollecteurDonnees/CollecteurDonnees.hpp
        CollecteurDonnees/TestCollecteurCSV.cpp
        CollecteurDonnees/TestCollecteurCSV.h
        RenduDonnees/RenduDonnees.hpp
        RenduDonnees/RenduPDF.hpp
        RenduDonnees/RenduPDF.cpp
        RenduDonnees/TestRenduPDF.h
        RenduDonnees/TestRenduPDF.cpp
        Session/Session.cpp
        Session/Session.h
        Session/Session_Admin.cpp
        Session/Session_Admin.h
        Session/Session_Consultant.cpp
        Session/Session_Consultant.h
        Session/Session_Membre.cpp
        Session/Session_Membre.h
        Association_class/Membre.h
        Association_class/TestAssociation.cpp
        Association_class/Membre.cpp
        Association_class/Association.cpp
        Test/TestUnit.h
        Test/TestProject.cpp
        Association_class/TestConsultant.h
        Association_class/TestConsultant.cpp
        Association_class/TestMembre.h
        Association_class/TestMembre.cpp
        Session/TestSession.h
        Session/TestSession.cpp
        Session/TestSessionConsultant.h
        Session/TestSessionConsultant.cpp
        Session/TestSession.h
        Session/TestSession.cpp
        Session/TestSessionMembre.h
        Session/TestSessionMembre.cpp
        Session/TestSessionAdmin.h
        Session/TestSessionAdmin.cpp)

target_link_libraries(Test /usr/lib/x86_64-linux-gnu/libcppunit.so)
target_link_libraries(Test /usr/lib/x86_64-linux-gnu/libhpdf-2.3.0.so)
target_link_libraries(Project_C /usr/lib/x86_64-linux-gnu/libhpdf-2.3.0.so)