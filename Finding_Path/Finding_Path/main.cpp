#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct point { int x, y; };

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	point *array;
};

struct Queue* createQueue(unsigned capacity)
{
	Queue *queue = (Queue*) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = 0;
	queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (point*) malloc(queue->capacity * sizeof(point));
	return queue;
}

bool isEmpty(Queue *queue)
{
	return (queue->size == 0);
}

bool isFull(Queue *queue)
{
	return queue->size == queue->capacity;
}

void enqueue(Queue *queue, point item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size += 1;
}

point dequeue(Queue *queue)
{
	if (isEmpty(queue))
		return { INT_MIN, INT_MIN };
	point item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -= 1;
	return item;
}

point front(Queue *queue)
{
	if (isEmpty(queue))
		return { INT_MIN, INT_MIN };
	return queue->array[queue->front];
}

point rear(Queue *queue)
{
	if (isEmpty(queue))
		return { INT_MIN, INT_MIN };
	return queue->array[queue->rear];
}

string **create_grid(string str)
{
	ifstream fin(str);
	char buff[50];

	int n = 0;
	int m = 0;

	while (!fin.eof())
	{
		fin.getline(buff, 50);
		while (buff[n] != '\0')
			n++;
		m++;
	}

	string **grid = new string*[m];

	for (int k(0); k < m; k++)
		grid[k] = new string[n];

	fin.clear();
	fin.seekg(0, ios::beg);

	for (int i(0); i < m; i++)
	{
		fin.getline(buff, 50);
		for (int j(0); j < n; j++)
		{
			grid[i][j] = buff[j];
		}
	}
	return grid;
}

void reconstruct(string **grid, int **dir, point start, point finish, int last)
{
	int di[4] = { -1,0,1,0 };
	int dj[4] = { 0,1,0,-1 };
	int **d = dir;
	Queue *queue = createQueue(100);
	enqueue(queue, finish);
	int l = last;
	int ch = 66;

	while (!isEmpty(queue))
	{
		point p = dequeue(queue);
		for (int k(0); k < 4; k++)
		{
			point newp = { p.x + di[k],p.y + dj[k] };
			if (dir[newp.x][newp.y] == l - 1 || l == 0)
			{
				grid[newp.x][newp.y] = (char)ch;
				enqueue(queue, newp);
				l--;
				ch++;
			}
		}
	}
	grid[finish.x][finish.y] = (char)65;
	for (int f(0); f < 8; f++)
	{
		for (int g(0); g < 8; g++)
			cout << grid[f][g];
		cout << endl;
	}
}


void Djicstra(string **grid, int m, int n, point start, point finish)
{
	int di[4] = { -1,0,1,0 };
	int dj[4] = { 0,1,0,-1 };
	int i = 0, j = 0;
	int **d = new int*[m];
	for (int k(0); k < m; k++)
		d[k] = new int[n];

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			d[i][j] = 0;

	d[start.x][start.y] = 1;

	Queue *queue = createQueue(m * n);
	enqueue(queue, start);

	while (!isEmpty(queue))
	{
		point p = dequeue(queue);
		for (int k(0); k < 4; k++)
		{
			point newp = { p.x + di[k],p.y + dj[k] };
			if (0 <= newp.x && newp.x < m && 0 <= newp.y && newp.y < n)
				if (grid[newp.x][newp.y] == " " && d[newp.x][newp.y] == 0)
				{
					d[newp.x][newp.y] = d[p.x][p.y] + 1;
					enqueue(queue, newp);
				}
		}
	}
	reconstruct(grid, d, start, finish, d[finish.x][finish.y]);
}


int main()
{
	string **grid = create_grid("C:\\Users\\den27\\Desktop\\labirint.txt");
	Djicstra(grid, 8, 8, { 6,1 }, { 1,6 });
	grid[6][1] = "a";
	grid[1][6] = "a";

	/*for (int i(0); i < 8; i++)
	{
		for (int j(0); j < 8; j++)
			cout << grid[i][j];
		cout << endl;
	}*/

	system("pause");
	return 0;
}