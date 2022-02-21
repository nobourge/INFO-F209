mkdir bin
cd bin || return
cmake ..
cmake --build . --target ClientSide
./src/client_side/ClientSide