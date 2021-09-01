#pragma once

#include <QObject>
#include <vector>
#include <string>

#include "detector.h"

typedef unsigned char byte;
/// Purpose:
/// Parses log files from argument-passed filepaths upon start
/// fresh data is sent to detector

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(std::vector<std::string>& buf , QObject *parent = nullptr);
    void handleSources();
    void readSources();


private:
    std::vector<std::string> m_SourceBuf;
    std::vector<unsigned int> m_LineCount;
    int m_SourceCount;
    Detector DataHandler;


signals:

};

