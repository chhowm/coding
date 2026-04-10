#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int item, bagCapacity;

    cin >> item >> bagCapacity;

    vector<pair<int,int>> dividedItem;
    vector<int> dynamicProg(bagCapacity + 1, 0);

    for(int i=1; i<=item; i++)
    {
        int itemWeight, itemValue, itemCnt;
        cin >> itemWeight >> itemValue >> itemCnt;
        
        for(int j = 1; itemCnt > 0; j <<= 1)
        {
            int num = min(j,itemCnt);
            dividedItem.push_back({num * itemWeight, num * itemValue});
            itemCnt -= num;
        }
    }

    for(const auto&item : dividedItem)
    {
        for(int i = bagCapacity; i >= item.first; i--)
        {
            dynamicProg[i] = max(dynamicProg[i], dynamicProg[i-item.first] + item.second);
        }
    }

    cout << dynamicProg[bagCapacity];

    return 0;
}