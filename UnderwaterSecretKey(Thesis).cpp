#include <iostream>
#include <string>
#include "AESRaw.h"
#include "Node.h"
#include "Checking_Authentication.cpp"
#include "Storing_Data_Request.cpp"
#include "Checking_Neighbour.cpp"
#include "Checking_AUV_Sensor_Authentication.cpp"
#include <conio.h>
using namespace std;


int main()
{

//List implementation for different different List

    SinlglyLinkedList Outsider_List;    //object of a Outsider list

//created predefined linked list for Outsider List
    Node n2(1, 10);
    Node n3(2, 20);
    Node n4(3, 30);
    Outsider_List.SinglyLinkedList(&n2);
    Outsider_List.appendNode(&n3);
    Outsider_List.appendNode(&n4);
    cout << "" << endl;
//asking for a key to check the key value against Outsider list key   
    int givenKey;
    cout << "Give your key to check that Your given node exits or not in the Outsider List" << endl;
    cin >> givenKey;

    Checking_Authentication ObjCheckAuth;     //Object of a Checking Authentication class
    ObjCheckAuth.validateC_A(Outsider_List.nodeExists(givenKey));


    SinlglyLinkedList AUV_Outsider_List;    //object of a AUV Sensor Outsider List

//created predefined linked list for AUV Sensor Outsider List
    Node n5(5, 400);
    Node n6(7, 500);
    Node n7(4, 600);
    AUV_Outsider_List.SinglyLinkedList(&n5);
    AUV_Outsider_List.appendNode(&n6);
    AUV_Outsider_List.appendNode(&n7);
    cout << "" << endl;
//asking for a key value from user to check the key value against AUV Sensor outsider list key
    int givenKey1;
    cout << "Give your key to check that your given node exits or not in the AUV Sensor Outsider List" << endl;
    cin >> givenKey1;

    Checking_AUV_Sensor_Authentication ObjCheckAUVSeAu;     //Object of a AUV Sensor Checking Authentication class
    ObjCheckAUVSeAu.validateC_AUV(AUV_Outsider_List.nodeExists(givenKey1));


    SinlglyLinkedList Neighbour_List;    //object of a Neighbour list

//created predefined linked list for Neighbour List
    Node n8(9, 1000);
    Node n9(6, 2000);
    Node n10(8, 3000);
    Neighbour_List.SinglyLinkedList(&n8);
    Neighbour_List.appendNode(&n9);
    Neighbour_List.appendNode(&n10);
    cout << "" << endl;
//asking for a key to check the key value against Neighbour List key
    
    int givenKey2;
    cout << "Give your key to check that your given node exits or not in the Neighbour List" << endl;
    cin >> givenKey2;

    Checking_Neighbour ObjCheckNeigh;     //Object of a AUV Sensor checking class
    ObjCheckNeigh.validate_Neighbour(Neighbour_List.nodeExists(givenKey2));

    cout << "" << endl;

    

    callMain(); //Calling AES raw header file




//Linked List Operation to demonstrate our created Linked List in the  output window

    int option;
    int key1, k1, data1;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;
        Node* n1 = new Node();
        //Node n1;



        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            AUV_Outsider_List.appendNode(n1);
            //cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            AUV_Outsider_List.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            AUV_Outsider_List.insertNodeAfter(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            AUV_Outsider_List.deleteNodeByKey(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            AUV_Outsider_List.updateNodeByKey(key1, data1);

            break;
        case 6:
            AUV_Outsider_List.printList();

            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);




    return 0;

}


