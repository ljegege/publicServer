#include <iostream>
#include "PenetratingFirewall.h"
#include "Cmd.h"
using namespace std;

int main(int argc, char* argv[])
{
	CClientInfo userInfo;
	CCmd cmd;

	userInfo.SetId(1);
	userInfo.SetSignature("ljegege");
	userInfo.SetPort1(10086);
	userInfo.SetIp("192.168.1.108");

	CPenetratingFirewall penetFirewall;
	penetFirewall.Init("client_info", userInfo);

	while(true){
		if(penetFirewall.RecvCmd(cmd)){
			penetFirewall.DisposeCmd(cmd);
		}else{
			continue;
		}
	}
	return 0;
}