#ifndef FACADE_OPERATION_RESULT_H
#define FACADE_OPERATION_RESULT_H

#include <string>

class FacadeOperationResult  {
    bool IsSuccess();
    std::string GetErrorMessage();
public:
    std::string _errorMessage;
    bool _isSuccess;
};

#endif // FACADE_OPERATION_RESULT_H
