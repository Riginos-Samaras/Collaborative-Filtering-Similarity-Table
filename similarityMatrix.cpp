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

               double** arysim = new double*[N];
                category_category_similarity_Table=arysim;
                for(int i = 0; i < N; ++i)
                    category_category_similarity_Table[i] = new double[N];     
               
                // fill
                for(int i = 0; i < N; ++i)
                  for(int j = 0; j < M; ++j)
                    category_user_Table[i][j] = 0;
                
                 // fill
                for(int i = 0; i < N; ++i)
                  for(int j = 0; j < N; ++j)
                    category_category_similarity_Table[i][j] = 0;

               
        }
        void similarityMatrix::printMatrix(){
        
             // print
                for(int i = 0; i < N; ++i){
                    
                  std::cout <<i<<"-> ";
                  for(int j = 0; j < M; ++j){
                    std::cout << category_user_Table[i][j];
                    if(j==M-1){
                        std::cout <<" <-"<< j<<" AR:"<<averageRatingat(i);
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
        
        float similarityMatrix::averageRatingat(int i){
            float num=0;
            float sum=0;
            for(int j = 0; j < M; ++j){
                if(category_user_Table[i][j]!=0){
                    num++;
                }
                sum=sum+category_user_Table[i][j];
            }
            //std::cout<<"sum"<<sum<<"num"<<num;
            return sum/num;
            
        }
        
        
        
        void similarityMatrix::similarityAlgorithm(){
            //category_category_similarity_Table;
            
            
            for(int x = 0; x < N; ++x){
                for(int y = 0; y < N; ++y){
                    
                    
                    
            }
            }
        
        }
        
        void similarityMatrix::printsimilarityMatrix(){
        
             // print
                for(int i = 0; i < N; ++i){
                    
                  std::cout <<i<<"-> ";
                  for(int j = 0; j <= N; ++j){
                    std::cout << category_category_similarity_Table[i][j];
                    if(j==N-1){
                        std::cout <<" <-"<< j;
                    }
                  }
                  std::cout <<"\n";
                }
        
        }