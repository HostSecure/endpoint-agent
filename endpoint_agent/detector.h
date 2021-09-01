#pragma once
#include <QObject>
#include <sstream>
#include <vector>
#include <string>
/// Purpose:
/// Detect anomalies from parsed log files
/// receives data from Parser class
typedef unsigned char byte;

class Detector : public QObject
{
public:
    Detector();

    int checkData(std::string& data);
    void checkDict();
    void HandleAnomaly();


private:

    std::vector< std::string > keyword {"drop", "block", "reject", "unauthorized"};
    std::stringstream keywordStream;

};

