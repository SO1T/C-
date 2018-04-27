#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

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

vector<vector<string> > create_grid(string str, int& n, int& m)
{
	ifstream fin(str);
	char buff[50];

	n = 0;
	m = 0;

	while (!fin.eof())
	{
		fin.getline(buff, 50);
		while (buff[n] != '\0')
			n++;
		m++;
	}

	vector<vector<string> > grid;
	grid.resize(m);

	for (int k(0); k < grid.size(); k++)
		grid[k].resize(n);

	fin.clear();
	fin.seekg(0, ios::beg);

	for (int k(0); k < grid.size(); k++)
	{
		fin.getline(buff, 50);
		for (int x(0); x < grid[k].size(); x++)
		{
			grid[k][x] = buff[x];
		}
	}

	return grid;
}

vector<point> neighbors(point p, vector<vector<string> > grid, int n, int m)
{
	int x = p.x;
	int y = p.y;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	vector<point> results;

	for (int k(0); k < 4; k++)
	{
		point temp = { x + dx[k], y + dy[k] };
		if (0 <= temp.x && temp.x < n && 0 <= temp.y && temp.y < m)
			if (grid[temp.x][temp.y] != "#")
				results.push_back(temp);
	}
	return results;
}

bool operator == (point a, point b)
{
	return a.x == b.x && a.y == b.y;
}

bool operator != (point a, point b)
{
	return a.x != b.x || a.y != b.y;
}

void reconstruct(vector<vector<string> >& grid, point start, point finish, unordered_map<point, point> came_from)
{
	vector<point> path;
	point current = finish;
	path.push_back(current);
	while (current != start)
	{
		current = came_from[current];
		path.push_back(current);
	}

	int ch = 65;
	for (auto v : path)
	{
		grid[v.x][v.y] = (char)ch;
		ch++;
		if (ch == 90)
			ch = 65;
	}
}

void Dijkstra(vector<vector<string> > grid, int n, int m, point start, point finish, unordered_map<point, point>& came_from, unordered_map<point, int>& cost_so_far)
{
	Queue *queue = createQueue(n * m);
	came_from[start] = start;
	cost_so_far[start] = 0;

	while (isEmpty(queue))
	{
		auto current = front(queue);
		dequeue(queue);

		if (current == finish)
			break;

		for (auto next : neighbors(current, grid, n, m))
		{
			int new_cost = cost_so_far[current] + 1;
			if (!cost_so_far.count(next) || new_cost < cost_so_far[next])
			{
				cost_so_far[next] = new_cost;
				came_from[next] = current;
				enqueue(queue, next);
			}


		}
	}


}

int main()
{
	int n, m;
	vector<vector<string> > grid = create_grid("C:\\Users\\den27\\Desktop\\labirint.txt", n, m);
	unordered_map<point, point> came_from;
	unordered_map<point, int> cost_so_far;
	point start = { 7,2 };
	point finish = { 2, 7 };
	Dijkstra(grid, n, m, start, finish, came_from, cost_so_far);
	reconstruct(grid, start, finish, came_from);

	system("pause");
	return 0;
}