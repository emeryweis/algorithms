/*
Self balancing tree
Any internal node can have either 2, 3 or 4 children
All leaves are on the same level (perfectly balanced tree)

A 2-node has 1 data element and if its an internal node it has 
2 child nodes
A 3-node has 2 data elements and if its internal it has 
3 child nodes
A 4-node has 3 data elements and if internal has 
4 child nodes

Elements in each node are sorted from smallest to largest

Each node can have 2, 3, or 4 children, each of which holds
1, 2, or 3 data elements respectively

Three operations are node insert, value search, node delete

When insert encounters a 3 key node (4 node), the middle key 
is placed in the parent node

*/

