class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Top row se diagonals
        for (int col = 0; col < n; col++) {
            vector<int> diag;

            int i = 0, j = col;

            while (i < m && j < n) {
                diag.push_back(mat[i][j]);
                i++;
                j++;
            }

            sort(diag.begin(), diag.end());

            i = 0;
            j = col;
            int k = 0;

            while (i < m && j < n) {
                mat[i][j] = diag[k++];
                i++;
                j++;
            }
        }

        // Left column se diagonals
        for (int row = 1; row < m; row++) {
            vector<int> diag;

            int i = row, j = 0;

            while (i < m && j < n) {
                diag.push_back(mat[i][j]);
                i++;
                j++;
            }

            sort(diag.begin(), diag.end());

            i = row;
            j = 0;
            int k = 0;

            while (i < m && j < n) {
                mat[i][j] = diag[k++];
                i++;
                j++;
            }
        }

        return mat;
    }
};