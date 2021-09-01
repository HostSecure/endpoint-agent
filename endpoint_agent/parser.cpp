#include "parser.h"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <QDebug>

Parser::Parser(std::vector<std::string> &buf, QObject *parent) : QObject(parent)
{
    m_SourceBuf = buf;
    m_SourceCount = m_SourceBuf.size();


}

void Parser::handleSources()
{
    std::stringstream dataStream;
    std::ifstream ifsStream;
    std::string line;


    for( int ii = 0; ii < m_SourceBuf.size(); ++ii )
    {
        qDebug() << "opening ifstream";
        qDebug() << m_SourceBuf.size();

        unsigned offset = 0;
        ifsStream.open( m_SourceBuf[ii].c_str() );
        if( ifsStream.is_open() )

        {
            while( std::getline(ifsStream , line ))
            {

                qDebug() << "check for keywords";
                if( DataHandler.checkData( line ) )
                {
                    dataStream << line;
                    ++offset;
                }
            }
            m_LineCount[ii] = offset;
            offset = 0;
            ifsStream.close();


        }
        else
        {
        qDebug() << "could not open ifstream";
        ifsStream.close();

        }
    }


}
