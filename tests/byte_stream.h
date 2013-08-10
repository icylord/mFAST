#ifndef BYTE_STREAM_H_4KE09BNK
#define BYTE_STREAM_H_4KE09BNK

#include "mfast/fast_coder/encoder/fast_ostreambuf.h"
#include <iostream>
#include <iomanip>
#include <boost/io/ios_state.hpp>


class byte_stream
{
  public:
    byte_stream(const char* s, std::size_t len)
      : data_(s)
      , size_(len)
    {
    }

    template <std::size_t SIZE>
    byte_stream(const char (&array) [SIZE])
      : data_(array)
      , size_(SIZE-1)
    {
    }
    
    
    byte_stream(const mfast::fast_ostreambuf& sb)
      : data_(sb.pbase())
      , size_(sb.length())
    {
    }

    std::size_t size() const
    {
      return size_;
    }

    const char* data() const
    {
      return data_;
    }

  private:
    const char* data_;
    std::size_t size_;
};


inline bool operator == (const byte_stream& lhs, const byte_stream& rhs)
{
  return lhs.size() == rhs.size() && memcmp(lhs.data(), rhs.data(), lhs.size()) == 0;
}

inline bool operator != (const byte_stream& lhs, const byte_stream& rhs)
{
  return !(lhs == rhs);
}

inline std::ostream& operator << (std::ostream& os, const byte_stream& bs )
{
  boost::io::ios_flags_saver ifs( os );

  os << std::hex << std::setfill('0');

  for (std::size_t i = 0; i < bs.size(); ++i)
  {
    os << "\\x" << std::setw(2) <<  (static_cast<uint32_t>(bs.data()[i]) & 0xFF);
  }

  return os;
}

#endif /* end of include guard: BYTE_STREAM_H_4KE09BNK */
