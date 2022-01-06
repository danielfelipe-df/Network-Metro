/**
 * @file code.cpp
 * @author Daniel Felipe
 * @date 03/01/2021
 * @brief
 */

#include <network.h>
#include <iostream>

int main(void)
{
  std::vector<std::pair<std::string, std::string> > nodes, links;

  read_network(nodes, links);

  std::cout << "Node\tColor" << std::endl;
  for(size_t i=0; i<nodes.size(); i++){
    std::cout << nodes[i].first << '\t' << nodes[i].second << std::endl;
  }

  std::cout << std::endl;

  std::cout << "Node1 <-> Node2" << std::endl;
  for(size_t i=0; i<links.size(); i++){
    std::cout << links[i].first << " <-> " << links[i].second << std::endl;
  }

  return 0;
}
