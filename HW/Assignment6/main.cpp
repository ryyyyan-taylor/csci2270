#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"
using namespace std;

void menu(){
	cout<<"======Main Menu======"<<endl;
	cout<<"1. Print the Inventory"<<endl;
	cout<<"2. Delete a movie"<<endl;
	cout<<"3. Quit"<<endl;
}

int main(int argc, char const *argv[])
{
	MovieTree movies;
	string filename = argv[1];
	int ranking, year;
	string inChoice,inTitle, line, line2;
	float rating;

	ifstream file(filename);
	if(file.is_open()){
		while(getline(file,line)){
			stringstream ss;
			ss<<line;

			getline(ss, line2, ',');
			ranking = stoi(line2);
			getline(ss, line2, ',');
			inTitle = line2;
			getline(ss, line2, ',');
			year = stoi(line2);
			getline(ss, line2, ',');
			rating = stof(line2);

			movies.addMovie(ranking, inTitle, year, rating);
		}
	}

	while(inChoice!="3"){
		menu();
		getline(cin,inChoice);
		switch(stoi(inChoice)){
			case 1:
				movies.printMovieInventory();
				break;
			case 2:
				cout<<"Enter title:"<<endl;
				getline(cin,inTitle);
				movies.deleteMovie(inTitle);
				cout<<"MADE IT OUT"<<endl;
				break;
			case 3:
				cout<<"Goodbye!"<<endl;
				return 0;
		}
	}
}