#ifndef WORD_H
#define WORD_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>


class Word {
  public:
    Word(std::string w, int l);
    std::string get_word();
    int get_count();
    void add_line_number(int l);
    void print();
  private:
    std::string name;
    int count;
    std::vector<int> line_numbers;
};
#endif
