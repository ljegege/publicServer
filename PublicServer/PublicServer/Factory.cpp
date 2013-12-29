    //生成客户机列表对象函数-CreateClientTable：
CClientTable *CreateClientTable(int type)
{
	switch(type){
		case enumVecTable: return new CClientVectorTable();
		default: return NULL;
	}
}
    //生成接收和发送数据socket-CreateSocket；
CRSocket *CreateSocket(int type)
{
	switch(type){
		case enumReliableSocket: return new CRSocket();
		default: return NULL;
	}
}
