#include <iostream>
using namespace std;
/*
    This class will drop those request which are coming from unauthentic Node.
    SOLID Methodology Approach
*/
class Dropping_Request {
public:
    /*
        for taking record of unauthentic Node
        Two variables are initialized
    */
    string Node_Name;
    int Node_ID;

    void Drop_Request(int Outsider_Node_List) {
        /*
            This method is used for dropping unauthentic Node's request &
            saving their record in a List.
        */
    }

};
