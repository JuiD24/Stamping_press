
#ifndef ROW_H
#define ROW_H

#include<ostream>
using std::ostream;
#include "stampbuf.h"

class row{
    public:
       row(int couter);
       int get_count();
       friend ostream &operator<<(ostream &output, const row &R);
    private:
        int count;
};

#endif