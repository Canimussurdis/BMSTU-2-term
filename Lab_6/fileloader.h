#ifndef FILELOADER_H
#include <iostream>
#include <fstream>
#define FILELOADER_H
using namespace std;

class fileLoader
{
private:
    string file_path;
    string file_text;
public:
    fileLoader();
    fileLoader(string path);

    void loadFile();
    string getFileText();
    void setFilePath(string path);
};

#endif // FILELOADER_H
