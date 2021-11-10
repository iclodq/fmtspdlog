# 依赖目录一览
```
deps
├── bin
│   ├── protoc
│   └── protoc.exe
├── include
│   ├── fmt
│   ├── google
│   └── spdlog
├── lib
│   ├── cmake
│   ├── fmt.lib
│   ├── fmtd.lib
│   ├── libfmt.a
│   ├── libfmtd.a
│   ├── libspdlog.a
│   ├── libspdlogd.a
│   ├── pkgconfig
│   ├── spdlog.lib
│   └── spdlogd.lib
└── src
    ├── fmt
    ├── readme.md
    └── spdlog
```

# 编译环境

- Centos 7.2 64  
- gcc-8.3.1-3  


需要把依赖库源码解压在 deps/src/中，然后进入到`deps/src/fmt`，执行`mkdir build && cd build`，随后执行相应的编译命令  
最终，如果设置正确后，会把相应结果拷贝到对应的目录中，如果没有，可以手动拷贝  



# 相关依赖库编译
## fmt

### version = 8.0.1

### compile

#### to static library
```
## MSVC  
mkdir build && cd build
cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE  -DCMAKE_INSTALL_PREFIX="../../.." -DCMAKE_CXX_STANDARD=17 .. 
cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE  -DCMAKE_INSTALL_PREFIX="../../.." -DCMAKE_CXX_STANDARD=17 -DCMAKE_BUILD_TYPE=Debug .. 
cmake --build . --target fmt --config Release
cmake --build . --target fmt --config Debug
cmake --install . --prefix ../../../ --config Release
cmake --install . --prefix ../../../ --config Debug
```

## sdplog

### version = 1.9.2

### compile
```
mkdir build && cd build
cmake -D SPDLOG_FMT_EXTERNAL=ON  -DCMAKE_INSTALL_PREFIX="../../.." -DMAKE_CXX_STANDARD=17 -DSPDLOG_BUILD_EXAMPLE=OFF -DSPDLOG_FMT_EXTERNAL=ON ..
cmake -D SPDLOG_FMT_EXTERNAL=ON  -DCMAKE_INSTALL_PREFIX="../../.." -DMAKE_CXX_STANDARD=17 -DSPDLOG_BUILD_EXAMPLE=OFF -DSPDLOG_FMT_EXTERNAL=ON -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --target spdlog --config Release
cmake --build . --target spdlog --config Debug
cmake --install . --prefix ../../../ --config Release
cmake --install . --prefix ../../../ --config Debug
cmake --install . --config Release

```
#### to static library


## fmtspdlog

### compile fmtspdlog

```
cmake -DSPDLOG_FMT_EXTERNAL=ON -DCMAKE_CXX_STANDARD=17 .. 
cmake --build . --target fmtspdlog --config Release
cmake --build . --target fmtspdlog --config Debug
```

## protobuf

### version = 3.17.0

