glslang -V ./src/defaults/default.vert -o ./src/defaults/compiled_shaders/default.vert.spv
glslang -V ./src/defaults/default.frag -o ./src/defaults/compiled_shaders/default.frag.spv

cmake .;
make;
./lina;

