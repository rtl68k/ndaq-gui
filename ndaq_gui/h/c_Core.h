// header files required by the application
//#include <stdlib.h>
//#include <stdio.h>
//#include <time.h>
//#include <iostream>
//using namespace std;	

#include "MPD.h"

class Core {

private:
	MPD *fmpd0;

	unsigned char lc_config;
	

protected:
	bool Run;

public:
	Core();
	virtual ~Core();
	
	int SetConnect(bool state);
	void Initialize();
	void SetChannels(unsigned char c_config);
	void SetRun(bool state);
	bool GetRun() {return Run;}
	void ToggleRun();
	unsigned int Acq(unsigned char *Buffer);
	unsigned char MapChannels(unsigned char config, unsigned char *channel);

	//ClassDef(Core,0);
};