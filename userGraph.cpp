#include "userGraph.h"
#include <iterator>

        userGraph::userGraph(){
        }
        void userGraph::insertUser(int nodeID,int nodeName){      
            user *inputNode=new user(nodeID, nodeName);
            userList.push_back(*inputNode);
        }
        
        void userGraph::printNodes(){   
            
            for( int i= 0; i <userList.size(); ++i){
               std::cout<<"\n";   
               std::cout<<userList[i].getID();
               std::cout<<"::"<<userList[i].getName();
            }
        }
 
       int userGraph::getIDof(int NAME){
            
            
            for( int i= 0; i <userList.size(); ++i){
                if(userList[i].getName()==NAME){
                    return userList[i].getID();             
                }
            }
            return 12345;
        }

        int userGraph::getNameof(int ID){      
            for( int i= 0; i <userList.size(); ++i){
                if(userList[i].getID()==ID){
                    return userList[i].getName();             
                }
            }
            return 0;
        }

        std::vector<user> userGraph::getuserList(){
            return userList;
        }
