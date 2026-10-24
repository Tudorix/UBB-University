package Utils;

import java.util.*;

public class AdjacentGraph implements Graph {
    Map<String, List<String>> adjacencyList;

    public AdjacentGraph() {
        /**
         * Constructor of the AdjacentGraph class
         */
        adjacencyList = new HashMap<>();
    }

    @Override
    public void addEdge(String source, String destination) {
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
    public List<String> getNeighbors(String vertex) {
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
        Set<String> visited = new HashSet<>();
        int count = 0;
        for (String vertex : adjacencyList.keySet()) {
            if (!visited.contains(vertex)) {
                DFS(vertex, visited);
                count++;
            }
        }
        return count;
    }

    private void DFS(String vertex, Set<String> visited) {
        /**
         * Depth First Search algorithm to traverse the graph
         *
         * @param vertex: the vertex to start the traversal from
         * @param visited: the set of visited vertices
         */
        visited.add(vertex);
        for (String neighbor : getNeighbors(vertex)) {
            if (!visited.contains(neighbor)) {
                DFS(neighbor, visited);
            }
        }
    }

    private void DFS(String vertex, Set<String> visited, List<String> component) {
        /**
         * Depth First Search algorithm to traverse the graph and find connected components
         *
         * @param vertex: the vertex to start the traversal from
         * @param visited: the set of visited vertices
         * @param component: the list of vertices in the current connected component
         */
        component.add(vertex);
        visited.add(vertex);
        for (String neighbor : getNeighbors(vertex)) {
            if (!visited.contains(neighbor)) {
                DFS(neighbor, visited, component);
            }
        }
    }

    @Override
    public List<String> getLargestConnectedComponent() {
        /**
         * Returns the largest connected component in the graph
         *
         * @return the list of vertices in the largest connected component
         */
        Set<String> visited = new HashSet<>();
        List<String> largestComponent = new ArrayList<>();
        for (var vertex : adjacencyList.keySet()) {
            if (!visited.contains(vertex)) {
                List<String> currentComponent = new ArrayList<>();
                DFS(vertex, visited, currentComponent);
                if (currentComponent.size() > largestComponent.size()) {
                    largestComponent.clear();
                    largestComponent.addAll(currentComponent);
                }
            }
        }
        return largestComponent;
    }
}