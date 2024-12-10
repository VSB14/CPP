class Solution
{
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {
           	
            int rowSize = matrix.size();
            int colSize = matrix[0].size();
            vector<pair<int, int>> flag;
            cout<<flag.size()<<endl;
            for (int i = 0; i < rowSize; i++)
            {
                for (int j = 0; j < colSize; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        flag.push_back(make_pair(i, j));
                    }
                }
            }
            cout<<flag.size()<<endl;
            for (const auto &it: flag)
            {
                cout << it.first << " " << it.second << endl;
            }
            if (!flag.empty())
            {
                for (auto it: flag)
                {

                    int row = it.first;
                    int column = it.second;
                    for (int n = 0; n < colSize; n++)
                    {

                        matrix[row][n] = 0;
                    }
                    for (int n = 0; n < rowSize; n++)
                    {

                        matrix[n][column] = 0;
                    }
                }
            }
        }
};