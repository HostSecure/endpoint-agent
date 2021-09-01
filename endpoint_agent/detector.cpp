#include "detector.h"
#include <iostream>


Detector::Detector()
{

}

int Detector::checkData(std::string& data)
{
    for (auto& e : keyword)
    {
        keywordStream << e;


    }
    auto it = std::find_first_of( data.begin(), data.end(),
                                keywordStream.str().begin(),keywordStream.str().end());

    if(it != data.end() )
    {
        std::cout << *it << " found!" << std::endl;
        return 1;
    }

    return 0;
}
