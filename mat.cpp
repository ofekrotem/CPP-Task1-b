/**
 * Author: Ofek Rotem
 * Since : 2022-03
 */

#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace ariel {

    int min(int a, int b)
    {
        if(a>b) {return b;}
        return a;
    }
    string mat(int col, int row, char firstSym, char secondSym) {
        const int low_limit_ascii = 33;
        const int high_limit_ascii = 126;
        if (col %2 == 0 || row%2==0) {__throw_invalid_argument("Enter only odd row and column size");}
        if (col<=0 || row<=0) {__throw_invalid_argument("Enter positive row and column size");}
        if (firstSym<low_limit_ascii || firstSym>high_limit_ascii || secondSym<low_limit_ascii || secondSym>high_limit_ascii) {__throw_invalid_argument("Enter valid symbol");}
        vector<vector<char>> matrix(row, vector<char>(col));
        int layer=0;
        char to_place='.';
        int max_layer=(min(row,col)/2)+1;
        for(layer=0;layer<max_layer;layer++)
        {
            if(layer%2==0) {to_place=firstSym;}
            else {to_place=secondSym;}
            for(int i=layer;i<col-layer;i++)
            {
                matrix[layer][i]=to_place;
            }
            for(int j=layer;j<row-layer;j++)
            {
                matrix[j][layer]=to_place;
            }
            int k=layer;
            for(int i=row-layer-1;k<col-layer;k++)
            {               
                matrix[i][k]=to_place;
            }
            k=layer;
            for(int j=col-layer-1;k<row-layer;k++)
            {
                matrix[k][j]=to_place;
            }            
        }
        string ans="0";
        bool flag=true;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(flag){ans=matrix[i][j];}
                else {ans+=matrix[i][j];}
                flag=false;
                
            }
            if(i!=row-1) { ans+="\n";}
        }
        return ans;
    }  
}

//  int main()
//     {
//         int col=0;
//         std::cin >> col;
//         int row=0;
//         std::cin >> row;
//         std::cout << ariel::mat(col,row,'O','R'); 
//         return 0;
//     }