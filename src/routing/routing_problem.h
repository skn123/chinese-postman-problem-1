#ifndef __ROUTING_PROBLEM_H__
#define __ROUTING_PROBLEM_H__

#include "graph/graph.h"
#include "paths/shortest_paths.h"
#include "flow/network_flow.h"
#include <stack>

enum GraphType { DIRECTED, UNDIRECTED, MIXED };


class RoutingProblem
{

    public:
        RoutingProblem();
        ~RoutingProblem();
        void clear();

        void init(const Graph graph, const int startId, int goalId = Graph::UnassignedId, Graph::EdgeSet travelEdges = Graph::EdgeSet());

        std::vector<int> solve();

        GraphType detectGraphType(Graph graph);

    private: 

        void evenDegreeHeuristic(Graph* graph);
        std::map<int, int> simmetryHeuristic(Graph* graph);

        std::vector<int> hierholzerSolver(Graph& graph, int startNodeId, int goalNodeId = Graph::UnassignedId);

        std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> fredericksonInOutDegree(Graph* graph);





        int _startId;
        int _goalId;
        Graph::EdgeSet _notRequiredEdges;

        Graph _originalGraph;
        GraphType _type;
        Graph _eulerianExtendedGraph;

};



#endif