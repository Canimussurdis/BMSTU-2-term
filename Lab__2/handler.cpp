#include "handler.h"
#include "filehandler.h"
#include "metrichandler.h"
#include "GraphicVectors.h"
#include "recordsplit.h"
#include "GraphicVectors.h"

//#include <QDebug>
//#include <vector>
//#include <stdlib.h>
//#include <QVector>

#define LOAD_DATA 0
#define CALC_METRICS 1

using namespace std;

vector<Record>* records = new vector<Record>;
vector<Record>* recmetr = new vector<Record>;

bool isLoaded = false;
string oldPath;

Response* execute(Request* request)
{
    Response* response = new Response;
    response->status = 1;

    switch (request->action)
    {
        case LOAD_DATA:
            if (!isLoaded || request->path != oldPath)
            {
                response->loadedData = *loadData(request->path);
                isLoaded = true;
                oldPath = request->path;
            }
            else
            { 
                response->records.clear();
            }

            setRecords(response,  recmetr, request->region);
            //recmetr = &response->records;
          //request->records = response->records;

            break;

        case CALC_METRICS:
            response->metrics = calcMatrics(recmetr, request->metricColumn);

            setGraphicVectors(request->records, &request->x, &request->y, request->col);
            if (response->metrics[3] == 0)
                response->status = 0;
            break;
    }

    return response;
}
