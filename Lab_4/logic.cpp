#include "logic.h"
#include "filehandler.h"
#include "drawhandler.h"
#include "metrichandler.h"
#include "stringPoints.h"

#include <QDebug>

#define SIZE 20

//vector<string> *loadedData;

bool loaded = false, drawed = false;
bool matrixCreated = false;

Point** points;
Line* lines = new Line[(SIZE - 1) * SIZE * 2];

float normalization[2] = {50, 400};

//точка входа, через свитч
Response* execute(Request* request)
{
    Response* response = new Response;

    switch (request->operation)
    {
        case Operations::LOAD_DATA:
            if (loaded)
            {
                response->loadedData.clear();
            }

            response->loadedData = *loadData(request->fileName);

            loaded = response->loadedData.size() != 0;

            if (!loaded)
            {
                response->done = false;
                response->message = "Не удалось загрузить данные";
            }
            break;

        case Operations::FREE_MEMORY:
            freePointMatrix(points, SIZE);
            delete [] lines;
            break;

        case Operations::DRAW:
            if (loaded)
            {
                if (matrixCreated)
                    freePointMatrix(points, SIZE);

                points = createPointMatrix(SIZE, SIZE);
                matrixCreated = true;

                setPoints(request, points, SIZE, SIZE);

                normalize(points, SIZE, SIZE, normalization);

                projectLines(points, lines, SIZE, SIZE);

                response->lines = lines;
            }
            else
            {
                response->done = false;
                response->message = "Данные не загружены";
            }
            break;

        case Operations::ROTATE:
            if (loaded)
            {
                rotate(points, SIZE, SIZE, request->axis, request->rotationAngle);
                normalize(points, SIZE, SIZE, normalization);
                projectLines(points, lines, SIZE, SIZE);

                response->lines = lines;
            }
            else
            {
                response->done = false;
                response->message = "Данные не загружены";
            }
            break;

        case Operations::OFFSET:
            if (loaded)
            {
                offset(points, SIZE, SIZE, request->axis, request->offsetValue);
                projectLines(points, lines, SIZE, SIZE);

                response->lines = lines;
            }
            else
            {
                response->done = false;
                response->message = "Данные не загружены";
            }
            break;

        case Operations::NORMALIZE:
            normalization[0] = request->normalization[0];
            normalization[1] = request->normalization[1];

            if (loaded)
            {
                normalize(points, SIZE, SIZE, normalization);
                projectLines(points, lines, SIZE, SIZE);

                response->lines = lines;
            }
            else
            {
                response->done = false;
                response->message = "Значения нормализации установлены. Данные не загружены";
            }
            break;
    }

    response->lineCount = (SIZE - 1) * SIZE * 2;

    return response;
}

