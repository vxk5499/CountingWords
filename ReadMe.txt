Data Structures Used

Here a 26-ary tree data structure in which each node consists of data member and atmost 26 child nodes. The dictionary of words is represented 
using this data structure.

Algorithm Description

64 searches are done beginning from each position in the cube. Now the successors in the search are decided based on the adjanceny matrix which
again is optimized using the tree representation of the dictionary.
This way we visit only the nodes that are in valid position to form a meaningful word in the dictionary. We keep track of the visited nodes
to avoid cycles in the graph.



Note: Place all the files in a single directory for compilation and execution of the code.

