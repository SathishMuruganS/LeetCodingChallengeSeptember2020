/*
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1. 1 <= A.length = A[0].length = B.length = B[0].length <= 30
2. 0 <= A[i][j], B[i][j] <= 1
*/

class Solution {
    int count_shift(vector<vector<int>>& A, vector<vector<int>>& B){
        int n = A.size();
        int count = 0;
        
        for (int i = 0;i < n; i++){
            for (int j = 0; j < n; j++){
                int temp = 0;
                for (int r = j; r < n; r++){
                    for(int c = i; c < n; c++){
                        if (A[r][c] == 1 && B[r-j][c-i] == 1){
                            temp++;
                        }
                    }
                }
                count = max(count, temp);
            }
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(count_shift(A,B), count_shift(B,A));
    }
};

