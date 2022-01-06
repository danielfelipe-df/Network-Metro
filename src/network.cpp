/**
 * @file network.cpp
 * @author Daniel Felipe
 * @date 03/01/2021
 * @brief
 */

#include <network.h>

#include <iostream>
#include <fstream>
#include <algorithm>

void read_network(std::vector<std::pair<std::string, std::string> > &nodes, std::vector<std::pair<std::string, std::string> > &links){
  std::string filename("dat/network.csv"), line;

  std::ifstream file(filename);
  if(!file.is_open()){
    std::cerr << "Could not open the file '" << filename << "'" << std::endl;
  }

  std::vector<std::vector<std::string> > data;

  while(std::getline(file, line)){
    std::transform(line.begin(), line.end(), line.begin(), ::toupper);

    std::vector<std::string> newline;
    std::string::size_type found = line.find("\t");
    while(found != std::string::npos){
      newline.push_back(line.substr(0, found));
      line.erase(0, found+1);

      found = line.find("\t");
    }

    newline.push_back(line);
    line.clear();

    data.push_back(newline);
  }

  size_t i=1;
  while(data[i][0].length() != 0){
    if(data[i][1].length() != 0){
      nodes.push_back(std::make_pair(data[i][0], data[i][1]));
    }
    else{
      nodes.push_back(std::make_pair(data[i][0], "BLANCO"));
    }
    i++;
  }

  i+=2;
  while(i<data.size()){
    links.push_back(std::make_pair(data[i][0], data[i][1]));
    i++;
  }

}
