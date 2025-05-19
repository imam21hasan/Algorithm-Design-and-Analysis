#include <iostream>
using namespace std;

int main()
{
    float weight[10], profit[10], ratio[10], Totalvalue = 0.0, temp, capacity;
    int n, i, j;

    cout << "Enter the number of items : ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter Weight and Profit for item - " << i + 1 << " : ";
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter the Capacity : ";
    cin >> capacity;

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
        else
        {
            Totalvalue += (ratio[i] * capacity);
            break;
        }
    }

    cout << "\nTotal benefit is : " << Totalvalue << endl;
    
    return 0;
}