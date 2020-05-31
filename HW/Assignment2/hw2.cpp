#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct wordItem{
     int count;
     string word;
};

void resize(wordItem* arrayPtr[], int capacity)
{
     int newCapacity = capacity*2;

	wordItem* newArray = new wordItem[newCapacity];

     for(int i=0;i<capacity;i++){
          newArray[i] = *arrayPtr[i];
     }

	arrayPtr = &newArray;
	capacity = newCapacity;
     delete[] newArray;
     return;
}

void getStopWords(const char *ignoreWordFilename, string ignoredWords[]){
     int k=0;
     ifstream ignoreWords(ignoreWordFilename);

     if(ignoreWords.is_open()){
          string line;
          while(getline(ignoreWords, line)){
               ignoredWords[k] = line;
               k++;
          }
     }
     else{
          cout<<"Failed to open "<<ignoreWordFilename<<endl;
     }
}

bool isStopWord(string word, string ignoredWords[]){
     for(int i=0;i<50;i++){
          if(word == ignoredWords[i]){
               return true;
          }
     }
     return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
     int total=0;
     for(int i=0;i<length;i++){
          total = total + uniqueWords[i].count;
     }
     return total;
}

void arraySort(wordItem* uniqueWords[], int length){
     for(int j=0;j<length;j++){
          for(int i=0;i<length;i++){
               if(uniqueWords[i]->count < uniqueWords[i+1]->count){
                    wordItem temp;
                    temp.count = uniqueWords[i]->count;
                    temp.word = uniqueWords[i]->word;
                    uniqueWords[i] = uniqueWords[i+1];
                    uniqueWords[i+1] = &temp;
               }
               else{
                    continue;
               }
          }
     }
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords){
     for(int i=0;i<topN;i++){
          float prob = (float) uniqueWords[i].count / totalNumWords;
          cout<<fixed<<setprecision(4)<<prob<<" - "<<uniqueWords[i].word<<endl;
     }
}

wordItem* newWordItem(string word){
     wordItem *temp = new wordItem;
     temp->word = word;
     temp->count = 1;
     return temp;
}

int main(int argc, char *argv[]){
     string ignoredWords[60];
     wordItem *uniqueWords[100];
     for(int i=0;i<100;i++){
          uniqueWords[i]=NULL;
     }
     int size = 100;
     int actualWords = 0; 
     int doubleTimes=0;
     int count = 0;

     getStopWords(argv[3], ignoredWords);

     ifstream book(argv[2]);
     if(book.is_open()){
          string words = "";
          
          while(getline(book, words, ' ')){
               cout<<"next word"<<endl;
               count=0;
               if(isStopWord(words, ignoredWords)==false){
                    for(int i=0;i<size;i++){
                         if(uniqueWords[i] && words == uniqueWords[i]->word){
                              cout<<"SAME WORD"<<endl;
                              uniqueWords[i]->count++;
                              count++;
                              break;
                         }
                    }
                    if(count==0){
                         cout<<"ADDING WORD"<<endl;
                         uniqueWords[actualWords] = newWordItem(words);
                         actualWords++;
                    }
               }
               if(actualWords==size-1){
                    cout<<"TRYING TO RESIZE"<<endl;
                    resize(uniqueWords, size);
                    size=size*2;
                    doubleTimes++;
                    cout<<"DONE RESIZING"<<endl;
               }
          }

          cout<<"MADE IT HERE"<<endl;
          arraySort(uniqueWords, actualWords);

          cout<<"DONE SORTING"<<endl;

          cout<<"Array doubled: "<<doubleTimes<<endl;
          cout<<"#"<<endl;
          cout<<"Unique non-common words: "<<actualWords<<endl;
          cout<<"#"<<endl;
          cout<<"Total non-common words: "<<getTotalNumberNonStopWords(*uniqueWords, actualWords)<<endl;
          cout<<"#"<<endl;
          cout<<"Probabilities of top "<<argv[1]<<" most frequent words"<<endl;
          cout<<"-----------------------------------------"<<endl;
          printTopN(*uniqueWords, stoi(argv[1]), actualWords);
     }

}
