#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H

#include<ostream>
using std::ostream;
#include <iostream>
#include "stamp.h"
#include "stampbuf.h"

class row{
    public:
       row(int couter);
       int get_count();
       
    private:
        int count;
};

class stampstream : public ostream {
  public:
    stampstream(int cols, int rows);
    ~stampstream();
  private:
    int total_cols;
    int total_rows;
};

ostream &operator<<(ostream &output, const row &R);
#endif

