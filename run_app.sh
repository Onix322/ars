#!/bin/bash
cmake -S . -B ./out -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
      -DCMAKE_CXX_FLAGS="-fsanitize=address -fno-omit-frame-pointer"

cmake --build ./out
./out/myapp -t /home/alex/text_from_app.desktop --Desktop_Entry::Terminal=True
