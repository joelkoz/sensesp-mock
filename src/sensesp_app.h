#ifndef _app_H_
#define _app_H_

#include "RemoteDebug.h"
#include "ReactESP.h"

class SensESPApp {


    public:
        bool isWifiConnected();

        bool isSignalKConnected();

        void enable() {}
                
};

extern SensESPApp* sensesp_app;
#endif
