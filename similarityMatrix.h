/* 
 * File:   similarityMatrix.h
 * Author: Dimitris
 *
 * Created on April 25, 2015, 6:54 PM
 */

#ifndef SIMILARITYMATRIX_H
#define	SIMILARITYMATRIX_H

#include "category.h"

class similarityMatrix{
    
    private:
        double** category_user_Table ;
        double** category_category_similarity_Table ;
        int N=0;
        int M=0;
        // std::vector<category> categoryList;
    public:  
        similarityMatrix();  
        similarityMatrix(int,int);
        void printMatrix();
        void printsimilarityMatrix();
        void changeValueofMatrixAt(int i,int j, double Value);
        float averageRatingat(int);
        void similarityAlgorithm();
        double** getSimilarityMatrix();
};
#endif	/* SIMILARITYMATRIX_H */

