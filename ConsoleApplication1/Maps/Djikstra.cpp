//
// Created by gabriel on 21/10/18.
//

#include "Djikstra.h"


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int Djikstra::minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index = 0;

	for (int v = 0; v < 16; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void Djikstra::printSolution(int dist[], int n)
{
	//Debug::Log("Vertex   Distance from Source", Color::Black);
    for (int i = 0; i < 16; i++)
        printf("%d tt %d\n", i, dist[i]);
		//Debug::Log(dist[i], Color::Black);
};

int Djikstra::Search(List<int> a, int ele){
    for (int i = 0 ; i< a.size; i++){
        if (a.get(i) == ele){
            return a.get(i-1);
        }
    }
};

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
List<int> Djikstra::asap(List<int>  v, int src, int fin){

    List<int>  b;
    int tmp = fin;

    while (tmp != src){
        b.add(tmp);
        tmp = Search(v,tmp);
    }
    return b;
};

List<int> Djikstra::dijkstra(int src, int fin)
{
    std::cout <<"iniciando algoritmo..." << std::endl;
    
	int dist[V];     // The output array.  dist[i] will hold the shortest // distance from src to i
    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest // path tree or shortest distance from src to i is finalized
    List<int>  a ;
    int ind=0; 
	// Initialize all distances as INFINITE and stpSet[] as false

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to  v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v],
				a.add(u), a.add(v),

				//Debug::Log(u, Color::Blue),
				//Debug::Log(v, Color::Red);
				std::cout << "[" << u << "," << v << "]" << ",";
                        //std::cout <<u,std::cout <<" ",std::cout <<v,std::cout <<"    ";
    };


    // print the constructed distance array
    //printSolution(dist, V);
    return asap(a,src,fin);
};
//Funciones de Gabo JAJAJ XD
void Djikstra::sendlist(void(*action)(int x, int y), void(*boolean)(bool m))
{
	//Debug::Log("Hellow Red", Color::Black);
	boolean(false);
	//Debug::Log(PosList.size, Color::Green);
	for (int i = 0; i < PosList.size; i++) {
		//Debug::Log(PosList.get(i), Color::Black);
		//Conversion de nodo a x y
		int x = PosList.get(i) % 250;
		int y = PosList.get(i) / 250;

		action(x, y);//Funcion que mete en la lista de C char
		//Debug::Log("added", Color::Black);
	}
	boolean(true);
}

void Djikstra::getPositions(int xi, int yi, int xf, int yf)
{
	//List<int> PosList;
	int init = xi * (1 + yi) + xi;
	std::cout << "node init:" <<init<< "created" << std::endl;
	//Debug::Log(init, Color::Red);
	int finit = xf * (1 + yf) + xf;
	std::cout << "node finit:" << finit << "created" << std::endl;
	//Debug::Log(finit, Color::Blue);
	std::cout << "sending info to Djikstra..." << std::endl;
	PosList = dijkstra(init, finit);
	//Aquí no sirve, y no me voy a meter en el código, arreglelo puto Josué...
	//Atte: Gabo
	PosList.show();
}
