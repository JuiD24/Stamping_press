#include "stampstream.h"

ostream &operator<<(ostream &ss, const row &R)
{
    stampbuf* sbp=(stampbuf*)ss.rdbuf();
    sbp->add_to_row(R.get_count());
    return ss;
}

row::row(int counter): count(counter){
    
}

int row::get_count(){
    return count;
}

stampstream::stampstream(int cols, int rows)
  :ostream{new stampbuf(cols, rows)}, total_cols{cols}, total_rows{rows}
{ 
  
}

stampstream::~stampstream()
{ 
  delete rdbuf();
}