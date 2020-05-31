#include <iostream>
#include <fstream>
using namespace std;

int split (string str, char c, string array[])
{
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }

struct User{
     string username;
     float gpa;
     int age;
};

void addUser(User users[], string _username, float _gpa, int _age, int length){
     User temp;
     temp.username = _username;
     temp.gpa = _gpa;
     temp.age = _age;
     users[length] = temp;
}

void printList(const User users[], int length){
     for(int i=0;i<length;i++){
          cout<<users[i].username<<" ["<<users[i].gpa<<"] age: "<<users[i].age<<endl;
     }
}


int main(int argc, char *argv[]){
     string parse1[10];
     string line;
     int numUsers = 0;
     User users[100];

     ifstream fileIn(argv[1]);
     if(fileIn.is_open()){
          while(getline(fileIn, line)){
               split(line, ',', parse1);
               addUser(users, parse1[0], stof(parse1[1]), stoi(parse1[2]), numUsers);
               numUsers++;
          }

     }
     ofstream fileOut(argv[2]);
     if(fileOut.is_open()){
          for(int i=0;i<numUsers;i++){
               if(users[i].gpa >= stof(argv[3])){
                    fileOut<<users[i].username<<", "<<users[i].gpa<<", "<<users[i].age<<endl;
               }
          }
     }
     printList(users, numUsers);
}
