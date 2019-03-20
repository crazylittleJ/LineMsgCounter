#include "message_parser.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

MessageParser::MessageParser(){
    if(!this->users.empty())
    {
        users.clear();
    }
    if(!this->user_statics.empty())
    {
        user_statics.clear();
    }
}

MessageParser::~MessageParser(){
    if(!this->users.empty())
    {
        users.clear();
    }
    if(!this->user_statics.empty())
    {
        user_statics.clear();
    }
}

int MessageParser::DoesTheUserExist(QString _qsName){
    std::vector<QString>::iterator itr;
    itr = std::find(this->users.begin(), this->users.end(), _qsName);
    if (itr != this->users.end())
    {
        int x = std::distance(this->users.begin(),itr);
        return x;
    }
    return -1;
}

int MessageParser::ParseAndCountMessages(QString _qsTxtFileName){
    QFile inputFile(_qsTxtFileName);
    QRegularExpression rx1("\\d{2}:\\d{2}\\t.*\\t.*");
    QRegularExpression rx2("\\d{2}:\\d{2} .* .*");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          QRegularExpressionMatch match1 = rx1.match(line);
          QRegularExpressionMatch match2 = rx2.match(line);
          if(match1.hasMatch() || match2.hasMatch()){
              QStringList tokens;
              if(match2.hasMatch())
                  tokens = line.split(" ");
              else
                  tokens = line.split("\t");
              QString qsTheName = tokens[1];
              QString qsMessageType = tokens[2];
              int index = this->DoesTheUserExist(qsTheName);
              //Name exists
              if(index >= 0){
                    if(!qsMessageType.compare("[貼圖]"))
                        this->user_statics[(unsigned int)index].iSticks++;
                    else if(!qsMessageType.compare("[圖片]"))
                        this->user_statics[(unsigned int)index].iPics++;
                    else if(!qsMessageType.compare("[影片]"))
                        this->user_statics[(unsigned int)index].iVideos++;
                    else
                        this->user_statics[(unsigned int)index].lMessages++;
              //User does not exists
              }else{
                  MESSAGE_STATICS tempMsgStatic;
                  tempMsgStatic.iPics = 0; tempMsgStatic.iSticks = 0; tempMsgStatic.iVideos = 0; tempMsgStatic.lMessages = 0;
                  if(!qsMessageType.compare("[貼圖]"))
                      tempMsgStatic.iSticks++;
                  else if(!qsMessageType.compare("[圖片]"))
                      tempMsgStatic.iPics++;
                  else if(!qsMessageType.compare("[影片]"))
                      tempMsgStatic.iVideos++;
                  else
                      tempMsgStatic.lMessages++;
                  users.push_back(qsTheName);
                  user_statics.push_back(tempMsgStatic);
              }
          }
       }
       inputFile.close();
    }
    return 0;
}
