/**
 * @file code.cpp
 * @author Daniel Felipe
 * @date 03/01/2021
 *
 * @brief This is the main file. Here is the main function and inside it is
 * implement the sequence of functions used for the code.
 */


#include <network.h>

#include <iostream>
#include <algorithm>

int main(void)
{
  // Create variables of nodes and links
  std::vector<std::pair<std::string, std::string> > links;
  std::vector<std::vector<std::string> > nodes;

  // Read file and save data
  read_network(nodes, links);

  // Check the file was read
  if(nodes.size() == 0 && links.size() == 0)
    return EXIT_FAILURE;

  // Check the file is in correct format
  if(nodes.size() < 2){
    std::cerr << "There is no nodes, or not enough (2), in the file '" << MyPar.filename << "'." << std::endl;
    std::cerr << "Please check the format used." << std::endl;
    return EXIT_FAILURE;
  }
  if(links.size() < 1){
    std::cerr << "There is not edges, or not enough (1), in the file '" << MyPar.filename << "'." << std::endl;
    std::cerr << "Please check the format used." << std::endl;
    return EXIT_FAILURE;
  }


  // Set init and end node
  int init=-1, end=-1;
  for(size_t i=0; i<nodes.size(); i++){
    if(MyPar.init == nodes[i][0]){
      init = i;
      break;
    }
  }
  for(size_t i=0; i<nodes.size(); i++){
    if(MyPar.end == nodes[i][0]){
      end = i;
      break;
    }
  }

  // Check the first and last nodes are correct
  if(init == -1){
    std::cerr << "The first node passed doesn't match with anyone in the file '" << MyPar.filename << "'." << std::endl;
    std::cerr << "Please check the file. Remind the program is not case sensitive." << std::endl;
    return EXIT_FAILURE;
  }
  if(end == -1){
    std::cerr << "The end node passed doesn't match with anyone in the file '" << MyPar.filename << "'." << std::endl;
    std::cerr << "Please check the file. Remind the program is not case sensitive." << std::endl;
    return EXIT_FAILURE;
  }

  // Check the color is a possible color
  bool false_color = true;
  for(size_t i=0; i<nodes.size(); i++){
    if(MyPar.color == nodes[i][1]){
      false_color = false;
      break;
    }
  }
  if(false_color){
    std::cerr << "The bus color passed doesn't match with anyone in the file '" << MyPar.filename << "'." << std::endl;
    std::cerr << "Please check the file. Remind the program is not case sensitive." << std::endl;
    return EXIT_FAILURE;
  }

  // Check the color can go to the nodes
  if(MyPar.color != "NOCOLOR"){
    if(nodes[init][1] != "NOCOLOR"){
      if(MyPar.color != nodes[init][1]){
	std::cerr << "The bus color passed can't stay in the first node." << std::endl;
	std::cerr << "The bus color is '" << MyPar.color << "', but the node color is '" << nodes[init][1] << "'." << std::endl;
	std::cerr << "Please check the file. Remind the program is not case sensitive." << std::endl;
	return EXIT_FAILURE;
      }
    }
  }
  if(nodes[end][1] != "NOCOLOR"){
    if(MyPar.color != nodes[end][1]){
      std::cerr << "The bus color passed can't stay in the end node." << std::endl;
      std::cerr << "The bus color is '" << MyPar.color << "', but the node color is '" << nodes[end][1] << "'." << std::endl;
      std::cerr << "Please check the file. Remind the program is not case sensitive." << std::endl;
      return EXIT_FAILURE;
    }
  }

  // Create the adjacency matrix
  int* graph = create_networks(nodes, links);


  // Start the Depth-First-Search algorithm to get all paths between two nodes

  // Variable for check the used (visited) nodes
  bool* visited = new bool[nodes.size()]();

  // Containers of the temporal path, and all paths
  std::vector<int> current_path;
  std::vector<std::vector<int> > paths;

  // Find the paths
  DepthFirstSearch_DFS(graph, init, end, nodes.size(), visited, current_path, paths);

  // Print paths
  std::cout << "Paths from " << MyPar.init << " to " << MyPar.end << std::endl;
  for(size_t i=0; i<paths.size(); i++){
    std::cout << nodes[paths[i][0]][0];
    for(size_t j=1; j<paths[i].size(); j++){
      std::cout << " -> " << nodes[paths[i][j]][0];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // Modify paths taking into account the color
  modify_paths(paths, nodes);

  // Create the time vector of the paths and save the time associated
  // with the path summing all node's time
  std::vector<double> time_paths(paths.size(), 0);
  for(size_t i=0; i<paths.size(); i++){
    for(size_t j=0; j<paths[i].size(); j++){
      time_paths[i] += std::stod(nodes[paths[i][j]][2]);
    }
  }

  // Find the min time in the vector
  auto minmax = std::minmax_element(time_paths.begin(), time_paths.end());
  std::cout << "Min path length is: " << *minmax.first << std::endl;

  // Save the index of smallest path
  size_t min_index = (minmax.first - time_paths.begin());

  // Print min path
  std::cout << "Min path index is: " << min_index << std::endl;
  std::cout << nodes[paths[min_index][0]][0];
  for(size_t j=1; j<paths[min_index].size(); j++){
    std::cout << " -> " << nodes[paths[min_index][j]][0];
  }
  std::cout << std::endl;

  // Erase memory
  delete[] graph;
  delete[] visited;
  nodes.clear();
  links.clear();
  current_path.clear();
  paths.clear();

  return 0;
}
