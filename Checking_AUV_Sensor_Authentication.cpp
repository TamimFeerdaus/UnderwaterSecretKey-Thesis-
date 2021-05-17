#include <iostream>
#include "Node.h"
#include <list>

using namespace std;
/*
    This class mainly check If AUV Sensors are authentic or not
    SOLID Methodology Approach
*/



class Checking_AUV_Sensor_Authentication {
public:
    
       //given variables are for tracking the authentic AUV and Sensor of the system.
    

    string AUV_Name;
    int AUV_ID;
    string Sensor_Name;
    int Sensor_ID;

    int validateC_AUV(Node* temp) {
        /*
            This method is used for checking validation of AUV and Sensor.
            If exits in the outsider list print Unauthentic
            else print Authentic */


        int countAUV = 0;


        if (temp != NULL) {

            cout << "*Node Already exists with key value in the AUV Sensor Outsider List. So, its not an Authentic AUV Sensor" << endl;
            cout << "" << endl;
            countAUV = 0;
        }
        else {

            cout << "*Node does not exists in the Outsider List, So it's Authentic AUV Sensor" << endl;
            cout << "" << endl;
            countAUV = 1;
        

        }

        return countAUV;

        cout << "";  //print
    }
};


