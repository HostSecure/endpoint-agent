#include <QCoreApplication>
#include <string>
#include <vector>
#include <iostream>
#include <parser.h>

namespace
{
    int ARG_LIMIT = 255;
    int ARGC_LIMIT = 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int argLimit;
    std::string exec_name = argv[0];
    std::vector< std::string > input_args;
    if ( argc > 1 )
    {

        argc > ARGC_LIMIT ?  argLimit = ARGC_LIMIT : argLimit = argc ;
        input_args.assign(argv + 1, argv + argLimit);
        Parser parser(input_args);
        parser.handleSources();
    }

    else
    {
        std::cout << "No args passed to " << exec_name << std::endl;
        return 0;
    }


    return a.exec();
}
