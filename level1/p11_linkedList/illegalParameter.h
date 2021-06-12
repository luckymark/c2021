#ifndef illegalParameter_
#define illegalParameter_
#include <iostream>

class illegalParameter {
   public:
    illegalParameter() : message("Illegal parameter value") {}
    illegalParameter(std::string theMessage) { message = theMessage; }
    void outputMessage() { std::cout << message << std::endl; }

   private:
    std::string message;
};
#endif