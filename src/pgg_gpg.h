#ifndef PGG_GPG_H
#define PGG_GPG_H

#include <gpgme.h>

class PggGpg {

private:
  //FIXME: move all statics to a util file and make ctor+dtor public
  PggGpg(){}
  ~PggGpg(){}

public:
  static void Init(const gpgme_protocol_t&);
  static const char* Version();
  static void EngineInfo(gpgme_engine_info_t&);
  static void ThrowError(const gpgme_error_t&);
};

#endif
