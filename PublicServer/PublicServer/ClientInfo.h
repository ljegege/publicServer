#include <string>
using namespace std;

//用于记录客户机信息
class CClientInfo{
//成员变量：
private:
//	客户机ID；
    int id;
//	客户机签名；
    string signature;
//	客户机状态；
    int state;
//	客户机IP地址；
    string ip;
//	客户机端口；
    string port;
//	心跳间隔；
    int heartbeatInterval;
public:
//操作函数：
//	各个成员变量的set和get函数
    inline bool getId(int &rtId);
    inline bool setId(const int &paramId);

    inline bool getSignature(string &rtSignature);
    inline bool setSignature(const string &paramSignature);

    inline bool getState(int &rtState);
    inline bool setState(const int &paramState);

    inline bool getIp(string &rtIp);
    inline bool setIp(const string &paramIp);

    inline bool getPort(int &rtPort);
    inline bool setPort(const int &paramPort);

    inline bool getHeartbeatInterval(int &rtHeartbeat);
    inline bool setHeartbeatInterval(const int &paramHeartbeat);

};
