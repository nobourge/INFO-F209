mkdir bin
cd bin || return
cmake ..
cmake --build . --target QuoridorServer
./src/server_side/QuoridorServer