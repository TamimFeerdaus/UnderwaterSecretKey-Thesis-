#include <iostream>
using namespace std;
/*
    This class will drop those request which are coming from unauthentic
    AUV and Sensor.
    SOLID Methodology Approach
*/
class Dropping_AUV_Sensor_Request {
public:
    /*
        for taking record of unauthentic AUV and Sensor
        Two variables are initialized
    */
    string AUV_Name;
    int AUV_ID;
    string Sensor_Name;
    int Sensor_ID;

    void Drop_Request(int Outsider_List) {

        /*
            This method is used for dropping unauthentic or outsider AUV
            and Sensor's request & saving their record in a List.
        */
    }
};
