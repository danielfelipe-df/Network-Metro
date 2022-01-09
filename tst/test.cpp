/**
 * @file test.cpp
 * @author Daniel Felipe
 * @date 03/01/2021
 *
 * @brief Test file where are located the TEST_CASE functions.
 */


#include <catch.hpp>

#include <network.h>


TEST_CASE( "Bad_network file is read", "[read_file]" ){
  std::vector<std::pair<std::string, std::string> > nodes, links;
  read_network(nodes, links);

  if(MyPar.filename == "../dat/bad_network.csv"){
    REQUIRE( nodes.size() == 0 );
    REQUIRE( links.size() == 0 );
  }
}


TEST_CASE( "No_nodes file is read", "[read_file]" ){
  std::vector<std::pair<std::string, std::string> > nodes, links;
  read_network(nodes, links);

  if(MyPar.filename == "../dat/no_nodes.csv"){
    REQUIRE( nodes.size() == 0 );
    REQUIRE( links.size() == 2 );
  }
}


TEST_CASE( "No_links bad_network file is read", "[read_file]" ){
  std::vector<std::pair<std::string, std::string> > nodes, links;
  read_network(nodes, links);

  if(MyPar.filename == "../dat/no_links.csv"){
    REQUIRE( nodes.size() == 5 );
    REQUIRE( links.size() == 0 );
  }
}
