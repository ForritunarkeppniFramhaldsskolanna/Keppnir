#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int h, w, d;
    cin >> h >> w >> d;

    int total_height = h + d - 1;
    int total_width = w + d - 1;

    vector<string> box(total_height, string(total_width, ' '));

    // Draw front face
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if ((i == 0 || i == h - 1) && (j == 0 || j == w - 1)) {
                box[i][j] = '+';
            } else if (i == 0 || i == h - 1) {
                box[i][j] = '-';
            } else if (j == 0 || j == w - 1) {
                box[i][j] = '|';
            }
        }
    }

    // Draw depth lines
    for (int i = 0; i < d - 1; ++i) {
        for (int j = 0; j < 4; ++j) {
            int row, col;
            if (j == 0) {
                row = i;
                col = w - 1 + i;
            } else if (j == 1) {
                row = i;
                col = i;
            } else if (j == 2) {
                row = h - 1 + i;
                col = i;
            } else {
                row = h - 1 + i;
                col = w - 1 + i;

            }
           if (box[row][col] == ' ') {
                box[row][col] = '/';

           }else if(box[row][col] == '-' || box[row][col] == '|'){
               box[row][col] = 'x';
            }
        }
    }
       

    // Draw back face
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int row = d - 1 + i;
            int col = d - 1 + j;
            if ((i == 0 || i == h - 1) && (j == 0 || j == w - 1)) {
                if(box[row][col] == ' ' || box[row][col]=='/'){
                     box[row][col] = '+';
                }
            } else if (i == 0 || i == h - 1) {
                if(box[row][col] == ' ' || box[row][col] == '/'){
                   box[row][col] = '-';
                } else if(box[row][col] == '|'){
                  box[row][col] = 'x';  
                }
            } else if (j == 0 || j == w - 1) {
              if(box[row][col] == ' ' || box[row][col] == '/'){
                box[row][col] = '|';
              }else if (box[row][col] == '-'){
                   box[row][col] = 'x';
              }
            }
        }
    }

    // Print the box
    for (int i = 0; i < total_height; ++i) {
        cout << box[i] << endl;
    }

    return 0;
}
