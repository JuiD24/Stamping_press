#ifndef STAMPBUF_H
#define STAMPBUF_H

#include<streambuf>
#include<iostream>
#include<ostream>
#include <ctype.h>
#include "stamp.h"
using std::streambuf;
using std::ostream;

class stampbuf : public streambuf {
  public:
    stampbuf(int ncols, int nrows);
    ~stampbuf();
    //this class overrides overflow() & sync()
    int sync();
    int overflow(int ch);
    void add_to_row(int rowCount); 
  private:
    int total_cols; //need this?
    int total_rows; //need this?
    int current_col;
    int current_row;

   protected:
    void add_one_to_row(); 
};
ostream& endrow(ostream& ss);
#endif
