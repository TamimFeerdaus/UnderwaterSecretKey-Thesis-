#include <iostream>
using namespace std;
/*
    This class is used for saving data for AUV which are requesting for
    storing data.
    SOLID Methodology Approach
*/
class Storing_Data_Request {
public:
    /*
        Given variables are use for AUV and their request for saving data
        to track.
    */
    string AUV_Name;
    int AUV_ID;
    string Sensor_Name;
    int Sensor_ID;

    void Data_Store() {
        cout << "Hello" << "\n";
        /*
            This method will use database for storing AUV's data.

        */

    }

};
