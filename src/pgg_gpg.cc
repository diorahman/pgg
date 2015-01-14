#include "pgg_gpg.h"

#include <nan.h>
#include <locale.h>

void PggGpg::Init(const gpgme_protocol_t& proto) {
  gpgme_error_t err;
  gpgme_check_version(NULL);
  setlocale(LC_ALL, "");
  gpgme_set_locale(NULL, LC_CTYPE, setlocale (LC_CTYPE, NULL));
  err = gpgme_engine_check_version(proto);
  ThrowError(err);
}

void PggGpg::ThrowError(const gpgme_error_t& err) {
  if (err)
    NanThrowError(NanNew(gpgme_strerror(err)));
}

const char* PggGpg::Version() {
  return gpgme_check_version(NULL);
}

void PggGpg::EngineInfo(gpgme_engine_info_t& info) {
  gpgme_error_t err;
  err = gpgme_get_engine_info(&info);
  ThrowError(err);
}
