/* 
 * File:   user.h
 * Author: Dimitris
 *
 * Created on April 25, 2015, 5:41 PM
 */

#ifndef USER_H
#define	USER_H
#include <vector>
#include <string>
#include <iostream>
#include <set>

#ifdef	__cplusplus
extern "C" {
#endif

using namespace::std; 
class user{

 private:
    int id;
    int name;
 public:
    
    user();
    user(int,int);
    int getID();
    void setID(int);
    int getName();
    void setName(int);
    
};



#ifdef	__cplusplus
}
#endif

#endif	/* USER_H */

