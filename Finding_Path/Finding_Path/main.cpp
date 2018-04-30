#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

struct point { int x, y; };

struct item
{
	point data;
	int priority;
};

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	item *array;
};

struct Queue* createQueue(unsigned capacity)
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (item*)malloc(queue->capacity * sizeof(item));
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

void enqueue(Queue *queue, point d, int pr)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear].data = d;
	queue->array[queue->rear].priority = pr;
	queue->size = queue->size + 1;

	int s = queue->size;
	int i, j, key;
	item temp;

	for (i = 1; i < s; i++)
	{
		key = queue->array[i].priority;
		temp = queue->array[i];
		j = i - 1;
		while (j >= 0 && queue->array[j].priority < key)
		{
			queue->array[j + 1] = queue->array[j];
			j = j - 1;
		}
		queue->array[j + 1] = temp;
	}
}

point dequeue(Queue *queue)
{
	if (isEmpty(queue))
		return { INT_MIN,INT_MIN };
	point data = queue->array[queue->front].data;
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -= 1;
	return data;
}

point front(Queue *queue)
{
	if (isEmpty(queue))
		return { INT_MIN, INT_MIN };
	return queue->array[queue->front].data;
}

point rear(Queue *queue)
{
	if (isEmpty(queue))
		return { INT_MIN, INT_MIN };
	return queue->array[queue->rear].data;
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

int heuristic(point c, point f)
{
	int dx = abs(c.x - f.x);
	int dy = abs(c.y - f.y);

	return dx + dy;
}

void reconstruction(string **grid, int m, int n, point start, point finish, int **dir)
{
	int di[4] = { -1,0,1,0 };
	int dj[4] = { 0,1,0,-1 };
	int **d = dir;
	Queue *queue = createQueue(100);
	enqueue(queue, finish, 0);
	int ch = 66;

	while (!isEmpty(queue))
	{
		point p = dequeue(queue);
		if (heuristic(p, start) == 0)
			break;
		for (int k(0); k < 4; k++)
		{
			point newp = { p.x + di[k],p.y + dj[k] };
			if (dir[newp.x][newp.y] != 0)
			{
				grid[newp.x][newp.y] = (char)ch;
				enqueue(queue, newp, heuristic(newp, start));
				ch++;
			}
		}
	}
	grid[finish.x][finish.y] = (char)65;

	ofstream fout("exit.txt");
	for (int f(0); f < m; f++)
	{
		for (int g(0); g < n; g++)
			fout << grid[f][g];
		fout << endl;
	}
	fout.clear();
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
	enqueue(queue, start, heuristic(start, finish));

	point p;

	while (!isEmpty(queue))
	{
		p = dequeue(queue);
		if (heuristic(p, finish) == 0)
			break;
		//cout << p.x << " - x:y - " << p.y << " d - " << heuristic(p, finish) << endl;
		for (int k(0); k < 4; k++)
		{
			point newp = { p.x + di[k],p.y + dj[k] };
			if (0 <= newp.x && newp.x < m && 0 <= newp.y && newp.y < n)
				if (grid[newp.x][newp.y] == " " && d[newp.x][newp.y] == 0)
				{
					d[newp.x][newp.y] = d[p.x][p.y] + 1;
					enqueue(queue, newp, d[newp.x][newp.y] + heuristic(newp, finish));
				}
		}
	}

	reconstruction(grid, m, n, start, finish, d);

}

int main()
{
	string **grid = create_grid("C:\\Users\\den27\\Desktop\\labirint.txt");
	Djicstra(grid, 8, 8, { 6,1 }, { 4,1 });

	system("pause");
	return 0;
}