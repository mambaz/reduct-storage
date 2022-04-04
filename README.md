# Reduct Storage

![GitHub release (latest SemVer)](https://img.shields.io/github/v/release/reduct-storage/reduct-storage)
![GitHub Workflow Status](https://img.shields.io/github/workflow/status/reduct-storage/reduct-storage/ci)

A time series storage to keep history of blob data.

Reduct Storage aims to solve the problem of storing data in a case where you need to write some data intensively and read it accidentally by some time interval. 
The storage uses HTTP API and stores the data as blobs. Read more [here](https://docs.reduct-storage.dev/).

## Features:

* HTTP(S) API
* Storing and access blobs as time series
* Optimized for little files
* Real-time quota for buckets
* Token authentication

## Get started

The easiest way to start is to use Docker image:

```shell
docker run -p 8383:8383 -v ${PWD}/data:/data ghcr.io/reduct-storage/reduct-storage:main
```

## Try one of SDKs;

* [Python Client SDK](https://github.com/reduct-storage/reduct-py)
* [C++ Client SDK](https://github.com/reduct-storage/reduct-cpp)
* or use [HTTP API](https://docs.reduct-storage.dev/http-api)
