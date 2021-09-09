#include <QCoreApplication>
#include <string>
#include <vector>
#include <iostream>
#include <parser.h>
#include <unistd.h>

#include "USBServiceHandler.h"

namespace
{
    int ARG_LIMIT = 255;
    int ARGC_LIMIT = 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    USBServiceHandler sh;


    std::string exec_name = argv[0];
    std::string input_arg;
    if ( argc == 2 )
    {
        input_arg = argv[1];
        while (true)
        {
//            Parser parser(input_arg);
//            parser.readLogSource();
//            std::cout << "done parsing" << std::endl;
            sleep(1);
        }
    }

    else
    {
        std::cout << "No arg passed to " << exec_name << std::endl;
        return 0;
    }




    return a.exec();
}
