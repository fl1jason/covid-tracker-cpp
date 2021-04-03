//
//  main.cpp
//  OCTest
//
//  Created by Jason Sammon on 27/03/2021.
//
#include <iostream>
#include "CCovidStats.hpp"

static void PrintStats(CCovidStats& stats)
{
    cout << "LTLA: " << stats.LtlaName << endl;
    cout << "MSOA: " << stats.Msoa << endl;
    cout << "LSOA: " << stats.MsoaName << endl;
    cout << "Nation: " << stats.NationName << endl;
    cout << "Region: " << stats.RegionName << endl;
    cout << "NSH Trust: " << stats.NhsTrustName << endl;
    cout << "Seven Days To: " << stats.SevenDaysTo << endl;
    cout << "Rolling Average: " << to_string(stats.RollingAverage) << endl;
    cout << "Total Cases: " << to_string(stats.TotalCases) << endl;
}

int main(int argc, const char * argv[]) {
    
    CCovidStats stats;
    
    string strIn = "";

    bool bValid = false;
    while (!bValid)
    {
        cout << "Enter your Post Code:";
        cin >> strIn;
        
        if (!stats.Validate(strIn))
        {
            cerr << stats.LastError << endl;
        }
        else
        {
            bValid = true;
        }
    }
    
    try
    {
        bool bOk = stats.Get(strIn);
        if (bOk)
        {
            // Print the results
            PrintStats(stats);
        }
    }
    catch (const exception& e)
    {
        cerr << "Request failed, error: " << e.what() << endl;
    }
    
    return 0;
}
