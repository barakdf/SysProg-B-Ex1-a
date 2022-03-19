//
// Created by barak on 15/03/2022.
//

#include <iostream>
#include "mat.hpp"

int t_col = 0, t_row = 0;

namespace ariel {

    void sym(std::string *matrix[t_col], int l_t, int l_b, int r_t, char s1) {
        for (int k = l_t + 1; k < r_t - l_t - 1; ++k) {
            matrix[k][l_t] = ""+s1;
            matrix[k][l_b] = ""+s1;
        }

        for (int k = l_t; k < l_t - l_b; ++k) {
            matrix[l_t][k] = s1;
            matrix[r_t][k] = s1;
        }

        if ((l_t-l_b) > 1 && (r_t - l_t) > 1) {
            sym(matrix, l_t + 2, l_b - 2, r_t - 2, s1);
        }
    }


    std::string mat(int col, int row, char s1, char s2) {
//        t_row += row;
//        std::string matrix[] = new std::string [row][10];
//        t_col += col;
//
//        sym(matrix, 0, row, col, s1);
//        sym(matrix, 1, row - 1, col - 1, s2);

        std::string ans;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
//                ans += matrix[j][i];
            }
            ans += '\n';
        }

        return ans;

    }

}

int main() {
    std::cout << ariel::mat(9, 7, '@', '-') << std::endl;
    std::cout << "hello world" << std::endl;
}

