package Utils;

import java.util.ArrayList;
import java.util.List;

public interface Graph {

    void addEdge(String source, String destination);
    List<String> getNeighbors(String vertex);

    int getConnectedComponents();
    List<String> getLargestConnectedComponent();
}
