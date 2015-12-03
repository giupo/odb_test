#ifndef __PERSON__
#define __PERSON__

#include <string>
#include <odb/core.hxx>     // (1)

#pragma db object           // (2)
class person
{
public:
  person (const std::string& first,
          const std::string& last,
          unsigned short age): first_(first), last_(last), age_(age) {}

  const std::string& first () const {
    return first_;
  }
  
  const std::string& last () const {
    return last_;
  }

  unsigned short age () const {
    return age_;
  }
  
  void age (unsigned short anni) {
    age_ = anni;
  }

private:
  person () {}              // (3)

  friend class odb::access; // (4)

#pragma db id auto        // (5)
  unsigned long id_;        // (5)
  
  std::string first_;
  std::string last_;
  unsigned short age_;
};

#endif
