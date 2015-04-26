/* 
 * File:   category.h
 * Author: Dimitris
 *
 * Created on April 25, 2015, 5:48 PM
 */

#ifndef CATEGORY_H
#define	CATEGORY_H

#include <vector>
#include <string>
#include <iostream>
#include <set>
 


#ifdef	__cplusplus
extern "C" {
#endif

using namespace::std; 
class category{

 private:
    int id;
    int name;
    std::string label;
 public:
    
    category();
    category(int,int);
    int getID();
    void setID(int);
    int getName();
    void setName(int);
    void setLabel(std::string);
    std::string getLabel();
    
};


#ifdef	__cplusplus
}
#endif

#endif	/* CATEGORY_H */

