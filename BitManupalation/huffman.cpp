#include <bits/stdc++.h>
using namespace std;

int printCodes(vector<int>& parent, vector<int>& left, vector<int>& right, string str, int node, vector<int>& freq) {
    if (node == -1) return 0;

    if (left[node] == -1 && right[node] == -1) {
        cout << (char)('a' + node) << ": " << str << "\n";
        return freq[node] * str.length();
    }

    int leftBits = printCodes(parent, left, right, str + "0", left[node], freq);
    int rightBits = printCodes(parent, left, right, str + "1", right[node], freq);

    return leftBits + rightBits;
}

void HuffmanCodes(vector<int>& freq) {
    int n = freq.size();
    vector<int> parent(2 * n - 1, -1), left(2 * n - 1, -1), right(2 * n - 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        pq.push({freq[i], i});
    }

    int nextNode = n;

    while (pq.size() > 1) {
        int leftNode = pq.top().second;
        pq.pop();
        int rightNode = pq.top().second;
        pq.pop();

        int newFreq = freq[leftNode] + freq[rightNode];
        parent[leftNode] = nextNode;
        parent[rightNode] = nextNode;
        left[nextNode] = leftNode;
        right[nextNode] = rightNode;
        freq.push_back(newFreq);

        pq.push({newFreq, nextNode});
        nextNode++;
    }

    int huffmanCompressedBits = printCodes(parent, left, right, "", pq.top().second, freq);

    int uniformBitsPerChar = ceil(log2(n)); 
    int uniformCompressedBits = 0;
    for (int i = 0; i < n; i++) {
        uniformCompressedBits += freq[i] * uniformBitsPerChar;
    }
    float cr = (float)huffmanCompressedBits/ (float)uniformCompressedBits;
    cout << "Total bits with uniform coding: " << uniformCompressedBits << "\n";
    cout << "Total compressed bits with Huffman coding: " << huffmanCompressedBits << "\n";
    cout << "Total compression ratio : " << setprecision(3) << cr;

}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<int> freq(n);

    cout << "Enter the frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    HuffmanCodes(freq);
    return 0;
}