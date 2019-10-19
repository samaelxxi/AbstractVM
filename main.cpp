#include <iostream>
#include "AbstractVM.h"

int main(int argc, char **argv)
{
    AbstractVM avm;

    if (argc == 1)
        avm.runFromCin();
    else if (argc == 2)
        avm.runFromFile(argv[1]);
    else
        std::cout << "usage: ./avm [filename]";

    return 0;
}
