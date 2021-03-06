#include "defines.h"
#include "MPD.h"

#ifndef LINUX
#include "ftd2xx.windows.h"
#else
#include "ftd2xx.linux.h"
#endif

#include <stdio.h>
#include <string.h>
#include "ftd2xx.inc"

// Construtor
MPD::MPD(int num)
{
	connected=false;
	numDev = DeviceInfoList();

}
//Destrutor
MPD::~MPD()
{
	delete this;
}
// Connect function
int MPD::connect(bool con)
{	
int ret;

  if(con==true){
		//CloseFtd(numDev);
		
		
		ret = OpenFtd(numDev);
		if(ret==1){
			connected = true;
			return 1;
		}else{
			connected = false;
			return 0;
		}		
   }else{
	ret = CloseFtd(numDev);
	connected=false;  
	//cout << "re: " << re << endl;
	return 1;	  	
  }
}

int MPD::SetLatency(unsigned char latency)
{
	SetLatencyFtd(numDev, latency);

	return 1;
}

int MPD::SetBlock(unsigned int block)
{
	SetBlockFtd(numDev, block);

	return 1;
}

int MPD::SetFlowControl(void)
{
	SetFlowControlFtd(numDev, FT_FLOW_RTS_CTS);

	return 1;
}

// Write function
int MPD::Write(int addr, unsigned char data)
{
	WriteFtd(numDev, addr);	// Endereço
	WriteFtd(numDev, data);	// dado
	return 1;
}
// Write function
int MPD::WriteB(unsigned char data)
{
	WriteFtd(numDev, data);	// dado
	return 1;
}

// Read function
int MPD::Read(unsigned char *data, DWORD &BytesR, DWORD size)
{
//	Int_t *DATA = data;
//	DWORD NBYTES = BytesR;
	ReadFtd(numDev, data, BytesR, size);
	return 1;
}

void MPD::reset(){
		WriteFtd(numDev,(char)0xFF);
}
// Gets
bool MPD::isConnected()
{
	return connected;
}
int MPD::GetNumDev()
{
	return numDev;
}
int MPD::GetSize()
{
	int size = 0;
	size = GetSIZE(numDev);
	return size;
} 
int MPD::clearBufferRX(){
	return clearRX(numDev);
}

int MPD::clearBufferTX(){
	return clearTX(numDev);
}

int MPD::ResetFTDevice(){
	return ResetDevice(numDev);
}
