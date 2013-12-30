#ifndef CMD_PENETRATE
#define CMD_PENETRATE

#pragma once 
#include <string>
using namespace std;
class CCmd{
private:
//成员变量：
//	客户机ID；
    int id;
//	客户机签名；
    string signature;
//	命令类型；
    int type;
//	命令内容；
    string message;
// 构造函数
    CCmd(int id = -1, string signature = "", int type = -1, string message = "");
    CCmd(const CCmd& paramCmd);
    CCmd & operator=(const CCmd & paramCmd);
//操作函数：
public:
//	各个成员变量的get和set函数；
    inline bool getId(int &rtId);
    inline bool setId(const int &paramId);

    inline bool getSignature(string &rtSignature);
    inline bool setSignature(const string &paramSignature);

    inline bool getType(int &rtType);
    inline bool setType(const int &paramType);

    inline bool getMessage(string &rtMessage);
    inline bool setMessage(const string &paramMessage);
//	格式化命令-Serialize：将对象的内容格式化成char数组；
    bool Serialize(char *rtBuf, int &len);
//	解析命令-Parse：将char数据解析成命令对象；
    bool Parse(const char *ptrData, const int &len);
};

#endif
