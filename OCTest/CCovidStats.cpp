//
//  CCovidStats.cpp
//  OCTest
//
//  Created by Jason Sammon on 03/04/2021.
//

#include <iostream>

#include "CCovidStats.hpp"
#include "CQuickHttpRequest.hpp"
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

CCovidStats::CCovidStats()
{
}

bool CCovidStats::Get(string sPostCode)
{
    // Chedck we're dealing with a valid Post Code
    if (Validate(sPostCode))
    {
        // Lookup the MSOA from the Post Code
        if (GetMsoa(sPostCode))
        {
            // Pull in the Full Statistics using the MSOA Code
            GetStatsFromMsoa();
        }
    }
    return (LastError.length() == 0);
}

bool CCovidStats::Validate(string sPostCode)
{
    LastError = "";
    
    // Check a Post Code has been provided at all
    if (sPostCode.length() == 8)
    {
        LastError = "A Post Code must be entered";
    }
    
    // Is the length valid?
    if ((sPostCode.length() < 6) || (sPostCode.length() > 8))
    {
        LastError = "The Post code was an invalid format";
    }
    
    return (LastError.length() == 0);
}

bool CCovidStats::GetMsoa(string sPostCode)
{
    string sUrl = "https://coronavirus.data.gov.uk/api/v1/code?category=postcode&search=" + sPostCode;
    CQuickHttpRequest req(sUrl);
    
    string sResponse = req.Get();
    if (sResponse.length() > 0)
    {
        auto j = json::parse(sResponse);
        
        LtlaName = j.at("ltlaName");
        Msoa  = j.at("msoa");
        MsoaName  = j.at("msoaName");
        NationName  = j.at("nationName");
        RegionName  = j.at("regionName");
        NhsTrustName  = j.at("nhsTrustName");
    }
    
    return (MsoaName.length() > 0);
}

bool CCovidStats::GetStatsFromMsoa()
{
    string sUrl = "https://coronavirus.data.gov.uk/api/v1/soa?filters=&areaType=msoa&areaCode="+Msoa+ "&structure=%7B%22areaCode%22:%22areaCode%22,%22release%22:%22release%22,%22newCasesBySpecimenDate%22:%5B%7B%22date%22:%22date%22,%22rollingSum%22:%22rollingSum%22,%22rollingRate%22:%22rollingRate%22,%22change%22:%22change%22,%22direction%22:%22direction%22,%22changePercentage%22:%22changePercentage%22%7D%5D%7D";
    
    CQuickHttpRequest req(sUrl);
    
    string sResponse = req.Get();
    
    if (sResponse.length() > 0)
    {
        auto j = json::parse(sResponse);
        //cout << j.dump() << std::endl;
        
        auto Var = j["latest"]["newCasesBySpecimenDate"]["rollingSum"];
        if (Var.type() != nlohmann::detail::value_t::null)
        {
            Var.get_to(TotalCases);
        }
        
        Var = j["latest"]["newCasesBySpecimenDate"]["rollingRate"];
        if (Var.type() != nlohmann::detail::value_t::null)
        {
            Var.get_to(RollingAverage);
        }
        
        SevenDaysTo = j["latest"]["newCasesBySpecimenDate"]["date"];
    }
    return (true);
}
