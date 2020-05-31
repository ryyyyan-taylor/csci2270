#include <iostream>
#include <fstream>
using namespace std;


int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
	int i = numEntries;
     while(newValue<=myArray[i-1]){
          myArray[i] = myArray[i-1];
          i--;
     }
	myArray[i] = newValue;
	cout<<myArray[i]<<" "<<newValue<<endl;
	return numEntries++;
}


int main(int argc, char *argv[]){

     ifstream file(argv[1]);

     if(file.is_open()){
          int nums[800];
          string line;
          int numLines = 0;
          int temp = 0;

          while(getline(file,line)){
               temp = stoi(line);
               cout<<temp<<endl;
               insertIntoSortedArray(nums, numLines, temp);
               numLines++;

               for(int j=0;j<numLines;j++){
                    if(numLines==1 || j==numLines-1){
                         cout<<nums[j];
                    }
                    else{
                         cout<<nums[j]<<",";
                    }
               }
               if(numLines>0){
                    cout<<endl;
               }
          }
     }
     else{
          cout<<"Failed to open the file"<<endl;
     }
}
