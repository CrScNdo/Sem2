#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void merge(const string& output, const string& input1, const string& input2)
{
    ifstream in1(input1), in2(input2);
    ofstream out(output);
    int val1, val2;
    bool hasVal1 = !!(in1 >> val1), hasVal2 = !!(in2 >> val2);
    while (hasVal1 && hasVal2)
    {
        if (val1 <= val2) { out << val1 << " "; hasVal1 = !!(in1 >> val1); }
        else { out << val2 << " "; hasVal2 = !!(in2 >> val2); }
    }
    while (hasVal1) { out << val1 << " "; hasVal1 = !!(in1 >> val1); }
    while (hasVal2) { out << val2 << " "; hasVal2 = !!(in2 >> val2); }
    in1.close(); in2.close(); out.close();
}

void distribute(const string& input, const vector<string>& tapes)
{
    ifstream in(input);
    if (!in.is_open()) return;
    vector<ofstream> outs;
    for (const auto& tape : tapes) outs.emplace_back(tape);
    int current, next;
    if (!(in >> current)) return;
    size_t tapeIdx = 0;
    outs[tapeIdx] << current << " ";
    while (in >> next)
    {
        if (next < current) tapeIdx = (tapeIdx + 1) % tapes.size();
        outs[tapeIdx] << next << " ";
        current = next;
    }
    for (auto& out : outs) out.close();
    in.close();
}

void naturalMergeSort(const string& inputFile, const string& outputFile, int k = 3)
{
    if (k < 2) return;
    vector<string> tapes(k);
    for (int i = 0; i < k; ++i) tapes[i] = "temp_tape_" + to_string(i) + ".txt";
    distribute(inputFile, tapes);
    string tempFile = "temp_merge.txt";
    int activeTapes = k;
    while (activeTapes > 1)
    {
        int tape1 = -1, tape2 = -1;
        for (int i = 0; i < k; ++i)
        {
            ifstream f(tapes[i]);
            if (f.peek() != EOF)
            {
                if (tape1 == -1) tape1 = i;
                else if (tape2 == -1) tape2 = i;
            }
            f.close();
        }
        if (tape2 == -1) break;
        merge(tempFile, tapes[tape1], tapes[tape2]);
        remove(tapes[tape1].c_str());
        remove(tapes[tape2].c_str());
        rename(tempFile.c_str(), tapes[tape1].c_str());
        activeTapes--;
    }
    for (int i = 0; i < k; ++i)
    {
        ifstream f(tapes[i]);
        if (f.peek() != EOF)
        {
            f.close();
            remove(outputFile.c_str());
            rename(tapes[i].c_str(), outputFile.c_str());
            break;
        }
        f.close();
    }
    for (const auto& tape : tapes) remove(tape.c_str());
}

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;
    int* arr = new int[n];
    ofstream file("input.txt");
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 - 50;
        file << arr[i] << " ";
        cout << arr[i] << " ";
    }
    cout << endl;
    file.close();
    naturalMergeSort("input.txt", "output_sorted.txt", 10);
    cout << "Sorted: ";
    ifstream sorted("output_sorted.txt");
    int x;
    while (sorted >> x) cout << x << " ";
    cout << endl;
    sorted.close();
    delete[] arr;
    return 0;
}
