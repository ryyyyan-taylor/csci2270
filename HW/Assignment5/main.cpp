#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"
using namespace std;

void menu(){
	cout<<"======Main Menu======"<<endl;
	cout<<"1. Find a movie"<<endl;
	cout<<"2. Query movies"<<endl;
	cout<<"3. Print the inventory"<<endl;
	cout<<"4. Average Rating of movies"<<endl;
	cout<<"5. Quit"<<endl;
}

int main(int argc, char* argv[]){
	MovieTree movies;
	string filename = argv[1];
	int ranking, year;
	string inChoice, inRating, inYear, title, line, line2;
	float rating;

	ifstream file(filename);

 	if(file.is_open()){
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

 			movies.addMovieNode(ranking, title, year, rating);
 		}
 	}

 	while(inChoice!="5"){
 		menu();
 		getline(cin,inChoice);
 		switch(stoi(inChoice)){
 			case 1:
 				cout<<"Enter title:"<<endl;
 				getline(cin,title);
 				movies.findMovie(title);
 				break;
 			case 2:
 				cout<<"Enter minimum rating:"<<endl;
 				getline(cin,inRating);
 				cout<<"Enter minimum year:"<<endl;
 				getline(cin,inYear);
 				movies.queryMovies(stof(inRating), stoi(inYear));
 				break;
 			case 3:
 				movies.printMovieInventory();
 				break;
 			case 4:
 				movies.averageRating();
 				break;
 			case 5:
 				cout<<"Goodbye!"<<endl;
 				return 0;
 		}
 	}
}