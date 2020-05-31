/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include <iosteram>
#include <string>
#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[]){
     CountryNetwork network;

     int n;
     string in1 = "", in2 = "";
     display:
     displayMenu();
     cin>>n;
     switch(n){
          case 1:
               network.loadDefaultSetup();
               network.printPath();
               break;
          case 2:
               network.printPath();
               break;
          case 3:
               cout<<"Enter the name of the country to recieve the message:"<<endl;
               cin.ignore();
               getline(cin,in1);
               cout<<"Enter the message to send:\n"<<endl;
               getline(cin,in2);
               network.transmitMsg(in1,in2);
               cout<<endl;
               break;
          case 4:
               cin.ignore();
               cout<<"Enter a new country name:"<<endl;
               getline(cin,in1);
               cout<<"Enter the previous country name (or First):"<<endl;
               getline(cin,in2);
               network.insertCountry(network.searchNetwork(in1),in2);
               break;
          case 5:
               cout<<"Enter a country name:";
               cin.ignore();
               getline(cin,in1);
               network.deleteCountry(network.searchNetwork(in1));
               break;
          case 8:
               cout<<"Quitting... cleaning up path:"<<endl;
               network.printPath();
               network.deleteEntireNetwork();
               cout<<"Path cleaned"<<endl;
               cout<<"Goodbye!"<<endl;
     }
     goto display;

}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
