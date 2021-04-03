//
//  CCovidStats.hpp
//  OCTest
//
//  Created by Jason Sammon on 03/04/2021.
//

#ifndef CCovidStats_hpp
#define CCovidStats_hpp

#include <stdio.h>
#include <string>

using namespace std;

class CCovidStats {

public:
    
    CCovidStats();
    
    int TotalCases = 0;
    float RollingAverage = 0.0;
    string SevenDaysTo = "";
    string LtlaName = "";
    string Msoa = "";
    string MsoaName = "";
    string NationName = "";
    string RegionName = "";
    string NhsTrustName = "";
    
    string LastError = "";
    
    bool Get(string sPostCode);
    bool Validate(string sPostCode);
    
private:
    bool GetMsoa(string sPostCode);
    bool GetStatsFromMsoa();
    
};
#endif /* CCovidStats_hpp */
