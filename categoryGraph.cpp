#include "categoryGraph.h"
#include <iterator>

        categoryGraph::categoryGraph(){
        }
        void categoryGraph::insertCategory(int nodeID,int nodeName){      
            category *inputNode=new category(nodeID, nodeName);
            categoryList.push_back(*inputNode);
        }
        
        void categoryGraph::printNodes(){   
            
            for( int i= 0; i <categoryList.size(); i++){
               std::cout<<"\n";   
               std::cout<<categoryList[i].getID();
               std::cout<<"::"<<categoryList[i].getName();
            }
        }
 
    
        int categoryGraph::getIDof(int NAME){
            
            
            for( int i= 0; i <categoryList.size(); i++){
                if(categoryList[i].getName()==NAME){
                    return categoryList[i].getID();             
                }
            }
            return 0;
        }

        int categoryGraph::getNameof(int ID){      
            for( int i= 0; i <categoryList.size(); i++){
                if(categoryList[i].getID()==ID){
                    return categoryList[i].getName();             
                }
            }
            return 0;
        }

        
        std::vector<category> categoryGraph::getcategoryList(){
            return categoryList;
        }