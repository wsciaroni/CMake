/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#pragma once

#include <memory>
#include <string>
#include <vector>

#include <cm/string_view>

#include "cmsys/FStream.hxx"

namespace Json {
class StreamWriter;
}

class cmMakefile;

class cmConfigureLog
{
public:
  cmConfigureLog(std::string logDir);
  ~cmConfigureLog();

  void WriteBacktrace(cmMakefile const& mf);

  void EnsureInit();

  void BeginEvent(std::string const& kind);
  void EndEvent();

  void BeginObject(cm::string_view key);
  void EndObject();

  // TODO other value types
  void WriteValue(cm::string_view key, std::nullptr_t);
  void WriteValue(cm::string_view key, bool value);
  void WriteValue(cm::string_view key, int value);
  void WriteValue(cm::string_view key, std::string const& value);
  void WriteValue(cm::string_view key, std::vector<std::string> const& list);

  void WriteTextBlock(cm::string_view key, cm::string_view text);
  void WriteLiteralTextBlock(cm::string_view key, cm::string_view text);

  void WriteLiteralTextBlock(cm::string_view key, std::string const& text)
  {
    this->WriteLiteralTextBlock(key, cm::string_view{ text });
  }

private:
  std::string LogDir;
  cmsys::ofstream Stream;
  unsigned Indent = 0;
  bool Opened = false;

  std::unique_ptr<Json::StreamWriter> Encoder;

  cmsys::ofstream& BeginLine();
  void EndLine();
  void WriteEscape(unsigned char c);
};
