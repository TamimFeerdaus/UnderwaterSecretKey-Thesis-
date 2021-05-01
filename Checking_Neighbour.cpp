#include <iostream>
#include "Node.h"

using namespace std;
/*
    This class is used for checking if the requested Node is our Neighbor or
    previously added Node.
*/
class Checking_Neighbour {
public:
    /*
        For checking neighbor we have initialized three  variables where Secret Key,
        Node ID and Node Name.
        Here Secret key is specialized Character given by system.
    */
    int Secret_Key;
    int Node_ID;
    string Node_Name;

    void validate_Neighbour(Node* temp ) {
        /*
            This method is used for checking neighbor by comparing the neighbor List.
            IT will return boolean type Data.
        */

        if (temp != NULL) {

            cout << "*Node exists with key value in the Neighbour list" << endl;
            cout << "" << endl;
        }
        else {

            cout << "*Node does not exists in the Neighbour list" << endl;
            cout << "" << endl;
        }
       
    }

};
