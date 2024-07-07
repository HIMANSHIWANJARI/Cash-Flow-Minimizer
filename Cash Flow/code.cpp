#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the index of the minimum value in arr[]
int getMin(const vector<int>& arr, int n) {
    int minInd = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minInd]) {
            minInd = i;
        }
    }
    return minInd;
}

// Function to find the index of the maximum value in arr[]
int getMax(const vector<int>& arr, int n) {
    int maxInd = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxInd]) {
            maxInd = i;
        }
    }
    return maxInd;
}

// Function to return the minimum of two values
int minOf2(int x, int y) {
    return (x < y) ? x : y;
}

// Function to minimize cash flow among banks
void minCashFlow(vector<vector<int> >& graph, int n, vector<string>& names) {
    vector<int> amount(n, 0);

    // Calculate the net amount to be paid to each bank
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n; i++) {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }

    while (true) {
        int mxCredit = getMax(amount, n);
        int mxDebit = getMin(amount, n);

        if (amount[mxCredit] == 0 && amount[mxDebit] == 0) {
            break;
        }

        int min = minOf2(-amount[mxDebit], amount[mxCredit]);
        amount[mxCredit] -= min;
        amount[mxDebit] += min;

        cout << names[mxDebit] << " pays " << min << " to " << names[mxCredit] << endl;
    }
}

int main() {
    int n;
    vector<string> names;
    vector<vector<int> > graph;

    cout<< "============================================================== $$ CASH FLOW MINIMIZER $$ =============================================================="<<endl<<endl;

    cout << "Enter the number of Banks: ";
    cin >> n;

    if (n < 2) {
        cout << "Invalid number of banks. Program exiting." << endl;
        return 1;
    }

    names.resize(n);
    graph.resize(n, vector<int>(n, 0));

    cin.ignore(); // Ignore newline character left in the buffer

    for (int i = 0; i < n; i++) {
        cout << "Enter the name of Bank " << i + 1 << ": ";
        getline(cin, names[i]); // Read entire line including spaces
    }

    cout<<endl;
    
    int transactions;
    cout << "Enter the number of transactions : ";
    cin >> transactions;
    cout<<"NOTE : Enter the data seprated by double space."<<endl<<endl;

    for (int t = 0; t < transactions; t++) {
        string debitor, creditor;
        int amount;
        cout << t+1<<")"<<"  "<< "Debitor Bank    Creditor Bank    Amount : ";
        cin >> debitor >> creditor >> amount;

        int debitorIndex = -1, creditorIndex = -1;
        for (int i = 0; i < n; i++) {
            if (names[i] == debitor) {
                debitorIndex = i;
            }
            if (names[i] == creditor) {
                creditorIndex = i;
            }
        }

        if (debitorIndex != -1 && creditorIndex != -1) {
            graph[debitorIndex][creditorIndex] += amount;
        } else {
            cout << "Invalid bank names entered." << endl;
        }
    }
    cout<<endl;

    cout << "Processing transactions to minimize cash flow:" << endl;
    minCashFlow(graph, n, names);
    cout<<endl;
    cout<< "====================================================== YAYYYY!!! YOU MINIMIZED THE CASH FLOW :) ======================================================"<<endl<<endl;



    return 0;
}
