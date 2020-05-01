//
// Created by marso on 31/03/2020.
//

#include "Session.h"
#include "Association.hpp"
using namespace std;

Session::Session() {

}

Session::Session(const std::string p_ID, const std::string p_Pass) {
    ID = p_ID;
    Pass = p_Pass;
}

bool Connection(const std::string,const std::string) const{

}

std::string Session::getID() const {
    return ID;
}

std::string Session::getPass() const {
    return Pass;
}

void Session::setID(const std::string p_ID) {
    ID = p_ID;
}

void Session::setPass(const std::string p_Pass) {
    Pass = p_Pass;
}