#pragma once

class EFile {
public:
  EFile();
  ~EFile();

  int SetWriteFiletime(long long writeFileTime);
};
