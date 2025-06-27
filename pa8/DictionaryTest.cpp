//Servesh Karnawat
//skarnawa
//pa8

#include "Dictionary.h"
#include<iostream>
#include<string>
#include <stdexcept>

int main(){
    Dictionary A = Dictionary();
    Dictionary B = Dictionary();

    std::string ideal1 = "d\nb\nc (RED)\nf\ne (RED)\ng (RED)\n";
    std::string ideal2 = "e\nb\nc (RED)\nf\ng (RED)\n";
    std::string ideal3 = "e\nb\nc (RED)\nf\n";
    // string ideal2 = "c\nb\nf\ne (RED)\ng (RED)\n";
    // string ideal3 = "c\nb\nf\ne (RED)\n";
    A.setValue("d", 1);
    A.setValue("b", 5);
    A.setValue("a", 10);
    A.setValue("c", 15);
    A.setValue("f", 20);
    A.setValue("e", 25);
    A.setValue("g", 30);
    A.begin();
    A.remove("a");
    if (A.hasCurrent())
      return 1;
    std::cout << A.pre_string()<<"\n";
    if (A.pre_string() != ideal1)
      return 12;
    A.end();
    A.remove("d");
    if (A.currentKey() != "g" || A.currentVal() != 30)
      return 2;
    if (A.pre_string() != ideal2)
      return 22;
    A.remove("g");
    if (A.hasCurrent())
      return 3;
    if (A.pre_string() != ideal3)
      return 32;
    return 0;



    /*
    std::cout << "working 0\n";
    A.setValue("a", 1);
    std::cout << "working\n";
    A.setValue("b", 2);
    A.setValue("c", 3);
     std::cout << "working 2\n";
    A.setValue("e", 5);
    if (A.size() != 4)
      return 1;
    return 0;
    */


    /*
    // string ideal1 = "d\nb\nc\nf\ne\ng\n";
    // string ideal2 = "e\nb\nc\nf\ng\n";
    // string ideal3 = "e\nb\nc\nf\n";

    std::string ideal1 = "d\nb\nc (RED)\nf\ne (RED)\ng (RED)\n";
    std::string ideal2 = "e\nb\nc (RED)\nf\ng (RED)\n";
    std::string ideal3 = "e\nb\nc (RED)\nf\n";
    // string ideal2 = "c\nb\nf\ne (RED)\ng (RED)\n";
    // string ideal3 = "c\nb\nf\ne (RED)\n";
    A.setValue("d", 1);
    A.setValue("b", 5);
    A.setValue("a", 10);
    A.setValue("c", 15);
    A.setValue("f", 20);
    A.setValue("e", 25);
    A.setValue("g", 30);
    A.begin();
    //std::cout<<A.to_string()<<"\n";
    A.remove("a");
    //std::cout<<A.to_string()<<"\n";
    std::cout << "working 1 \n";

    if (A.hasCurrent())
      return 1;
    std::cout << "working 2 \n";

    //std::cout << A.pre_string();
    //std::cout << ideal1;

    if (A.pre_string() != ideal1)
      return 12;
    std::cout << "working 4 \n";

    A.end();
    std::cout <<"A curernt key";
    std::cout << A.currentKey()<<"\n";
    std::cout <<"A current val";
    std::cout << A.currentVal() <<"\n";
    


    std::cout << "working 5 \n";
    A.remove("d");
    std::cout << "working 6 \n";
    std::cout <<"A curernt key";
    std::cout << A.currentKey()<<"\n";
    std::cout <<"A current val";
    std::cout << A.currentVal() <<"\n";
    if (A.currentKey() != "g" || A.currentVal() != 30)
      return 2;
    std::cout << "working 7 \n";
    if (A.pre_string() != ideal2)
      return 22;
    std::cout << "working 8 \n";
    A.remove("g");
    std::cout << "working 3 \n";

    if (A.hasCurrent())
      return 3;
    if (A.pre_string() != ideal3)
      return 32;
    std::cout << "working final \n";
    */


    /*
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.end();
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);
    std::cout << "wrking 1\n";
    if (A.currentKey() != "e" || A.currentVal() != 10)
      return 1;
    std::cout << "wrking 1\n";

    A.end();
    std::cout << "end is " << A.currentKey() << A.currentVal() << "\n";
    A.prev();
    std::cout << "prev1 is " << A.currentKey() << A.currentVal() << "\n";
    
    A.prev();
    std::cout << "prev 2 is " << A.currentKey() << A.currentVal() << "\n";

    std::cout << "wrking 3\n";

    if (A.currentKey() != "f" || A.currentVal() != 20)
      return 2;
  
    std::cout << "final";
    */

    /*
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 3214);
    A.end();
    std::cout << "working1\n";
    std::cout << "end value is "<< A.currentKey()<<A.currentVal() <<"\n";
    A.prev();
    std::cout << "end value is "<< A.currentKey()<<A.currentVal() <<"\n";
    std::cout << "working2\n";

    if (A.currentKey() != "b" || A.currentVal() != 5)
      return 1;
    std::cout << "working3\n";

    A.prev();
    std::cout << "working4\n";

    std::cout << "end value is "<< A.currentKey()<<A.currentVal() <<"\n";

    A.prev();

    if (A.hasCurrent())
      return 2;
    std::cout <<"bing chillinf";
    /*
    /*
    A.setValue("a", 1);
    std::cout <<A.to_string();
    A.setValue("b", 5);
    std::cout <<A.to_string();
    A.setValue("c", 16);
    std::cout <<A.to_string();
    A.setValue("d", 176);
    A.setValue("e", 3214);
    std::cout <<A.to_string();
    //std::cout << "working1?\n";
    A.begin();
    std::cout << "current key is \n";
    std::cout <<  A.currentKey()<<"\n";
    std::cout << "current val is ?\n";
    std::cout << A.currentVal() << "\n";

    std::cout << "After beggin at first next?\n";
    A.next();
     std::cout << "current key is \n";
    std::cout <<  A.currentKey()<<"\n";
    std::cout << "current val is ?\n";
    std::cout << A.currentVal() << "\n";
    std::cout << "working3?\n";
    A.next();
    std::cout << "working4?\n";
     std::cout << "current key is \n";
    std::cout <<  A.currentKey()<<"\n";
    std::cout << "current val is ?\n";
    std::cout << A.currentVal() << "\n";
    std::cout << "current key is ?\n"<< A.currentKey();
    std::cout << "current val is ?\n"<< A.currentVal();

    if (A.currentKey() != "c" || A.currentVal() != 16)
      std::cout << "evil?\n";
    std::cout << "working5?\n";
    A.next();
    std::cout << "working6?\n";
    A.next();

    std::cout << "working7?\n";
    A.next();
    std::cout << "working8ss?\n";
    

    if (A.hasCurrent())
      return 2;
    std::cout <<"complete";
    */

    /*
    if (A.contains("d"))
       std::cout << "evil1 \n";

    A.setValue("d", 1);
    if (!A.contains("d"))
       std::cout << "evil1 \n";

    A.remove("d");
    if (A.contains("d"))
       std::cout << "evil1 \n";
    std::cout << "yuh yuh \n";  

    
    std::string ideal = "a\nb\ne\nh\nf\ni\n";
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);
    std::string val = A.pre_string();
    if (val != ideal)
        std::cout << "evil1 \n";
    std::cout << "suoo \n";

    
    std::string ideal = "a : 1\nb : 5\ne : 10\nf : 20\nh : 15\ni : 100\n";
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);
    std::string val = A.to_string();
    if (val != ideal)
      std::cout << "evil1 \n";
    std::cout << "yippie\n";

    
    A.clear();
    B.clear();
    if (!(A == B))
      std::cout << "evil1 \n";

    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);

    if ((A == B))
      std::cout << "evil2 \n";

    B.setValue("a", 1);
    B.setValue("b", 5);
    B.setValue("e", 10);
    B.setValue("h", 15);
    B.setValue("f", 20);
    B.setValue("i", 100);

    if (!(A == B))
      std::cout << "evil3 \n";

    B.clear();
    B.setValue("i", 100);
    B.setValue("f", 20);
    B.setValue("h", 15);
    B.setValue("e", 10);
    B.setValue("b", 5);
    B.setValue("a", 1);

    if (!(A == B))
      std::cout << "evil4 \n";
  

    std::cout <<"hehehehe";
    

    A.setValue("d", 2);
    A.setValue("d", 5);

    if (A.size() != 1)
      std::cout << "evil1 \n";

    std::cout << "size is "<< A.size()<<"\n";
    
    if (A.getValue("d") != 5)
      std::cout << "evil1 \n";

    std::cout << "val is "<< A.getValue("d")<<"\n";

    A.setValue("d", 1);

    if (A.getValue("d") != 1)
      std::cout << "evil1 \n";
    
    std::cout << "val is "<< A.getValue("d")<<"\n";

    A.remove("d");
    std::cout << "size is "<< A.size()<<"\n";

    if (A.size() != 0)
      std::cout << "evil1 \n";

    std::cout << "be \n";

    std::cout << "wut\n";
   

    
    if (A.contains("f"))
      std::cout << "evil \n";
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);

    if (A.getValue("f") != 20)
      std::cout << "evil1 \n";

    A.remove("f");

    if (A.contains("f"))
      std::cout << "evil 2\n";

    std::cout << "be \n";;

  

    A.setValue("d", 1);
    A.setValue("b", 5);
    A.setValue("a", 10);
    A.setValue("c", 15);
    A.setValue("f", 20);
    A.setValue("e", 25);
    A.setValue("g", 30);
    A.begin();
    A.remove("a");
    if (A.hasCurrent())
      std::cout << "evil \n";
    A.end();
    A.remove("d");
    if (A.currentKey() != "g" || A.currentVal() != 30)
      std::cout << "evil \n";
    A.remove("g");
    if (A.hasCurrent())
      std::cout << "evil \n";
    std::cout << "chil \n";

    
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.end();
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);
    if (A.currentKey() != "e" || A.currentVal() != 10)
      std::cout << "evil\n";
    A.end();
    A.prev();
    A.prev();
    if (A.currentKey() != "f" || A.currentVal() != 20)
      std::cout << "evil \n";
    std::cout << "chilling\n";


 
   
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 3214);
    std::cout << "chilling\n";
    A.end();
    std::cout << "chilling1\n";
    A.prev();
    std::cout << "current val is "<< A.currentVal()<<"\n";
    std::cout << "current key is "<< A.currentKey()<<"\n";
    A.prev();
    std::cout << "current val is "<< A.currentVal()<<"\n";
    std::cout << "current key is "<< A.currentKey()<<"\n";
    A.prev();
    std::cout << "current val is\n ";
    if (A.hasCurrent())
      std::cout << "evil";
    std::cout << "chilling\n";
    
    
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("c", 16);
    A.setValue("d", 176);
    A.setValue("e", 3214);
    A.begin();
    A.next();
    A.next();
    std::cout << "current val is "<< A.currentVal()<<"\n";
    std::cout << "current key is "<< A.currentKey()<<"\n";
    A.next();
    A.next();
    A.next();
    if (A.hasCurrent())
      std::cout<<"wrong\n";
    std::cout <<"chilling \n";

    
   
    A.setValue("d", 1);
    A.setValue("b", 5);
    A.setValue("c", 16);
    A.setValue("f", 176);
    A.setValue("e", 3214);

    A.end();

    

    std::cout << "current val is "<< A.currentVal()<<"\n";
    std::cout << "current key is "<< A.currentKey()<<"\n";

    A.remove("f");
    A.end();
    std::cout << "current val is "<< A.currentVal()<<"\n";
    std::cout << "current key is "<< A.currentKey()<<"\n";
    



        
    A.setValue("d", 1);
    A.setValue("b", 5);
    A.setValue("c", 16);
    A.setValue("f", 176);
    A.setValue("e", 3214);

    A.begin();
    
    std::cout << "current val is "<< A.currentVal()<<"\n";
    std::cout << "current key is "<< A.currentKey()<<"\n";

    A.remove("b");
    A.begin();

    std::cout << "current val is "<< A.currentVal()<<"\n";
    std::cout << "current key is "<< A.currentKey()<<"\n";

    
    A.setValue("c", 3);
    A.setValue("b", 2);
    A.setValue("a", 1);
    A.begin();
    A.clear();
    if (A.size() != 0) {
      std::cout << "evil \n";
    }
    try {
      A.currentKey();
      std::cout << "evil \n";
    } 
    catch(const std::logic_error& e){
        std::cout << "yuh";
    }
   
    A.setValue("c", 3);
    A.setValue("a", 1);
    A.setValue("b", 2);
    A.remove("a");
    if (A.size() != 2)
      std::cout << "evil \n";
    A.setValue("e", 5);
    A.remove("c");
    if (A.size() != 2)
      std::cout << "evil \n";
    std::cout << "hy \n";


    */
    /*
    std::cout << "size is"<< A.size()<<"\n";
    A.setValue("a", 1);
    A.setValue("b", 2);
    A.setValue("c", 3);
    A.setValue("e", 5);
    std::cout << "size is"<< A.size()<<"\n";
    */
    /*
    A.setValue("c", 3);
    A.setValue("a", 1);
    A.setValue("b", 2);
    A.remove("a");
    std::cout << "size is"<< A.size()<<"\n";    
    A.setValue("e", 5);
    A.remove("c");
    std::cout << "size is"<< A.size()<<"\n";
    



    /*
    //printf("is this working\n");
    
    //std::cout <<D.to_string() << " was first string\n";
    //printf("is this working2\n");
    D.setValue("c", 1);
    D.setValue("b",21);
    D.setValue("a", 3);
    std::cout<<D.to_string() << " was sec string\n";
    //printf("is this working3\n");
    
    
    //std::cout<<D.to_string()<< " was 3 string\n";
    D.setValue("r", 4);
    
    
    
    std::cout<<D.to_string()<< " was 4 string\n";

    D.setValue("k",5);
    std::cout<<D.to_string()<< " was 4 string\n";
    
    D.setValue("g",32);
    std::cout<<D.to_string()<< " was 4 string\n";
   
    
    D.remove("c");

    std::cout<<D.to_string()<< " was 5 string\n";

    D.remove("b");
    std::cout<<D.to_string()<< " was 5 string\n";
    */


    return 0;
}
