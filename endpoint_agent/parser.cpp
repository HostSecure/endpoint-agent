#include "parser.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <QDebug>


namespace
{
int LINE_LIMIT = 500000;

}

Parser::Parser(std::string& filepath, QObject *parent) : QObject(parent)
{

    handleSources(filepath);


}

void Parser::handleSources(std::string filePath)
{
    std::ifstream ifsStream;
    std::string line;
    std::stringstream dataStream;

    ifsStream.open( filePath.c_str() );
    if (ifsStream.is_open() )
    {
        int i = 0;
        std::string tmpSource;
        std::string tmpFilePath;
        while ( std::getline(ifsStream, line))
        {
            dataStream << line;
            dataStream >> tmpSource;
            dataStream >> tmpFilePath;


            m_sourceName[i] = tmpSource;
            m_sourcePath[ m_sourceName[i] ] = tmpFilePath;
            dataStream.clear();
            ++i;

        }

        ifsStream.close();


        for( int ii = 0; ii < m_sourceName.size(); ++ii)
        {
            std::cout << m_sourceName[ii] << " " << m_sourcePath[ m_sourceName[ii] ] << std::endl;
        }
    }

}

void Parser::readLogSource()
{
    std::stringstream dataStream;
    std::ifstream ifsStream;
    std::string line;
    qDebug() << dataStream.str().max_size();


    for( int i = 0; i < m_sourceName.size(); ++i )
    {
        qDebug() << "opening ifstream";

        uint64_t lineCount = 0;
        ifsStream.open( m_sourcePath[ m_sourceName[ i ] ].c_str() );
        if( ifsStream.is_open() )

        {
            while( std::getline(ifsStream , line ))
            {
                //dataStream << line;
                m_DataHandler.checkData(line, m_sourceName[ i ]);
                ++ lineCount;

                if(lineCount > LINE_LIMIT)
                {
                    qDebug() << "Line limit reached";
                    break;

                }

            }
            ifsStream.close();
            qDebug() << "Close stream";
            m_sourceOffset[ m_sourceName[ i ] ] = lineCount;



        }
        else
        {
        qDebug() << "could not open ifstream";

        }
    }


}
