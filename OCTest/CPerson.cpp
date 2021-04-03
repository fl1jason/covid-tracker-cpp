//
//  CPerson.cpp
//  OCTest
//
//  Created by Jason Sammon on 27/03/2021.
//

#include "CPerson.hpp"
#include <string>

CPerson::CPerson()
{
    FirstName = "Jason";
    Surname = "Sammon";
}

CPerson::~CPerson()
{
    
}

string CPerson::ShowSummary(){
        
    string strFullName = FirstName + " " + Surname + " is " + to_string(age);
    return (strFullName);
}
