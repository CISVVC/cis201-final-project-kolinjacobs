#include "Word.h"
#include<iostream>

Word::Word(std::string s, int l){
  name = s;
  line_numbers.push_back(l);
  count = 1;
}

void Word::print(){
  std::cout << name << " : ";
  std::cout << count << " : ";
  for(int i = 0; i < line_numbers.size(); i++){
    if(i == line_numbers.size()-1){
      std::cout << line_numbers[i] << "\n";
    }else{
      std::cout << line_numbers[i] << ",";
    }
  }
}

int Word::get_count(){
  return count;
}
std::string Word::get_word(){
  return name;
}

void Word::add_line_number(int l){
  line_numbers.push_back(l);
  count ++;
}
