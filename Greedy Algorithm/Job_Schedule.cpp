#include <iostream>
using namespace std;

int main()
{
    int job[10], deadline[10], profit[10], result[10], total_Profit = 0, temp;
    int n, i, j;

    cout << "Enter the number of jobs : ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        job[i] = i;
        cout << "Enter Deadline and Profit for job-" << i + 1 << " : ";
        cin >> deadline[i] >> profit[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = deadline[j];
                deadline[j] = deadline[i];
                deadline[i] = temp;

                temp = job[j];
                job[j] = job[i];
                job[i] = temp;
            }
        }
    }

    int max = deadline[0];
    for (i = 1; i < n; i++)
    {
        if (deadline[i] > max)
        {
            max = deadline[i];
        }
    }

    for (i = 0; i < max; i++)
    {
        result[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = deadline[i] - 1; j >= 0; j--)
        {
            if (result[j] == -1)
            {
                result[j] = job[i];
                total_Profit += profit[i];
                break;
            }
        }
    }

    cout << "\nJob Sequence : ";
    for (i = 0; i < max; i++)
    {
        if (result[i] != -1)
        {
            cout << "job-" << result[i] + 1 << "  ";
        }
    }
    cout << "\nTotal benefit is : " << total_Profit << endl;

    return 0;
}