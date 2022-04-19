#include "stampbuf.h"

stampbuf::stampbuf(int ncols, int nrows)
  : total_cols{ncols}, total_rows{nrows}, current_col{0}, current_row{0}
{
  stamping_press::insert_plate(total_cols, total_rows);
  char* cp=new char[total_cols/2];
  setp(cp, cp+total_cols/2);
}

stampbuf::~stampbuf()
{   
  sync(); //flush array
  delete [] pbase(); //release char array
  stamping_press::eject_plate();
  
}

void stampbuf::add_to_row(int rowCount){
    sync();
    current_row = rowCount;
    current_col = 0;
}

void stampbuf::add_one_to_row(){
    current_row ++;
    current_col = 0;
}

int stampbuf::sync()
{
    for(auto i = pbase(); i < pptr(); i++)
    { 
        try{
          stamping_press::set_die(*i);
          if(current_col < total_cols)
            stamping_press::stamp(current_col, current_row);
        }catch(...){
        } 
        
        current_col++;    
    }
    setp(pbase(), epptr());
    return 0;
}

int stampbuf::overflow(int ch)
{
    sync();

    try{
      stamping_press::set_die(ch);
      stamping_press::stamp(current_col, current_row);
    }catch(...){
    }

    current_col++;
    setp(pbase(), epptr());   
    
    return ch; 
}

ostream& endrow(ostream& ss)
{
  stampbuf* sbp=(stampbuf*)ss.rdbuf();//this is a legitimate use of "downcasting"
  sbp->sync(); 
  sbp->add_one_to_row();
  return ss;
}