#pragma once
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <algorithm>

class Graph {
public:
    Graph() = default;
    
    void addVertex(const std::string& vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = std::list<std::string>();
        }
    }
    
    void addEdge(const std::string& from, const std::string& to) {
        addVertex(from);
        addVertex(to);
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from); // For undirected graph
    }
    
    std::vector<std::string> findShortestPath(const std::string& start, const std::string& end) {
        if (adjacencyList.find(start) == adjacencyList.end() || 
            adjacencyList.find(end) == adjacencyList.end()) {
            throw std::invalid_argument("Start or end vertex does not exist");
        }
        
        std::queue<std::string> queue;
        std::unordered_map<std::string, bool> visited;
        std::unordered_map<std::string, std::string> parent;
        
        queue.push(start);
        visited[start] = true;
        
        while (!queue.empty()) {
            std::string current = queue.front();
            queue.pop();
            
            if (current == end) {
                return reconstructPath(parent, start, end);
            }
            
            for (const auto& neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    queue.push(neighbor);
                }
            }
        }
        
        return {}; // No path found
    }
    
private:
    std::unordered_map<std::string, std::list<std::string>> adjacencyList;
    
    std::vector<std::string> reconstructPath(
        const std::unordered_map<std::string, std::string>& parent,
        const std::string& start,
        const std::string& end) {
        
        std::vector<std::string> path;
        std::string current = end;
        
        while (current != start) {
            path.push_back(current);
            current = parent.at(current);
        }
        path.push_back(start);
        
        std::reverse(path.begin(), path.end());
        return path;
    }
}; 