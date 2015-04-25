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
