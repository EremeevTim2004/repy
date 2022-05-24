#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph
{
    int numVertices;

public:
    bool* visited;

    list<int>* adjLists;

    Graph(int V);

    void addEdge(int src, int dest);
    
    void DFS(int vertex);
    
    void BFS(int startVertex, int v);
};

// Инициализация графа
Graph::Graph(int vertices)
{
    numVertices = vertices;

    adjLists = new list<int>[vertices];
    
    visited = new bool[vertices];
    
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }
}

// Добавление ребер
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_front(dest);
}

// Алгоритм 
void Graph::DFS(int vertex)
{
    visited[vertex] = true;

    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;

    for (i = adjList.begin(); i != adjList.end(); ++i)
    {
        int temp = *i;

        if (!visited[temp])
        {
            DFS(temp);
        }
    }
}

void Graph::BFS(int startVertex, int v)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list <int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);
    vector <int> d(numVertices, -1), p(numVertices);
    d[startVertex] = 0;
    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
                d[*i] = d[adjVertex] + 1;
                p[*i] = currVertex;
            }
        }
    }

    int sum = 0;
    cout << "rez: \n";
    while (v != startVertex) {
        cout << v << endl;
        v = p[v];
        sum++;
    }
    cout << "минимальная длина = " << sum;
}

/*
* Дано дерево.
* Удалить элементы кратные Х
*/
void task1()
{
    int n;

    cout << "введите колиество вершин\n";
    cin >> n;

    Graph graph(n);

    int colR;

    cout << "введите количетсво ребер\n";
    cin >> colR;

    for (int i = 0; i < colR; i++)
    {
        int s1, s2;
        
        cout << "введите 2 вершины между которыми есть ребро\n";
        cin >> s1 >> s2;
        
        graph.addEdge(s1, s2);
    }

    int Versh;
    
    cout << "введите вершину\n";
    cin >> Versh;

    int rez = 0;
    cout << graph.adjLists[Versh].size();
}

/*
* Дано дерево.
* Определить его высоту.
*/
void task2()
{
    int n;
    
    cout << "введите колиество вершин\n";
    cin >> n;
    
    Graph graph(n);

    int colR;

    cout << "введите количетсво ребер\n";
    cin >> colR;

    for (int i = 0; i < colR; i++)
    {
        int s1, s2;

        cout << "введите 2 вершины между которыми есть ребро\n";
        cin >> s1 >> s2;

        graph.addEdge(s1, s2);
    }

    int s1, s2;

    cout << "какие 2 вершины соединить?\n";
    cin >> s1 >> s2;

    graph.addEdge(s1, s2);

}

/*
* Дано дерево.
* Подсчитать среднее арифметическое листьев.
*/
void task3()
{
    int n;
    
    cout << "введите колиество вершин\n";
    cin >> n;

    Graph graph(n);
    
    int colR;

    cout << "введите количетсво ребер\n";
    cin >> colR;

    for (int i = 0; i < colR; i++)
    {
        cout << "введите 2 вершины между которыми есть ребро\n";
        int s1, s2;
        cin >> s1 >> s2;
        graph.addEdge(s1, s2);
    }

    vector<int> rez(n);

    for (int i = 0; i < n; i++)
    {
        list<int>temp = graph.adjLists[i];

        cout << i << " " << temp.size() << endl;
    }
}

/*
* Дано дерево.
* Вывести узлы к-го уровня.
*/
void task4()
{
    int n;

    cout << "введите колиество вершин\n";
    cin >> n;
    
    Graph graph(n);

    int colR;

    cout << "введите количетсво ребер\n";
    cin >> colR;

    for (int i = 0; i < colR; i++)
    {
        int s1, s2;

        cout << "введите 2 вершины между которыми есть ребро\n";
        cin >> s1 >> s2;
        
        graph.addEdge(s1, s2);
    }

    graph.DFS(1);
    for (int i = 0; i < n; i++)
    {
        if (!graph.visited[i])
        {
            cout << "no\n";

            return;
        }
    }

    cout << "yes\n";
}

/*
* Дан невзвешенный неориентированный граф.
* Найти кратчайший путь между вершинами А и В.
*/
void task5()
{
    int n;

    cout << "введите колиество вершин\n";
    cin >> n;

    Graph graph(n);

    int colR;

    cout << "введите количетсво ребер\n";
    cin >> colR;

    for (int i = 0; i < colR; i++)
    {
        int s1, s2;

        cout << "введите 2 вершины между которыми есть ребро\n";     
        cin >> s1 >> s2;

        graph.addEdge(s1, s2);
        graph.addEdge(s2, s1);
    }

    int tempVersh1, tempVersh2;

    cout << "введите 2 вершины, между которыми необходимо найти путь\n";   
    cin >> tempVersh1 >> tempVersh2;

    graph.BFS(tempVersh1, tempVersh2);   
}

int main()
{
    int task;

    std::cout << "" << std::endl;
    std::cin >> task;

    switch(task)
    {
        case 1:
        {
            task1();

            break;
        }

        case 2:
        {
            task2();

            break;
        }

        case 3:
        {
            task3();

            break;
        }

        case 4:
        {
            task4();

            break;
        }

        case 5:
        {
            task5();

            break;
        }

        default:
        {
            std::cout << "" << std::endl;

            break;
        }
    }

    return 0;
}