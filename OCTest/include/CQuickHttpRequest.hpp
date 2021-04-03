//
//  CQuickHttpRequest.hpp
//  OCTest
//
//  Created by Jason Sammon on 03/04/2021.
//

#ifndef CQuickHttpRequest_hpp
#define CQuickHttpRequest_hpp

#include <stdio.h>
#include <curl/curl.h>
#include <string>

using namespace std;

class CQuickHttpRequest {
 public:
    CQuickHttpRequest();
    ~CQuickHttpRequest();
    CQuickHttpRequest(string sUrl);
    
    string Get();
    string Get(string sUrl);
    string Get(string sUrl, string& options);
    
protected:
    string m_sUrl;
    
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};


#endif /* CQuickHttpRequest_hpp */
