/*

 Copyright 2017 Aman Mehara

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 */

import java.util.*;

public class DepthFirstTraversal<V> {

    public void depthFirstTraversal(DirectedGraph<V> graph, V vertex) {

        final Set<V> visited = new HashSet<>();
        recurse(graph, vertex, visited);

    }

    private void recurse(DirectedGraph<V> graph, V vertex, Set<V> visited) {

        visited.add(vertex);

        graph.adjacencyList().get(vertex).forEach(v -> {
            if (!visited.contains(v)) {
                recurse(graph, v, visited);
            }
        });

    }

}