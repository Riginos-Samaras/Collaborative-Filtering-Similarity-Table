#include "category.h" 

   category::category(){
   }
   category::category(int Id,int nam){
       id=Id;
       name=nam;
   }
   
    int category::getName(){
       return name;
   }
   void category::setName(int nam){
       name=nam;
   }
   
   int category::getID(){
       return id;
   }
   void category::setID(int Id){
       id=Id;
   }
   void category::setLabel( std::string L){
       L.replace(L.begin(),L.begin()+1,"");  
       L.replace(L.end()-1,L.end(),"");  
       label=L;
   }
  
   std::string category::getLabel(){
       return label;
   }