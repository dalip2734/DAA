#include <iostream>
using namespace std;

void MaxActivitiesSelect(int s[], int f[], int n)
{
	int i, j;

	cout << "Following activities are selected" << endl;
	i = 1;
	cout << i << " ";
	for (j = 1; j <= n; j++)
	{
		if (s[j] >= f[i])
		{
			cout << j << ",";
			i = j;
		}
	}
}

int main()
{
	int n;
	cout << "Enter the number of Activities :";
	cin >> n;
	int start[n];
	cout << "Enter start Time :" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "A" << i << "=";
		cin >> start[i];
	}
	cout << "Enter finish Time :" << endl;
	int finish[n];
	for (int i = 1; i <= n; i++)
	{
		cout << "A" << i << "=";

		cin >> finish[i];
	}
	MaxActivitiesSelect(start, finish, n);
	return 0;
}


// input value :
//starting time : 

// Time Complexity: O(N)
// Auxiliary Space: O(1)
