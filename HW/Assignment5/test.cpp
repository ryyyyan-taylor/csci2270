#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
 	ifstream file("Movies.csv");

 	if(file.is_open()){
 		string line, line2, title, strRanking, strYear, strRating;
 		int year, ranking, count = 0;
 		float rating;
 		while(getline(file,line)){
 			stringstream ss;
 			ss<<line;

 			getline(ss, line2, ',');
 			ranking = stoi(line2);
 			getline(ss, line2, ',');
 			title = line2;
 			getline(ss, line2, ',');
 			year = stoi(line2);
 			getline(ss, line2, ',');
 			rating = stof(line2);

 
 		}
 	}
}