#include <iostream>
using namespace std;

class Term {
public:
    int coeff;
    int expo;
};

class Polynomial {
public:
    Term* terms;
    int size;

    Polynomial(int s = 0) {
        size = s;
        if (s > 0)
            terms = new Term[s];
        else
            terms = nullptr;
    }

    ~Polynomial() {
        delete[] terms;
    }

    void getValue() {
        for (int i = 0; i < size; i++) {
            cout << "Coefficient [" << i << "]: ";
            cin >> terms[i].coeff;
            cout << "Exponent [" << i << "]: ";
            cin >> terms[i].expo;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << terms[i].coeff << "x^" << terms[i].expo;
            if (i != size - 1) cout << " + ";
        }
        cout << endl;
    }

    static Polynomial add(const Polynomial& p1, const Polynomial& p2) {
        int i = 0, j = 0, k = 0;
        Term* resultTerms = new Term[p1.size + p2.size];

        while (i < p1.size && j < p2.size) {
            if (p1.terms[i].expo > p2.terms[j].expo) {
                resultTerms[k++] = p1.terms[i++];
            }
            else if (p1.terms[i].expo < p2.terms[j].expo) {
                resultTerms[k++] = p2.terms[j++];
            }
            else {
                resultTerms[k].expo = p1.terms[i].expo;
                resultTerms[k].coeff = p1.terms[i].coeff + p2.terms[j].coeff;
                i++;
                j++;
                k++;
            }
        }

        while (i < p1.size) {
            resultTerms[k++] = p1.terms[i++];
        }

        while (j < p2.size) {
            resultTerms[k++] = p2.terms[j++];
        }

        Polynomial result(k);
        for (int idx = 0; idx < k; idx++) {
            result.terms[idx] = resultTerms[idx];
        }

        delete[] resultTerms;
        return result;
    }
};

int main() {
    int t1, t2;

    cout << "Enter number of terms in first polynomial: ";
    cin >> t1;
    Polynomial p1(t1);
    p1.getValue();

    cout << "Enter number of terms in second polynomial: ";
    cin >> t2;
    Polynomial p2(t2);
    p2.getValue();

    cout << "\nFirst Polynomial: ";
    p1.display();

    cout << "Second Polynomial: ";
    p2.display();

    Polynomial result = Polynomial::add(p1, p2);

    cout << "\nResultant Polynomial (Sum): ";
    result.display();

    return 0;
}
