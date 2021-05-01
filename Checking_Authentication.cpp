#include <iostream>
#include "Node.h"

#include <list>
using namespace std;


    //This class mainly check If the node authentic or not SOLID Methodology Approach

class Checking_Authentication {
public:
    string Node_Name;
    int Node_ID;
    
    //int Request_ID; this id will be used as IP address which are given from DHCP Pool
    
    void validateC_A(Node* temp) {
        /*
            This method is used for checking validation of Node.
            If exits in the outsider list print Unauthentic,
            else print Authentic 
            */

        if (temp != NULL) {

            cout << "*Node Already exists with key value in the Outsider list. So, it's  Unauthentic Node " << endl;
            cout << "" << endl;
        }
        else {

            cout << "*Node does not exists. So its Authentic Node" << endl;
            cout << "" << endl;
        }

    }
}
;

