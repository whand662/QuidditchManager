/**
  StringTokenizer.hpp
  Tool for parsing input strings

  @author Willis Hand
  @version 1.0
  @copyright 2017 Willis Hand
*/

#ifndef _STRING_TOKENIZER
#define _STRING_TOKENIZER

#include <string>
#include <vector>

#define DEFAULT_DELIMITERS " \t\n"

using namespace std;

class StringTokenizer{
  public:

    //! Default constructor, uses predefined DEFAULT_DELIMITERS (" \t\n")
    StringTokenizer();

    //! Constructor that takes a custom set of delimiters
    /*!
      \param delims will be assigned to delimeters, use to set your own default delimiters.
    */
    StringTokenizer(string delims);

    //! Tokenizes input string, returns as a vector<string>
    /*!
      \param line input to be tokenized
      \return returns a vector<string>
    */
    vector<string> tokenize(string line);

    //! Tokenizes input string based on a temporary set of delimiters, returns as a vector<string>
    /*!
      \param line input to be tokenized
      \param delims Set of delimiters just for this one call. Does not overwrite default delimiters
      \return returns a vector<string>
    */
    vector<string> tokenize(string line, string delims);

    //! Used as a setter for the default delimiters
    /*!
      \param delims The new set of delimiters
    */
    void setDefaultDelimiters(string delims);
  private:
    string delimiters; //<! String containing delimiter characters
};

#endif

