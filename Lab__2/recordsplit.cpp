#include "recordsplit.h"

void setRecord(Record* record, string* arr)
{
    record->year = atoi(arr[0].c_str());
    record->region = arr[1];
    record->npg = atof(arr[2].c_str());
    record->birthRate = atof(arr[3].c_str());
    record->deathRate = atof(arr[4].c_str());
    record->gdw = atof(arr[5].c_str());
    record->urbanization = atof(arr[6].c_str());

    record->arr[0] = atoi(arr[0].c_str());
    record->arr[1] = 0;
    record->arr[2] = atof(arr[2].c_str());
    record->arr[3] = atof(arr[3].c_str());
    record->arr[4] = atof(arr[4].c_str());
    record->arr[5] = atof(arr[5].c_str());
    record->arr[6] = atof(arr[6].c_str());
}

void setRecords(Response* response <recmetr>, string region)
{
    string arr[7];

    for (int i = 0; i < response->loadedData.size(); i++)
    {
        splitString((response->loadedData)[i], arr);

        if (arr[1] == region || region == "")
        {
            Record record;
            setRecord(&record, arr);
            response->records.push_back(record);

            recmetr.push_back(record);
        }
    }
}


void splitString(string input, string* output)
{
    string delimiter = ",";
    int i = 0;

    size_t pos = 0;
    string str;

    while ((pos = input.find(delimiter)) != string::npos)
    {
        str = input.substr(0, pos);

        output[i] = str;
        i++;

        input.erase(0, pos + delimiter.length());
    }

    output[i] = input;
}
