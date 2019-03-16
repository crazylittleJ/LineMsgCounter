#ifndef MESSAGE_PARSER_H
#define MESSAGE_PARSER_H
#include<regex>
#include<iostream>
#include<QString>

#define J_SUCCESS 0
#define J_FAIL    -1

typedef struct MessageStatics{
    int iPics;
    int iVideos;
    int iSticks;
    long lMessages;
}MESSAGE_STATICS;

class MessageParser
{
    public:
       explicit MessageParser();
       ~MessageParser();
    public:
       std::vector<QString> users;
       std::vector<MESSAGE_STATICS> user_statics;
    public:
       int ParseAndCountMessages(QString _qsTxtFileName);
    private:
       int DoesTheUserExist(QString _qsName);

};
#endif // MESSAGE_PARSER_H
