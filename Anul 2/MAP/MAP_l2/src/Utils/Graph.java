package Utils;

import java.util.ArrayList;
import java.util.List;

public interface Graph {

    void addEdge(int source, int destination);
    List<Integer> getNeighbors(int vertex);

    int getConnectedComponents();
    List<Integer> getLargestConnectedComponent();
}
