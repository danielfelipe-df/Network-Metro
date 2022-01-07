/**
 * @file network.h
 * @author Daniel Felipe
 * @date 03/01/2021
 * @brief
 */

#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <utility>
#include <string>

/**
 * @brief
 *
 * @param nodes
 * @param links
 */
void read_network(std::vector<std::pair<std::string, std::string> > &nodes, std::vector<std::pair<std::string, std::string> > &links);


/**
 * @brief
 *
 * @param matrix
 * @param nodes
 * @param links
 *
 * @return
 */
int* create_networks(std::vector<std::pair<std::string, std::string> > &nodes, std::vector<std::pair<std::string, std::string> > &links);


/**
 * @brief
 *
 * @param matrix
 * @param init
 * @param end
 * @param num_nodes
 *
 * @return
 */
void DepthFirstSearch_DFS(int* matrix, int init, int end, size_t num_nodes, bool* visited, std::vector<int> &current_path, std::vector<std::vector<int> > &paths);

#endif
