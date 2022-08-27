/*___________this code is generic you just changed da static memory to dynmaic and read data from file _____________*/
struct index {
	int x = 0, y = 0;
	index(int row, int col)
	{
		x = row; y = col;
	}
};
#include<iostream>
#include<stack>//using builtin stack
#include<fstream>
using namespace std;
stack<index> solution(int[][4],int s);
void makesolution(stack<index> obj);
void display(int arr[][4]);
int sol[4][4] = { {0},{0},{0},{0} };
int main()
{
	int maze[4][4]= { {1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1} };//you can read data from file 
	cout << "Original Maze\n\n";
	display(maze);
	stack<index> stakso = solution(maze, 4);
	makesolution(stakso);
	cout << "\n\n Solved Path\n\n";
	display(sol);
	cout << endl;

}
stack<index> solution(int arr[][4],int s)
{
	stack<index> temp;
	int x = 0;
	int y = 0;
	if (arr[x][y] == 0)
	{
		return temp;
	}
	else {
		index obj(x, y);
		temp.push(obj);

		while (true)
		{
			if (x - 1 >= 0 && arr[x - 1][y] != 0 && arr[x - 1][y] != -1)
			{
				index obj(x - 1, y);
				temp.pop();
				
				arr[x - 1][y] = -1;
				x--;


			}
			else if (y - 1 >= 0 && arr[x][y - 1] != 0 && arr[x][y - 1] != -1)
			{
				index obj(x, y - 1);
				temp.pop();
				arr[x][y - 1] = -1;
				y--;

			}
			else if (y + 1 < s && arr[x][y + 1] != 0 && arr[x][y + 1] != -1)
			{
				index obj(x, y + 1);
				temp.push(obj);
				y++;

			}
			else if (x + 1 < s && arr[x + 1][y] != 0 && arr[x + 1][y] != -1)
			{
				index obj(x + 1, y);
				temp.push(obj);
				x++;
			}
			else
			{
			}
			if (x == s - 1 && y == s - 1)
			{
				return temp;
			}
		}
	}
}
void makesolution(stack<index> obj)
{
	int size = 4;
	index temp(0, 0);
	while (!obj.empty())
	{
		temp = obj.top();
		obj.pop();
		sol[temp.x][temp.y] = 1;
	}
	
}
void display(int arr[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}