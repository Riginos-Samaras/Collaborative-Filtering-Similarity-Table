#include "similarityMatrix.h"
#include <iterator>

        similarityMatrix::similarityMatrix(){
        }
        similarityMatrix::similarityMatrix(int x,int y){
                N=x;
                M=y;
                
                double** ary2 = new double*[N];
                category_user_Table=ary2;
                for(int i = 0; i < N; ++i)
                    category_user_Table[i] = new double[M];

                // fill
                for(int i = 0; i < N; ++i)
                  for(int j = 0; j < M; ++j)
                    category_user_Table[i][j] = 0;

               
        }
        void similarityMatrix::printMatrix(){
        
             // print
                for(int i = 0; i < N; ++i){
                    
                  std::cout <<i<<"-> ";
                  for(int j = 0; j < M; ++j){
                    std::cout << category_user_Table[i][j];
                    if(j==M-1){
                        std::cout <<" <-"<< j;
                    }
                  }
                  std::cout <<"\n";
                }
        
        }
        
        
        void similarityMatrix::changeValueofMatrixAt(int i,int j, double Value){
            if(i>N){
                return ;
            }
            if(j>M){
                return ;
            }
                
            category_user_Table[i][j]=Value;     
        }