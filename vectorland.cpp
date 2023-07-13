#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <map>

namespace Vec
  {
    std::vector<std::string> Vec = {};

    std::vector<std::string>::size_type getSize()
      {
        return Vec.size();
      }

    void addItem(std::string item)
      {
        Vec.push_back(item);
      }
    void removeItemIndex(int iterator)
      {
        Vec.erase(Vec.begin()+iterator);
      }
    void clearVec()
      {
        Vec.clear();
      }
    void insertItemStack (int iterator, std::string item_value)
      {
        Vec.insert(Vec.begin()+iterator, item_value);
      }
    void editItem (int iterator, std::string item_value)
    {
      Vec[iterator] = item_value;
    }
    std::string fetchItem(int index)
      {
        return Vec[index];
      }
    std::vector<std::string>::iterator begin()
      {
        return Vec.begin();
      }
    std::vector<std::string>::iterator end()
      {
        return Vec.end();
      }
    std::vector<std::string> returnVec()
      {
        return Vec;
      }
    std::string iterateVec(std::string separator = " ", bool quotes = false /* não achei um nome melhor para "aspas" em inglês, vai ser isso. */)
      {
        std::string x = "";
        for ( std::vector<std::string>::iterator i = Vec.begin(); i != Vec.end(); ++i )
          {
            if (i == Vec.end()-1)
              {
                if ( quotes )
                  x.append("\"");
                x.append(*i);
                if ( quotes )
                  x.append("\"");
              }
            else {
                if ( quotes )
                  x.append("\"");
                x.append(*i);
                if ( quotes )
                  x.append("\"");
                x.append(separator);
              }
          }
        return x;
      }
  }

namespace Map
  {
    std::map<std::string, int> intMap;
    std::map<std::string, std::string> strMap;
    
    void insertToIntContainer ( std::string key, int value )
      {
        intMap.insert( std::pair<std::string, int> (key, value) );
      }
    void insertToStringContainer ( std::string key, std::string value )
      {
        strMap.insert( std::pair<std::string, std::string> (key, value) );
      }
    void removeItemFromStringContainer ( std::string key )
      {
        strMap.erase(key);
      }
    void removeItemFromIntContainer ( std::string key )
      {
        intMap.erase(key);
      }
    int sofStrItem ( std::string key, std::map<std::string, std::string> map )
      {
        return sizeof( map[key] );
      }
    int sofIntItem ( std::string key, std::map<std::string, int> map )
      {
        return sizeof( map[key] );
      }
    bool checkKeyExists ( std::string key )
      {
        if ( intMap.find(key) == intMap.end() || strMap.find(key) == strMap.end() )
          return false;
        else
          return true;
      }
  }

std::vector<std::string> splitString(const std::string& input, char delimiter)
  {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    while (std::getline(iss, token, delimiter)) 
      {
        tokens.push_back(token);
      }
    return tokens;
  }

bool checkSize( std::vector<std::string> vec, unsigned int size = 0 /*, char* operator*/ )
  {
    if ( vec.size() >= size )
      return true;
    else 
      return true;
  }

void evalBooExit ( bool evaluate, std::string errCode )
  {
    if (evaluate == true)
      {
        // pass
      }
    else /* if false */
      {
        std::cout << errCode << std::endl;
        exit(1); 
      }
  }

