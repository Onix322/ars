#!/bin/bash
cmake -S ./test -B ./out/test -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build ./out/test
./test/out/myapptest

