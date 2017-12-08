/*:
 * File: main.cpp
 * Developer: Kolin Jacobs
 * Email: jacobsk138447@student.vvc.edu
 * Descrition : This program a list of all the words found in a text file with a count of the
 * number of times the word occurred and a comma delimited list of the line numbers of where
 * the word occurred
 **/
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "Word.h"

//this function checks if a word exist inside of the vector
//if it does it adds adds a line number
//if it does not it adds the word to the vector
bool add_word(std::vector<Word> &ws, std::string w, int l){
  for(int i = 0; i < ws.size(); i++){
    if(ws[i].get_word() == w){
      ws[i].add_line_number(l);
      return true;
    }
  }
  Word wd(w,l);
  ws.push_back(wd); 
  return false;
}
//A function that takes in a file name and a word vector 
//the funtion will then then add every word of the file to vector
//the function also negates punction and keeps track of the line number a word was found on
void reader(std::string file, std::vector<Word> &w) {
  std::ifstream ifs;
  ifs.open (file);
  std::string word;
  int line_count = 1;
  while (ifs.good()) {
    char c;
    c = ifs.get();
    if(c == '\n'){
      line_count++;
    }
    if(!ispunct(c) && !isspace (c)){
      word += std::tolower(c); 
    }
    if(c == ' ' || c == '-' || c == '\n'){
      add_word(w,word,line_count);
      word = ""; 
    }
  }
  ifs.close();
}

int main() {
    std::vector<Word> words;
    reader("alice.txt", words);
    for(int i = 0; i < words.size(); i++){
      words[i].print();
    }
    return 0;
}
