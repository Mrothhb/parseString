class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
  if(pattern.length() == 1 )
      return true; 
        
  std::map<char,string> mymap;
  std::map<char,string>::iterator it;
  std::string delimiter = " ";
  size_t pos = 0;
  std::string token;
  int i = 0;
  pos = str.find(delimiter);
  token = str.substr(0, pos);
  str.erase(0, pos + delimiter.length());  
  mymap[pattern[0]]=token;
  i++;
        
  
  while((pos = str.find(delimiter)) != std::string::npos) {
    token = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
    it = mymap.find(pattern[i]);
    if (it != mymap.end()){
        if(mymap.find(pattern[i])->second == token){
            i++;
            continue;
        }else{
            return false;
        }
    }
    
      bool result = findByValue(mymap, token);
      if(result){
          return false;
      }
      else{
          mymap[pattern[i]]=token;
          i++;
      } 
  }
    it = mymap.find(pattern[i]);
    if (it != mymap.end()){
        if(mymap.find(pattern[i])->second == str){
            return true;
        }else{
            return false;
        }
    }
    bool result = findByValue(mymap, str);
    if(result){
          return false;
    }
        
    return true;
      
}

    
/*
 * Generic implementation to search if a given value exists in a map or not.
 * Adds all the keys with given value in the vector
 */
bool findByValue(std::map<char, string> mapOfElemen, string value)
{
    bool bResult = false;
    auto it = mapOfElemen.begin();
    // Iterate through the map
    while(it != mapOfElemen.end())
    {
        // Check if value of this entry matches with given value
        if(it->second == value)
        {
            // Yes found
            return true;
        }
        // Go to next entry in map
        it++;
    }
    return false;
}
};
