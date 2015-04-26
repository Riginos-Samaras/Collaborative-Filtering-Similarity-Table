/* 
 * File:   categoryGraph.h
 * Author: Dimitris
 *
 * Created on April 25, 2015, 6:07 PM
 */

#ifndef CATEGORYGRAPH_H
#define	CATEGORYGRAPH_H

#include "category.h"

class categoryGraph{
    private:
         std::vector<category> categoryList;
    public:  
        categoryGraph();  
        void insertCategory(int,int);
        void printNodes();
        int getIDof(int);
        int getNameof(int);
        void setLabelof(int,std::string);
        std::vector<category> getcategoryList();
};
#endif	/* NODEGRAPH_H */





