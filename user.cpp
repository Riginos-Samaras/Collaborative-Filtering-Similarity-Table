#include "user.h" 

   user::user(){
   }
   user::user(int Id,int nam){
       id=Id;
       name=nam;
   }
   
    int user::getName(){
       return name;
   }
   void user::setName(int nam){
       name=nam;
   }
   
   int user::getID(){
       return id;
   }
   void user::setID(int Id){
       id=Id;
   }