#include "fileloader.h"

fileLoader::fileLoader(): file_path(""), file_text(""){ }
fileLoader::fileLoader(string path): file_path(path), file_text(""){  }

void fileLoader::loadFile()
{
   ifstream stream;
   string line;
   stream.open(file_path);
   cout << stream.is_open() << endl;
   if (stream.is_open())
       while (!stream.eof())
       {
           getline(stream, line);
           file_text += line + "\n";
       }
}
string fileLoader::getFileText()
{
    string result;
    if (file_text != "")
        result = file_text;
    else
    {
        loadFile();
        result = file_text;
    }
    return result;
}
void fileLoader::setFilePath(string path)
{
    file_path = path;
}
