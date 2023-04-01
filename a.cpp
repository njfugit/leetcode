/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               神兽保佑            永无BUG
 *
 * @Author: Jack
 * @Date: 2022-09-17 14:44:15
 * @LastEditTime: 2022-10-06 14:35:22
 * @LastEditors: your name
 * @FilePath: /.leetcode/a.cpp
 */

#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

/* class Node {
public:
    // Node() {}
    Node(int x, int y) : x(x), y(y) {}
    bool operator<(const Node &node) const {
        return this->y == node.y ? this->x > node.x : this->y < node.y;
    }

public:
    int x;
    int y;
}; */
// void removespace(string &s) {
//     int slow = 0;
//     for (int i = 0; i < s.size(); ++i) {
//         if (s[i] != ' ') {
//             if (slow != 0) s[slow++] = ' ';
//             while (i < s.size() && s[i] != ' ') {
//                 s[slow++] = s[i++];
//             }
//         }
//     }
//     s.resize(slow);
// }
/**
 * @description: conv2d
 * @param {int} x
 * @param {int} y
 * @param {int} offsetr
 * @param {int} offsetc
 * @return {*}
 */
int conv2d(int x, int y, int offsetr, int offsetc, const vector<vector<int>>& matrix, const vector<vector<int>>& filter) {
    int temp = 0;
    for (int i = x - offsetr; i < x + offsetr + 1; i++) {
        if (i < 0 || i >= matrix.size()) continue;
        for (int j = y - offsetc; j < y + offsetc + 1; j++) {
            if (j < 0 || j >= matrix[0].size()) continue;
            temp += matrix[i][j] * filter[i - x + offsetr][j - y + offsetc];
        }
    }
    if (temp < 0)
        temp = 0;
    else if (temp > 255)
        temp = 255;
    else
        return temp;
}


int main() {
    // auto cmp = [](int val1, int val2) { return val1 < val2; };
    // std::priority_queue<int, vector<int>, decltype(cmp)> queue_cmp(cmp);
    // queue_cmp.push(1);
    // queue_cmp.push(2);
    // queue_cmp.push(3);
    // queue_cmp.push(4);

    // while (!queue_cmp.empty()) {
    //     int top = queue_cmp.top();
    //     cout << top << "\t";
    //     queue_cmp.pop();
    // }
    // cout << endl;
    // string ss = "  a   rer  faf ";
    // removespace(ss);
    // cout << ss << endl;

    /* int n = 0;
    cin >> n;
    vector<Node> vn;
    vector<Node> result;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vn.push_back(Node(a, b));  // x降序 y升序
    }
    for (auto v : vn) {
        cout << v.x << "," << v.y << endl;
    }
    result.push_back(vn[vn.size() - 1]);

    int maxx = vn[vn.size() - 1].x;
    for (int i = vn.size() - 2; i >= 0; i--) {
        if (vn[i].x > maxx) {
            result.push_back(vn[i]);
            maxx = vn[i].x;
        }
    }
    for (auto v : result) {
        cout << v.x << "," << v.y << endl;
    } */

    // int m, n, k, l;    //conv2d
    // cin >> m >> n >> k >> l;
    // vector<vector<int>> matrix(m, vector<int>(n));
    // vector<vector<int>> filter(k, vector<int>(l));
    // vector<vector<int>> result(m, vector<int>(n));
    // for (int i = 0; i < m; i++)
    //     for (int j = 0; j < n; j++)
    //         cin >> matrix[i][j];
    // for (int i = 0; i < k; i++)
    //     for (int j = 0; j < l; j++)
    //         cin >> filter[i][j];

    // for (int i = 0; i < m; i++)
    //     for (int j = 0; j < m; j++)
    //         result[i][j] = conv2d(i, j, k / 2, l / 2, matrix, filter);
    // for (auto a : result) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }


    return 0;
}
