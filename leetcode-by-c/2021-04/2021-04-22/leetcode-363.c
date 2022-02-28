#include<limits.h> /* INT_MIN INT_MAX */

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k){
    int preSum[matrixSize][*matrixColSize];
    for(int i=0; i<matrixSize; i++){
        preSum[i][0] = matrix[i][0];
    }
    for(int i=0; i<matrixSize; i++){
        for(int j=1; j<*matrixColSize; j++){
            preSum[i][j] = preSum[i][j-1]+matrix[i][j];
        }
    }
    int ret = INT_MIN;
    for(int i=0; i<matrixSize; i++){
        for(int left=0; left<*matrixColSize; left++){
            for(int right=left; right<*matrixColSize; right++){
                int tmp = 0;
                for(int down=i; down<matrixSize; down++){
                    tmp += (preSum[down][right]-preSum[down][left]+matrix[down][left]);
                    if(tmp<=k){
                        ret = ret<tmp?tmp:ret;
                    }
                }
            }
        }
    }
    return ret;
}