// Copyright 2021 Alexey Timin

#ifndef REDUCT_STORAGE_CALLBACKS_H
#define REDUCT_STORAGE_CALLBACKS_H

#include <string>

#include "reduct/async/run.h"
#include "reduct/core/error.h"

namespace reduct::api {

template <typename Response>
struct CallbackResult {
  Response response;
  core::Error error;

  operator const core::Error&() const { return error; }
};

/**
 * Get info callback
 */
class IInfoCallback {
 public:
  struct Response {
    std::string version;
    size_t bucket_number;
  };
  struct Request {};
  using Result = CallbackResult<Response>;
  virtual async::Run<Result> OnInfo(const Request& req) const = 0;
};

//---------------------
// Bucket API
//---------------------

/**
 * Create bucket callback
 */
class ICreateBucketCallback {
 public:
  struct Response {};
  struct Request {
    std::string_view name;
  };
  using Result = CallbackResult<Response>;
  virtual async::Run<Result> OnCreateBucket(const Request& req) = 0;
};

/**
 * Get bucket callback
 */
class IGetBucketCallback {
 public:
  struct Response {};
  struct Request {
    std::string_view name;
  };
  using Result = CallbackResult<Response>;
  virtual async::Run<Result> OnGetBucket(const Request& req) const = 0;
};

/**
 * Remove bucket callback
 */
class IRemoveBucketCallback {
 public:
  struct Response {};
  struct Request {
    std::string_view name;
  };
  using Result = CallbackResult<Response>;
  virtual async::Run<Result> OnRemoveBucket(const Request& req) = 0;
};

//---------------------
// Entry API
//---------------------

class IWriteEntryCallback {
 public:
  struct Response {};
  struct Request {
    std::string_view bucket_name;
    std::string_view entry_name;
    std::string_view timestamp;
    std::string_view blob;
  };

  using Result = CallbackResult<Response>;
  virtual async::Run<Result> OnWriteEntry(const Request& req) = 0;
};

class IReadEntryCallback {
 public:
  struct Response {
    std::string blob;
    std::string timestamp;
  };
  struct Request {
    std::string_view bucket_name;
    std::string_view entry_name;
    std::string_view timestamp;
  };

  using Result = CallbackResult<Response>;
  virtual async::Run<Result> OnReadEntry(const Request& req) = 0;
};

}  // namespace reduct::api
#endif  // REDUCT_STORAGE_CALLBACKS_H