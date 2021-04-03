//
//  CQuickHttpRequest.cpp
//  OCTest
//
//  Created by Jason Sammon on 03/04/2021.
//

#include "CQuickHttpRequest.hpp"

#include <stdio.h>
#include <string>

CQuickHttpRequest::CQuickHttpRequest()
{
    
}

CQuickHttpRequest::~CQuickHttpRequest()
{
    
}

CQuickHttpRequest::CQuickHttpRequest(string sUrl)
{
    m_sUrl =  sUrl;
}

size_t CQuickHttpRequest::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


string CQuickHttpRequest::Get()
{
    return (Get(m_sUrl));
}

string CQuickHttpRequest::Get(string sUrl)
{
    m_sUrl = sUrl;
    string strOptions = "";
    
    return (Get(m_sUrl, strOptions));
}

string CQuickHttpRequest::Get(string sUrl, string& options)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    
    curl = curl_easy_init();
    
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, sUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CQuickHttpRequest::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
     
    return (readBuffer);
}
