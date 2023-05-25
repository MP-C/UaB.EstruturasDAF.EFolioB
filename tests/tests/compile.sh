cd ..
g++ -g -c minh.cpp -o minh.o
g++ -g -c main-minh.cpp -o main-minh.o
g++ -g main-minh.o minh.o -o program.out
cd tests/