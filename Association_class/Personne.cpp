//
// Created by marso on 01/05/2020.
//
#include "Personne.hpp"

std::string Personne::getpole() {
    return this->pole;
}

std::string Personne::getID() {
    return this->Id;
}

std::string Personne::getpass() {
    return this->pass;
}

int Personne::getsaves() {
    return this->saves;
}

void Personne::setID(const std::string p) {
    this->Id = p;
}

void Personne::setpass(const std::string p) {
    this->pass = p;
}

void Personne::setsaves(const int p) {
    this->saves = p;
}

void Personne::setpole(const std::string p) {
    this->pole = p;
}