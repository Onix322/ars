#!/bin/bash
cmake -S . -B out -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build out
./out/myapp