int process_command(const std::string& cmd_input)
  {
    std::vector<std::string> tokens = splitString(cmd_input, ' ');
    //for ( std::vector<std::string>::iterator i = tokens.begin(); i != tokens.end(); ++i ) std::cout << " \"" << *i << "\" ";
    if ( tokens.size() == 0 )
      {  }
    else if ( tokens[0] == "help" )
      {
        const std::string TAB = "   ";
         std :: cout << "vectorland commands:\n" << TAB
         << "help: show this screen\n" << TAB
         << "add-item <item>: add a item on vector.\n" << TAB
         << "del-item <index>: delete a item from the vector using a integer index.\n" << TAB
         << "add-to-vector [args, ...]: add a array on vector.\n" << TAB
         << "remove-to-vector [args, ...] remove multiple items from array by index.\n" << TAB
         //<< "\titerate <arg> ... : iterate vector with a condiction, list iterate an as lost, index-list iterate an as list and index numbers, separator <separator string> iterate with a separator like a split.\n"
         << "list-vec: iterate vector\n" << TAB
         << "sizeof <container> <param>: returns size of vector in integer format.\n" << TAB
         << TAB << "Args: container: vec or map, params: item, all\n" << TAB
         << "set <name> <value>: set a variable at a map container.\n" << TAB
         << TAB << "Args: name: str, value: str or int.\n" << TAB
         << TAB << "unset <name>: unset a variable at a map container.\n" << TAB
         << TAB << "range <int> <int>: create a range of a numbers\n" << TAB
         << "exports <filename>: exports vector and vars at a file\n" << TAB
         << "show: show the value of map\n";
      }
    else if ( tokens[0] == "sizeof" && tokens.size() > 2 )
      {
        std::cout << "Size of vector:" << Vec::getSize() << std::endl;
      }
    else if ( tokens[0] == "show" && tokens.size() > 2 )
      {
        try 
          {
            if ( tokens[1] == "int" )     std::cout << Map::intMap[ tokens[2] ] << std::endl;
            else if (tokens [1] == "str") std::cout << Map::strMap[ tokens[2] ] << std::endl;
          }
        catch (...) 
          {
            std::cout << "Error, this value not exists!" << std::endl;
          }
      }
    else if ( tokens[0] == "set" && tokens.size() > 3)
      {
        if ( tokens[1] == "int" )
          {
            if ( !Map::checkKeyExists( tokens[2] ) ) 
              Map::insertToIntContainer ( tokens[2], stoi(tokens[3]) );
            else std::cout << "Error to set, this key has already been set.";
          }
        else if (tokens[1] == "str" )
          {}
        else {
          std::cout << "Fatal error, unknown type of variable.";
        }

        try
          {
            if ( Map::checkKeyExists(tokens[2]) )
                std::cout << "Error to set, this key has already been set." << std::endl;
            else
              Map::insertToIntContainer( tokens[2], stoi(tokens[3]) );
          }
        catch (...)
          {
            try
              {
                if ( Map::checkKeyExists(tokens[1]) )
                  std::cout << "Error to set, this key already been set." << std::endl;
                else
                  Map::insertToStringContainer ( tokens[1], tokens[2] );
              }
            catch (...)
              {
                std::cout << "Parsing error! Please put in this order: set <key: str> <value: int or str>" << std::endl;
              }
          }
      }
    else if ( tokens[0] == "unset" && tokens.size() > 1 )
      {
        if ( Map::checkKeyExists(tokens[1]) )
          {
            try 
              {
                Map::removeItemFromStringContainer( tokens[1] );
              }
            catch (...)
              {
                Map::removeItemFromIntContainer( tokens[1] );
              }
          }
        else
          {
            std::cout << "This key does not exists." << std::endl;
          }
      }
    else if ( tokens[0] == "range" && tokens.size() > 2 )
      {
        try 
          {
             int a = std::stoi( tokens[1] ), b = std::stoi( tokens[2] );
             if ( a < b )
              {            
                for ( int i = a; i != b + 1; i++ )
                {
                  std::cout << i << " ";
                }                         
              }
             else if ( a > b )
             {
               for ( int i = a; i != b-1; i-- )
               {
                 std::cout << i << " ";
               }
              }
             else if ( a == b )
              {
                std::cout << "Same value.";
              }
             std::cout << std::endl;
          }
        catch (...)
          {
             std::cout << "Parsing error! Can't parse a string with not integer numbers format in integer." << std::endl;
          }
      }
    else if ( tokens[0] == "exit" ) exit(0);
    else if ( tokens[0] == "add-item" && tokens.size() > 1)
      {
        Vec::addItem( tokens[1] );
      }
    else if ( tokens[0] == "list-vec" )
      {
        if ( Vec::getSize() != 0 ) std::cout << "[" << Vec::iterateVec(", ", true) << "]" << std::endl;
        else std::cout << "Empty." << std::endl;
      }
    else if ( tokens[0] == "del-item" && tokens.size() > 1 )
      {
        try 
          {
            unsigned int index = std::stoi( tokens[1] );
            if ( Vec::getSize() > index )
              {
                try 
                  {
                    Vec::removeItemIndex( index );
                  }
                catch (...)
                  {
                    std::cout << "Error to remove item from vector." << std::endl;
                  }
              }
            else 
              {
                std::cout << "Error, this index is bigger than vector size!" << std::endl;
              }
          }
        catch (...)
          {
            std::cout << "Parsing error! Can't parse a string with not integer numbers format in integer." << std::endl;
          }
      }
      else std::cout << "Incorrect expression, please enter \"help\"\n";
    return 0;
  }
void cmd()
  {
    std::string cmd_input = "";
    std::cout << "> ";
    std::getline(std::cin, cmd_input);
    if (!std::cin.eof())
      process_command(cmd_input);
    else exit(0);
  }
int main()
  {
    while (1)
    {
      cmd();
    }
  }

