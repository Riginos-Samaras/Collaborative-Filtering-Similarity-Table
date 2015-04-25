    /* 
 * File:   userGraph.h
 * Author: Dimitris
 *
 * Created on April 25, 2015, 6:21 PM
 */

#ifndef USERGRAPH_H
#define	USERGRAPH_H

#include "user.h"

class userGraph{
    private:
         std::vector<user> userList;
    public:  
        userGraph();  
        void insertUser(int,int);
        void printNodes();
        int getIDof(int);
        int getNameof(int);
        std::vector<user> getuserList();
};
#endif	/* NODEGRAPH_H */


