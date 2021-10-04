#include "filehandler.h"

using namespace std;

vector<string>* loadData(string path)
{
    ifstream file;
    file.open(path);

    vector<string>* response = new vector<string>;

    string str;

    if (file)
    {
        response->reserve(20);

        while (getline(file,  str))
        {
            response->push_back(str);
        }
    }

    file.close();
    response->shrink_to_fit();

    return response;
}
