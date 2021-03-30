#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, m;
    vector<int> dist;

    void read_input() {
        ifstream fin("in");
        fin >> n >> m;
        for (int i = 0, d; i < n; i++) {
            fin >> d;
            dist.push_back(d);
        }
        fin.close();
    }

    int get_result() {
        // TODO: Aflati numarul minim de opriri necesare pentru a ajunge
        // la destinatie.

        int d = dist[0];
        int remained_fuel = m;
        int i = 0, j;
        int count = (d == m) ? 1 : 0;

        while (i < n - 1) {
            j = i;
            
            while (remained_fuel >= d) {
                j++;
                remained_fuel -= d;
                d = dist[j] - dist[j - 1];
            }

            i = j;
            remained_fuel = m;
            if (i < n - 1) {
                count++;
            }
        }

        return count;
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (std::nothrow) Task{}; // hint: cppreference/nothrow
    if (!task) {
        std::cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
