#include "user.h"
#include "categoryGraph.h"
#include "similarityMatrix.h"
#include "userGraph.h"
#include <curses.h>
#include <iostream>
#include <stdio.h>
#include <valarray>
#include <iomanip>      // std::setprecision
#include <cstdlib> 
#include <iostream>
#include <fstream>
#include <string>     // std::string, std::stoi
#include <vector>

using namespace std;

#include <algorithm>    // std::max
#include <dirent.h>

using namespace::std; 
int main(int argc, char**argv)
{
    
    ofstream similarityfile;
    similarityfile.open ("datasets/similaritiesBetweenCategories.txt");
   
    std::string::size_type sz;   // alias of size_t
    std::string str_dec = "2001";
    int i_dec = std::stoi (str_dec,&sz);
    
    categoryGraph CG;
    userGraph UG;

    CG.insertCategory(1,2);
    
    CG.printNodes();
    
    
    
    
    
    
    std::ifstream Users("datasets/U.txt");
    std::ifstream UserCategoriesRating("datasets/category_ratings.txt");
    std::ifstream Categories("datasets/C.txt");
    std::ifstream CategoriesLabels("datasets/C_String.txt");
    
    std::string line;
    std::string tokenOne;
    std::string tokenTwo;
    std::string tokenThree;
   
    //USERS PARSER
    for( std::string line; getline( Users, line ); ){
    size_t pos = 0;
    std::string delimiter = ",";
    std::string token; 
    int i=0;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        tokenOne=token;
        line.erase(0, pos + delimiter.length());
    }
    tokenTwo=line; 
    
    UG.insertUser(std::stoi (tokenOne,&sz),std::stoi (tokenTwo,&sz));
    
    
    }   
  
    //CATEGORIES PARSER
    for( std::string line; getline( Categories, line ); ){
    size_t pos = 0;
    std::string delimiter = ",";
    std::string token; 
    int i=0;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        tokenOne=token;
        line.erase(0, pos + delimiter.length());
    }
    tokenTwo=line; 
    
    CG.insertCategory(std::stoi (tokenOne,&sz),std::stoi (tokenTwo,&sz));
    
    
    }   
    
    //CATEGORIES LABEL PARSER
    for( std::string line; getline( CategoriesLabels, line ); ){
    size_t pos = 0;
    std::string delimiter = ",";
    std::string token; 
    int i=0;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        tokenOne=token;
        line.erase(0, pos + delimiter.length());
    }
    tokenTwo=line; 
    CG.setLabelof(std::stoi (tokenOne,&sz),tokenTwo);
  //  CG.insertCategory(std::stoi (tokenOne,&sz),std::stoi (tokenTwo,&sz));
    
    
    }  
    
    
   // UG.printNodes();
   // CG.printNodes();
    similarityMatrix Matrix(CG.getcategoryList().size()-1,UG.getuserList().size());
    int jobsPosted=0;
    //Matrix.printMatrix();
    
    
    int num=0;
    //RATING PARSER
    for( std::string line; getline( UserCategoriesRating, line ); ){
        
    size_t pos = 0;
    std::string delimiter = ",";
    std::string token; 
    int i=0;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        if(i==0)
            tokenOne=token;
        if(i==1)
            tokenTwo=token;
        i++;
        line.erase(0, pos + delimiter.length());
    }
    tokenThree=line; 
   // cout<<CG.getIDof(std::stoi(tokenOne))<<"->"<<tokenOne<<","<<UG.getIDof(std::stoi(tokenTwo))<<"->"<<tokenTwo<<","<<tokenThree<<endl;

    if(UG.getIDof(std::stoi(tokenTwo))!=12345){
    Matrix.changeValueofMatrixAt(CG.getIDof(std::stoi(tokenOne)) , UG.getIDof(std::stoi(tokenTwo)), std::stoi(tokenThree));
    jobsPosted=jobsPosted+std::stoi(tokenThree);
    
    }
   // CG.insertCategory(std::stoi (tokenOne,&sz),std::stoi (tokenTwo,&sz));
    //num
    
    }   
    
    //cout<<
    //Matrix.printMatrix();
    
   // cout<<"\n"<<CG.getcategoryList().size()<<" "<<CG.getIDof(4);
    //Matrix.similarityAlgorithm();
    Matrix.similarityAlgorithmsimple();
    //Matrix.printsimilarityMatrix();
    
    
   std::vector<category> CL=CG.getcategoryList();
   double** ST=Matrix.getSimilarityMatrix();
   
 //  Matrix.printMatrix();
   for( int x= 0; x <CL.size()-1; x++){
               //if category is deleted
               if(CL[x].getLabel()=="")continue;
               similarityfile<<"\n";
               std::cout<<"\n";   
              // std::cout<<CL[x].getName();
               
               for( int y= 0; y <CL.size(); y++){   
                 if(CL[y].getLabel()=="")continue;
                 
             //  std::cout<<<<":";
                 float val =ST[x][y];
                 float val2 =ST[x][x];
                 float totalpercentage=100*val/val2;

float rounded_down = floorf(totalpercentage * 100) / 100;   /* Result: 37.77 */
float nearest = roundf(totalpercentage * 100) / 100;  /* Result: 37.78 */
float rounded_up = ceilf(totalpercentage * 100) / 100;      /* Result: 37.78 */
                 
                    similarityfile<<"\n\t"<<CL[x].getLabel()<<" -> "<<CL[y].getLabel()<<" : "<<rounded_up<<"% ";
                    std::cout<<"\n\t"<<CL[x].getLabel()<<" -> "<<CL[y].getLabel()<<" : "<<rounded_up<<"% ";
               }
            }
   
    similarityfile.close();
 std::cout<<"\n"<<jobsPosted;
 
 
}
