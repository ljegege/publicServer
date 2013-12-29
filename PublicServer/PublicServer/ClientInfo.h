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
    int port;
//	心跳间隔；
    int heartbeatInterval;
public:
// 构造函数
    CClientInfo(int id = -1，string signature = “”，int state = -1，string ip = “”，int port = -1, int heartbeatInterval = -1);
    CClientInfo(const CClientInfo& clientInfo);
    CClientInfo & operator=(const CClientInfo & paramClientInfo);
//操作函数：
//	各个成员变量的set和get函数
    inline bool GetId(int &rtId);
    inline bool SetId(const int &paramId);

    inline bool GetSignature(string &rtSignature);
    inline bool SetSignature(const string &paramSignature);

    inline bool GetState(int &rtState);
    inline bool SetState(const int &paramState);

    inline bool GetIp(string &rtIp);
    inline bool SetIp(const string &paramIp);

    inline bool GetPort(int &rtPort);
    inline bool SetPort(const int &paramPort);

    inline bool GetHeartbeatInterval(int &rtHeartbeat);
    inline bool SetHeartbeatInterval(const int &paramHeartbeat);

};
