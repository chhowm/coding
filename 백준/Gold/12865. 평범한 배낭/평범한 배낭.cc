#include <iostream>
#include <algorithm>

using namespace std;

int weight[101];
int value[101];
int dynamicP[101][100001];

int main()
{
    int packNum;
    int maxWeight;
    cin >> packNum >> maxWeight;

    for(int i=1; i<=packNum; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for(int i=1; i<=packNum; i++)
    {
        for(int j=1; j<=maxWeight; j++)
        {
            if(weight[i] <= j)
            {
                dynamicP[i][j] = max(dynamicP[i-1][j], dynamicP[i-1][j-weight[i]]+value[i]);
            }
            else
            {
                dynamicP[i][j] = dynamicP[i-1][j];
            }
        }
    }

    cout << dynamicP[packNum][maxWeight] << endl;

    return 0;
}