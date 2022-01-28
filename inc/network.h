/**
 * @file network.h
 * @author Daniel Felipe
 * @date 03/01/2021
 *
 * @brief This header contains the declaration of functions that are in 'network.cpp'.
 * This is the only header, so here are all the functions used in the code.
 */


#ifndef NETWORK_H
#define NETWORK_H

#include <parameters.h>

#include <vector>
#include <utility>


/// Create the variable of Parameters class
const Parameters MyPar;

/**
 * @brief This function read the CSV file where the graph is defined. Divide the nodes,
 * with its attribute, and the links.
 *
 * @param nodes Is a vector of pairs. The pair's first element is the node's label, the
 * second one is the color.
 * @param links Is a vector of pairs. Both elements are nodes that are connected by an edge.
 */
void read_network(std::vector<std::vector<std::string> > &nodes, std::vector<std::pair<std::string, std::string> > &links);


/**
 * @brief This function create the adjacency matrix based in the links and nodes given.
 *
 * @param nodes Vector of the node's label and color.
 * @param links Vector containing names of nodes that are connected.
 *
 * @return 1-D array containing 1 and 0. 1 if there is an edge, 0 otherwise.
 */
int* create_networks(std::vector<std::vector<std::string> > &nodes, std::vector<std::pair<std::string, std::string> > &links);


/**
 * @brief This function find all paths between nodes @p init and @p end. Uses the
 * Depth-First-Search (DFS) algorithm, a search-three algorithm which go forward looking
 * for the next possible node. The used algorithm has an small modification in order to not
 * go into a cycle.
 *
 * @param matrix 1-D array associated to the adjacency matrix.
 * @param init Index of the first node on the path sought.
 * @param end Index of the last node on the path sought.
 * @param num_nodes Number of nodes in the graph.
 * @param visited Boolean 1-D array which check if the node has been visited in the current path.
 * @param current_path This vector saves the node's index that has been visited.
 * @param paths This vector saves all the paths found.
 */
void DepthFirstSearch_DFS(int* matrix, int init, int end, size_t num_nodes, bool* visited, std::vector<int> &current_path, std::vector<std::vector<int> > &paths);


/**
 * @brief This function check the nodes in the paths can be visited by the color asked, if not
 * then remove the node from the path.
 *
 * @param paths Vector with all the possible paths.
 * @param nodes Vector with the node's label and color.
 */
void modify_paths(std::vector<std::vector<int> > &paths, std::vector<std::vector<std::string> > &nodes);


#endif
