rm -rf ./application/build
mkdir ./application/build 
cd ./application/build
cmake ..
make lenet.app -j
make lenet
