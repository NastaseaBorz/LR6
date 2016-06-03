#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:

    Graph() : nodes_number(0), edges_number(0), first(0) { }

    Graph(int _nodes_number, int _edges_number, int _first) : nodes_number(_nodes_number), edges_number(_edges_number), first(_first) { }

    void add(int begin, int end, int size)
    {
        vector<int> edge;
        edge.push_back(begin);
        edge.push_back(end);
        edge.push_back(size);
        array.push_back(edge);
    }

    void dijkstra()
    {
        vector<int> edges;
        vector<bool> flag;
        for(int i = 0; i < nodes_number; i++)
        {
            edges.push_back(numeric_limits<int>::max());
            flag.push_back(false);
        }

        edges[first] = 0;
        int id;

        for (int i = 0; i < edges_number - 1; i++)
        {
            int min = numeric_limits<int>::max();

            for (int j = 0; j < edges_number; j++)
            {
                if (min > edges[j] && !flag[j])
                {
                    min = edges[j];
                    id = j;
                }
            }

            flag[id] = true;

            for (int k = 0; k < edges_number; k++)
            {
                for (int j = 0; j < array.size(); j++)
                    if ((array[j])[0] == id && (array[j])[1] == k && edges[id] != numeric_limits<int>::max() && !flag[k] &&
                        edges[id] + (
                                      array[j])[2] < edges[k])
                        edges[k] = edges[id] + (array[j])[2];
            }
        }

        for (int i = 0; i < nodes_number; i++)
        {
            if (edges[i] != numeric_limits<int>::max())
                cout << edges[i] << " ";
        }
        cout << endl;

    }

    ~Graph() { }
private:
    int nodes_number;
    int edges_number;
    int first;
    vector<vector<int>> array;
};



int main()
{
    int V, E, N;
    cin >> V >> E >> N;
    Graph graph(V, E, N);

    for (int i = 0; i < E; i++)
    {
        int beg, end, size;
        cin >> beg >> end >> size;
        graph.add(beg, end, size);
    }

    graph.dijkstra();
    
    return 0;
}