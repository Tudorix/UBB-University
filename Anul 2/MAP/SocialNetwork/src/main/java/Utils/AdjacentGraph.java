package Utils;

import java.util.*;
import java.util.function.Predicate;

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
        getNeighbors(vertex).forEach(neighbour -> {
            if (!visited.contains(neighbour)) {
                DFS(neighbour, visited);
            }
        });
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
        getNeighbors(vertex).forEach(neighbour -> {
            if (!visited.contains(neighbour)) {
                DFS(neighbour, visited, component);
            }
        });
    }

    @Override
    public List<String> getLargestConnectedComponent() {
        /**
         * Returns the largest connected component in the graph
         *
         * @return the list of vertices in the largest connected component
         */
        List<List<String>> components = new ArrayList<>();
        Set<String> visited = new HashSet<>();

        for (var vertex : adjacencyList.keySet()) {
            if (!visited.contains(vertex)) {
                List<String> currentComponent = new ArrayList<>();
                DFS(vertex, visited, currentComponent);
                components.add(currentComponent);
            }
        }
        return components.stream().max(Comparator.comparingInt(List::size)).orElseGet(ArrayList::new);
    }
}