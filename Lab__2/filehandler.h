#ifndef FILEHANDLER_H
#include <fstream>
#include <vector>
#include <string>
#define FILEHANDLER_H

using namespace std;

vector<string>* loadData(string path);

 /*std::vector<std::string>* loadData(string path)
    {
        ifstream file;
        file.open(path);

        vector<string>* response = new vector<string>;

        string str;

        if (file)
        {
            response->reserve(2000);

            getline(file,  str); // Dropping table headers

            while (getline(file,  str))
            {
                response->push_back(str);
            }
        }

        file.close();
        response->shrink_to_fit();

        return response;
    }
    */

#endif // FILEHANDLER_H
