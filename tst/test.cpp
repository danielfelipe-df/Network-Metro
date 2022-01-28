/**
 * @file test.cpp
 * @author Daniel Felipe
 * @date 03/01/2021
 *
 * @brief Test file where are located the TEST_CASE functions.
 */


#include <catch.hpp>

#include <network.h>
#include <algorithm>


// Check the empty network is not working
TEST_CASE( "Bad_network file is read", "[read_file]" ){
  std::vector<std::pair<std::string, std::string> > links;
  std::vector<std::vector<std::string> > nodes;
  read_network(nodes, links);

  if(MyPar.filename == "../dat/bad_network.csv"){
    REQUIRE( nodes.size() == 0 );
    REQUIRE( links.size() == 0 );
  }
}


// Check the network without nodes attributes is not working
TEST_CASE( "No_nodes file is read", "[read_file]" ){
  std::vector<std::pair<std::string, std::string> > links;
  std::vector<std::vector<std::string> > nodes;
  read_network(nodes, links);

  if(MyPar.filename == "../dat/no_nodes.csv"){
    REQUIRE( nodes.size() == 0 );
    REQUIRE( links.size() == 2 );
  }
}


// Check the network without links is not working
TEST_CASE( "No_links bad_network file is read", "[read_file]" ){
  std::vector<std::pair<std::string, std::string> > links;
  std::vector<std::vector<std::string> > nodes;
  read_network(nodes, links);

  if(MyPar.filename == "../dat/no_links.csv"){
    REQUIRE( nodes.size() == 5 );
    REQUIRE( links.size() == 0 );
  }
}


// Check the best path for the default network
TEST_CASE( "Check the best path in the network", "[check_network]"){

  if(MyPar.filename == "../dat/network.csv"){
    std::vector<std::pair<std::string, std::string> > links;
    std::vector<std::vector<std::string> > nodes;
    read_network(nodes, links);

    // Create the adjacency matrix
    int* graph = create_networks(nodes, links);

    // Variable for check the used (visited) nodes
    bool* visited = new bool[nodes.size()]();

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

    // Containers of the temporal path, and all paths
    std::vector<int> current_path;
    std::vector<std::vector<int> > paths;

    // Find the paths
    DepthFirstSearch_DFS(graph, init, end, nodes.size(), visited, current_path, paths);

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

    // Save the index of smallest path
    size_t num_path = (minmax.first - time_paths.begin());
    
    REQUIRE( paths[num_path].size() == 5 );

    REQUIRE( nodes[paths[num_path][0]][0] == "A" );
    REQUIRE( nodes[paths[num_path][1]][0] == "B" );
    REQUIRE( nodes[paths[num_path][2]][0] == "C" );
    REQUIRE( nodes[paths[num_path][3]][0] == "H" );
    REQUIRE( nodes[paths[num_path][4]][0] == "F" );
  }

}
