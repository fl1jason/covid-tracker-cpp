//
//  CPerson.hpp
//  OCTest
//
//  Created by Jason Sammon on 27/03/2021.
//

#ifndef CPerson_hpp
#define CPerson_hpp

#include <stdio.h>
#include <string>

using namespace std;

class CPerson {
 public:
    //string name;
    int age;
    string FirstName;
    string Surname;
    CPerson();
    ~CPerson();
    
    string ShowSummary();
};

#endif /* CPerson_hpp */
