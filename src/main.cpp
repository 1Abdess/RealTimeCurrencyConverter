//Abdessamad G.

#include <iostream>
#include <string.h>
#include <curl/curl.h>
#include <fstream>
#include "nlohmann/json.hpp"

constexpr const char* greenColor = "\033[32m";
constexpr const char* resetColor = "\033[0m";
constexpr const char* blueColor = "\033[34m";

size_t writeCallBack(void* contents, size_t size, size_t nmemb, void* userptr){
    size_t totalSize = size * nmemb;
    std::string* response = static_cast<std::string*> (userptr);
    response->append(static_cast<char*>(contents), totalSize);

    return totalSize;
}

int main(int argc, char** argv){
    // ./currencyConverter --help
        if((argc == 2) && (strcmp(argv[1], "--help") == 0)){
            std::cout << "\n\nUsage:" << blueColor << "./currencyConverter <value> <initial currency> <final currency>" << resetColor << std::endl;

            std::ifstream inputFile("extra/currencyList.txt");
            if(!inputFile.is_open()){
                std::cout << "file opening error." << std::endl;
            }
            else{
                std::string buffer;
                std::cout << greenColor << "available currencies:" << resetColor << std::endl;  
                while(std::getline(inputFile, buffer)){
                    std::cout << buffer << std::endl;
                }
            }
            
            inputFile.close();
            exit(0);    
        }

    // main program
        // Check Arguments
        if(argc != 4){
            std::cout << "Wrong program arguments. use --help for more information." << std::endl;
            exit(1);
        }

        float initialBalance = std::stof(argv[1]), finalBalance;
        std::string initialCurrency = argv[2], finalCurrency = argv[3];
        std::string APIKey = " "; //insert here your API key
        std::string url = "https://api.currencyapi.com/v3/latest?apikey="+APIKey+"&currencies="+finalCurrency+"&base_currency="+initialCurrency;


        std::string receivedJson;
        CURL* curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if(curl){            
            // set url to download
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            
            // set the write callback 
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &receivedJson);

            // perform the request
            res = curl_easy_perform(curl);

            // check errors
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }

            //clean up
            curl_easy_cleanup(curl);
        }

        //clean curl global resources
        curl_global_cleanup();

        nlohmann::json json = nlohmann::json::parse(receivedJson);

        finalBalance = (initialBalance * ((float) json["data"][finalCurrency]["value"]));

        //finalBalance = (float)initialBalance * json["data"][finalCurrency]["value"];
        std::cout << "Converting the currency you have: " << greenColor << finalBalance << " "<< finalCurrency << resetColor << std::endl;
        std::cout << "Previously you had: " << initialBalance << " " << initialCurrency <<"\n";

    return 0;
}