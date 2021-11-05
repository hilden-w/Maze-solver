disabled checks:
To avoid warnings generated from the code given by the starter files:
    -llvm-include-order
    -cppcoreguidelines-pro-bounds-constant-array-index
    -cppcoreguidelines-pro-type-member-init 
    -hicpp-member-init
To avoid warnings generated from not declaring the Maze and Path as constant or a pointer
even though I modify them within the methods:
    -google-runtime-references