package Utils;

import java.util.*;

public class AdjacentGraph implements Graph {
    Map<Integer, List<Integer>> adjacencyList;

    public AdjacentGraph() {
        /**
         * Constructor of the AdjacentGraph class
         */
        adjacencyList = new HashMap<>();
    }

    @Override
    public void addEdge(int source, int destination) {
        /**
         * Adds an edge to the graph
         *
         * @param source: the source vertex
         * @param destination: the destination vertex
         */
        adjacencyList.computeIfAbsent(source, k -> new ArrayList<>()).add(destination);
        adjacencyList.computeIfAbsent(destination, k -> new ArrayList<>()).add(source);
    }

    @Override
    public List<Integer> getNeighbors(int vertex) {
        /**
         * Returns the neighbors of a vertex
         *
         * @param vertex: the vertex whose neighbors are to be returned
         * @return the list of neighbors of the vertex
         */
        return adjacencyList.get(vertex);
    }

    @Override
    public int getConnectedComponents() {
        /**
         * Returns the number of connected components in the graph
         *
         * @return the number of connected components
         */
        Set<Integer> visited = new HashSet<>();
        int count = 0;
        for (int vertex : adjacencyList.keySet()) {
            if (!visited.contains(vertex)) {
                DFS(vertex, visited);
                count++;
            }
        }
        return count;
    }

    private void DFS(int vertex, Set<Integer> visited) {
        /**
         * Depth First Search algorithm to traverse the graph
         *
         * @param vertex: the vertex to start the traversal from
         * @param visited: the set of visited vertices
         */
        visited.add(vertex);
        for (int neighbor : getNeighbors(vertex)) {
            if (!visited.contains(neighbor)) {
                DFS(neighbor, visited);
            }
        }
    }

    private void DFS(int vertex, Set<Integer> visited, List<Integer> component) {
        /**
         * Depth First Search algorithm to traverse the graph and find connected components
         *
         * @param vertex: the vertex to start the traversal from
         * @param visited: the set of visited vertices
         * @param component: the list of vertices in the current connected component
         */
        component.add(vertex);
        visited.add(vertex);
        for (int neighbor : getNeighbors(vertex)) {
            if (!visited.contains(neighbor)) {
                DFS(neighbor, visited, component);
            }
        }
    }

    @Override
    public List<Integer> getLargestConnectedComponent() {
        /**
         * Returns the largest connected component in the graph
         *
         * @return the list of vertices in the largest connected component
         */
        Set<Integer> visited = new HashSet<>();
        List<Integer> largestComponent = new ArrayList<>();
        for (int vertex : adjacencyList.keySet()) {
            if (!visited.contains(vertex)) {
                List<Integer> currentComponent = new ArrayList<>();
                DFS(vertex, visited, currentComponent);
                if (currentComponent.size() > largestComponent.size()) {
                    largestComponent = currentComponent;
                }
            }
        }
        return largestComponent;
    }
}