/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void nFloodFill(int** result,int row,int col,int targetColor, int nRows, int nCols){
    if(row<0 || col < 0 || row >= nRows || col >= nCols ) return ;
    if(result[row][col]!= targetColor) return ;
    result[row][col]  = -1;
    nFloodFill(result,row+1,col,targetColor,nRows,nCols);
    nFloodFill(result,row-1,col,targetColor,nRows,nCols);
    nFloodFill(result,row,col+1,targetColor,nRows,nCols);
    nFloodFill(result,row,col-1,targetColor,nRows,nCols);
    
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    const int nRows = imageSize;
    const int nCols = imageColSize[0];
    int** result = malloc(sizeof(int*)*nRows);
    for(int row = 0 ; row < nRows ; row ++){
        result[row]= malloc(sizeof(int)*nCols);
    }

    for(int row = 0 ; row < nRows; row++){
        for(int col = 0 ; col < nCols ; col ++){
            result[row][col] = image[row][col];
        }
    }


    int targetColor = result[sr][sc];
    
    nFloodFill(result,sr,sc,targetColor,nRows,nCols);

    for(int row = 0 ; row < nRows; row++){
        for(int col = 0 ; col < nCols ; col ++){
            if(result[row][col] == -1 ){
                result[row][col] = color;
            }
        }
    }

    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int)*nRows);
    for(int i = 0 ; i < nRows ; i ++){
        (*returnColumnSizes)[i] = nCols;
    }

    return result ;
}
