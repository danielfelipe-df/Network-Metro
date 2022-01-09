/**
 * @file parameters.h
 * @author Daniel Felipe
 * @date 08/01/2022
 *
 * @brief
 */


#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>

/**
 * @brief This class receive the main parameters. These come from the command line.
 *
 * @class Parameters
 */
class Parameters{
public:

  /* Atributes */

  /// Filename of the graph file.
  std::string filename;

  /// Name of the initial node.
  std::string init;

  /// Name of the final node.
  std::string end;

  /// Color of the bus
  std::string color;


  /* Constructor */
  /**
   * @brief Constructor of the class Parameters
   */
  Parameters();


  /* Destructor */
  /**
   * @brief Destructor of the class Parameters
   */
  ~Parameters();
};


#endif /* PARAMETERS_H */
