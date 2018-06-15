#pragma once 

#include <string>
#include "BaseErrorListener.h"
#include "exception/InvalidQueryException.h"

class ThrowingErrorListener : public BaseErrorListener {

    static const ThrowingErrorListener INSTANCE;

   
   public:
    virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e) override
       {
         throw InvalidQueryException("");
      }
};