#include <iostream>
using namespace std;

int main()
{
    int start[10], end[10], selected[10], n, i, j, count = 0;

    cout << "Enter the number of jobs: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter start and end time of job-" << i + 1 << ": ";
        cin >> start[i] >> end[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (end[i] > end[j])
            {
                swap(end[i], end[j]);
                swap(start[i], start[j]);
            }
        }
    }

    int lastEnd = 0;

    cout << "\nSelected Jobs: \n";
    for (i = 0; i < n; i++)
    {
        if (start[i] >= lastEnd)
        {
            selected[count++] = i;
            lastEnd = end[i];
            cout << "Job-" << i + 1 << " [" << start[i] << ", " << end[i] << "]\n";
        }
    }

    cout << "Maximum number of non-overlapping jobs: " << count << endl;

    return 0;
}
