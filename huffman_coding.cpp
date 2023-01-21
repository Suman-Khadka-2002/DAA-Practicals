#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Node struct represents each node in the Huffman tree
struct Node {
  char ch;                                 // character that represents the node
  int freq;                                // frequency of the character
  Node *left, *right;                      // pointers to the left and right children of the node
};

// Compare struct is used to compare the nodes in the priority queue based on their frequency
struct Compare {
  bool operator()(Node *a, Node *b) {
    return a->freq > b->freq;
  }
};

// function to build a frequency table of the characters in the input string
void buildFrequencyTable(string input, unordered_map<char, int> &freqTable) {
  for (char ch : input) {
    freqTable[ch]++;                      // increment the count of each character in the frequency table
  }
}

// function to construct the Huffman tree
Node* buildHuffmanTree(unordered_map<char, int> &freqTable) {
  priority_queue<Node*, vector<Node*>, Compare> pq; // create a priority queue
  for (auto pair : freqTable) {
    Node *node = new Node();
    node->ch = pair.first;                           // set the character
    node->freq = pair.second;                        // set the frequency
    node->left = node->right = nullptr;
    pq.push(node);                                   // add the leaf node to the priority queue
  }
  // repeatedly remove the two nodes with the lowest frequency from the queue
  // create a new internal node with the sum of the frequencies of the removed nodes as its value
  // set the left child of the new node to be the node with the lowest frequency 
  // set the right child to be the node with the second-lowest frequency 
  // add the new node to the priority queue
  while (pq.size() > 1) {
    Node *left = pq.top(); pq.pop();
    Node *right = pq.top(); pq.pop();
    Node *node = new Node();
    node->freq = left->freq + right->freq;
    node->left = left;
    node->right = right;
    pq.push(node);
  }
  return pq.top();                                    // the remaining node in the queue is the root of the Huffman tree
}

// function to traverse the Huffman tree and assign a code to each character
void buildEncodingTable(Node *root, string str, unordered_map<char, string> &encodingTable) {
  if (!root) return;                                 // base case
  if (!root->left && !root->right) {                 // if current node is a leaf node
    encodingTable[root->ch] = str;                   // assign the string to the corresponding character in the encoding table
  }
  buildEncodingTable(root->left, str + "0", encodingTable);  // recursively call the function for the left child and append 0
  buildEncodingTable(root->right, str + "1", encodingTable); //

}
// function to compress the input string
string compress(string input, unordered_map<char, string> &encodingTable) {
  string compressed = "";
  for (char ch : input) {
    compressed += encodingTable[ch];
  }
  return compressed;
}

int main() {
  string input = "suman khadka";
  unordered_map<char, int> freqTable;
  buildFrequencyTable(input, freqTable);
  Node *root = buildHuffmanTree(freqTable);
  unordered_map<char, string> encodingTable;
  buildEncodingTable(root, "", encodingTable);
  string compressed = compress(input, encodingTable);
  cout << "Original: " << input << endl;
  cout << "Compressed: " << compressed << endl;
  return 0;
}
