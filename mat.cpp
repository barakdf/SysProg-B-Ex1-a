//
// Created by barak on 15/03/2022.
//

#include <vector>
#include <iostream>
#include <exception>
#include "mat.hpp"

namespace ariel {
    int max(int col, int row) {
        if (col > row) {
            return col;
        }
        return row;
    }
    int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }

    std::string mat(int col, int row, char s1, char s2) {
        if(row % 2 == 0 || col % 2 == 0) {
            throw std::invalid_argument("Mat size is always odd");
        }
        if (row <= 0 || col <= 0) {
            throw std::invalid_argument("Mat should be positive");
        }
        if ((int) s1 <= 32 || (int) s2 <= 32) {
            throw std::invalid_argument("Invalid symbols");
        }
        int l_mat[row][col];
        int r_mat[row][col];

        for (int i = 0; i < max(col, row); ++i) {
            if (i < row) {
                for (int j = i; j < col; ++j) {
                    l_mat[i][j] = i;
                    r_mat[row - 1 - i][col - 1 - j] = i;
                }
            }
            if (i < col) {
                for (int j = i; j < row; ++j) {
                    l_mat[j][i] = i;
                    r_mat[row - 1 - j][col - 1 - i] = i;
                }
            }

        }

        std::string ans;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int bin = min(l_mat[i][j], r_mat[i][j]) % 2;
                if (bin == 0) {
                    ans += s1;
                } else {
                    ans += s2;
                }
            }
            ans += '\n';
        }
        return ans;
    }
}

