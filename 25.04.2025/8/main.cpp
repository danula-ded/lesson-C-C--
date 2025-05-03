#include "graph.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\nGraph Operations Menu:\n"
              << "1. Add edge\n"
              << "2. Find shortest path\n"
              << "3. Exit\n"
              << "Enter your choice: ";
}

int main() {
    Graph graph;
    
    // Add some example edges
    graph.addEdge("A", "B");
    graph.addEdge("B", "C");
    graph.addEdge("C", "D");
    graph.addEdge("D", "E");
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }
        
        try {
            switch (choice) {
                case 1: {
                    std::string from, to;
                    std::cout << "Enter source vertex: ";
                    std::cin >> from;
                    std::cout << "Enter destination vertex: ";
                    std::cin >> to;
                    graph.addEdge(from, to);
                    std::cout << "Edge added successfully.\n";
                    break;
                }
                case 2: {
                    std::string start, end;
                    std::cout << "Enter start vertex: ";
                    std::cin >> start;
                    std::cout << "Enter end vertex: ";
                    std::cin >> end;
                    
                    auto path = graph.findShortestPath(start, end);
                    if (path.empty()) {
                        std::cout << "No path found between " << start << " and " << end << "\n";
                    } else {
                        std::cout << "Shortest path: ";
                        for (size_t i = 0; i < path.size(); ++i) {
                            std::cout << path[i];
                            if (i < path.size() - 1) {
                                std::cout << " -> ";
                            }
                        }
                        std::cout << "\n";
                    }
                    break;
                }
                case 3:
                    std::cout << "Exiting program.\n";
                    return 0;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
} 