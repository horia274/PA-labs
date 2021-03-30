#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x, y;

    void read_input() {
        ifstream fin("in");
        fin >> n >> x >> y;
        fin.close();
    }

    int get_value_recursive(int n, int x, int y) {
        // TODO: Calculati valoarea de pe pozitia (x, y) din matricea de dimensiune 2^n x 2^n
        if (n == 0) {
            return 1;
        }

        int pow_n_1 = 1 << (n - 1);
        int pow_2n_2 = pow_n_1 * pow_n_1;

        if (x <= pow_n_1 && y <= pow_n_1) {
            return get_value_recursive(n - 1, x, y);
        } else if (x <= pow_n_1 && y > pow_n_1) {
            return get_value_recursive(n - 1, x, y - pow_n_1) + pow_2n_2;
        } else if (x > pow_n_1 && y <= pow_n_1){
            return get_value_recursive(n - 1, x - pow_n_1, y) + 2 * pow_2n_2;
        } else {
            return get_value_recursive(n - 1, x - pow_n_1, y - pow_n_1) + 3 * pow_2n_2;
        }
    }

    int get_value_iterative(int n, int x, int y) {
        int x1 = 1, x2 = 1 << n;
        int y1 = 1, y2 = 1 << n;
        int xmid, ymid, ans = 0;

        while (x1 < x2 && y1 < y2) {
            xmid = (x1 + x2) / 2;
            ymid = (y1 + y2) / 2;
            if (x <= xmid && y <= ymid) {
                x2 = xmid;
                y2 = ymid;
            } else if (x > xmid && y <= ymid) {
                ans += 2 * (1 << (2 * n - 2));
                x1 = xmid + 1;
                y2 = ymid;
            } else if (x <= xmid && y > ymid) {
                ans += (1 << (2 * n - 2));
                x2 = xmid;
                y1 = ymid + 1;
            } else {
                ans += 3 * (1 << (2 * n - 2));
                x1 = xmid + 1;
                y1 = ymid + 1;
            }
            n--;
        }
        
        return ans + 1;
    }

    int get_value(int n, int x, int y) {
        // return get_value_recursive(n, x, y);
        return get_value_iterative(n, x, y);
    }

    int get_result() { return get_value(n, x, y); }

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
