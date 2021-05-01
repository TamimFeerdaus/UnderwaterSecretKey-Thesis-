#include <iostream>
using namespace std;
/*
    This class is used to alert the whole system when unauthorized AUV
    and Sensor attack will happen.
*/
class Thread_Alert {
public:
    /*
        for taking record of unauthentic AUV and Sensor
        Two variables are initialized
    */
    string AUV_Name;
    int AUV_ID;
    string Sensor_Name;
    int Sensor_ID;

    void Thread(int outsider_List) {

        /* Alerting the system for unauthentic AUV sensor request*/

    }

};

