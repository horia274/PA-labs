#include <bits/stdc++.h>
using namespace std;

struct Object {
    int weight;
    int price;

    Object(int _weight, int _price)
        : weight(_weight)
        , price(_price) { }
};

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, w;
    vector<Object> objs;

    void read_input() {
        ifstream fin("in");
        fin >> n >> w;
        for (int i = 0, weight, price; i < n; i++) {
            fin >> weight >> price;
            objs.push_back(Object(weight, price));
        }
        fin.close();
    }

    static bool cmp_obj(Object& o1, Object& o2) {
        return ((double) o1.price / o1.weight) >= ((double) o2.price / o2.weight);
    }

    double get_result() {
        // TODO: Aflati profitul maxim care se poate obtine cu obiectele date.
        double total_weight = 0;
        double total_profit = 0;
        int i = 0;

        sort(objs.begin(), objs.end(), cmp_obj);

        cout << n << " " << w << "\n";
        for (i = 0; i < n; i++) {
            cout << objs[i].price << " " << objs[i].weight << "\n";
        }

        cout << "\n";

        i = 0;
        while (i < n && total_weight < w) {
            if (total_weight + objs[i].weight <= w) {
                total_weight += objs[i].weight;
                total_profit += objs[i].price;
                i++;
            } else if (total_weight < w) {
                total_profit += (objs[i].price * (w - total_weight) / objs[i].weight);
                total_weight = w;
                i++;
            }
            cout << total_profit << "\n";
        }

        return total_profit;
    }

    void print_output(double result) {
        ofstream fout("out");
        fout << setprecision(4) << fixed << result;
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
