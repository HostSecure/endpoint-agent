#pragma once
#include <QObject>

/// Purpose:
/// Detect anomalies from parsed log files
/// receives data from Parser class
typedef unsigned char byte;

class Detector : public QObject
{
public:
    Detector();

    void checkDict();
    void HandleAnomaly();

private:

};

