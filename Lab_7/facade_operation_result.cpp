#include "facade_operation_result.h"

bool FacadeOperationResult::IsSuccess() {
    return _isSuccess;
}

std::string FacadeOperationResult::GetErrorMessage() {
    return _errorMessage;
}
