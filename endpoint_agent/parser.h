#pragma once

#include <QObject>
#include <vector>
#include <string>
#include <sstream>

#include "detector.h"

typedef unsigned char byte;
/// Purpose:
/// Parses log files from argument-passed filepaths upon start
/// fresh data is sent to detector

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = nullptr);
    void handleSources();
    void readSources();


private:
    std::vector<std::string> fileSources;
    int fileSourcesCount;
    Detector DataHandler;


signals:

};

