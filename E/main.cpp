#include <windows.h>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

// list<string> shuntingYardAlgorithm(const string &equation);
// Funkcija shuntingYardAlgorithm(equation) -
// Paņem matemātisko izteiksmi (equation) augta līmeņa simbolu virknes formā, un
// atgriež to apgrieztajā poļu pierakstā, kā augsta līmeņa simbolu virkņu
// sarakstu.
list<string> shuntingYardAlgorithm(const string &equation);

// double evaluateReversePolishNotation(const list<string> &equation);
// Funkcija evaluateReversePolishNotation(equation) -
// Paņem matematisko izteiksmi apgrieztā poļu pieraksta forma (equation),
// kā augsta līmeņa simbolu virkņu sarakstu, un atgriež tas rezultātu, kā
// double vertību
double evaluateReversePolishNotation(const list<string> &equation);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    while (true)
    {
        cout << "Ievadiet izteiksmi: ";
        string equation;
        getline(cin, equation);
        if (equation.empty())
        {
            break;
        }

        list<string> rev_Pol_not = shuntingYardAlgorithm(equation);
        cout << "Izteiksme apgrieztajā poļu pierakstā: ";
        for (const auto &i : rev_Pol_not)
        {
            cout << i << " ";
        }
        cout << endl;

        cout << "Izteiksmes rezultāts: " << evaluateReversePolishNotation(rev_Pol_not) << endl;
    }

    return 0;
}

list<string> shuntingYardAlgorithm(const string &equation)
{
    map<char, int> op_precedence({{'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'^', 4}});
    // 1 priekš kreisas asocivitātes, 2 priekš labās.
    map<char, bool> op_associativity({{'+', 1}, {'-', 1}, {'*', 1}, {'/', 1}, {'^', 0}});

    stack<char> op_stack;

    list<string> ans;

    for (auto i = equation.begin(); i != equation.end(); ++i)
    {
        // Ja atrod ciparu, punktu vai mīnus zīmi, kas ir izteiksmes sākuma vai
        // tieši aiz atverošajām iekāvam saglabā to saraksta beigās.
        if (((i == equation.begin() || *(i - 1) == '(') && *i != '(') ||
            (*i >= '0' && *i <= '9') || *i == '.')
        {
            string number = {*(i++)};
            while ((*i >= '0' && *i <= '9') || *i == '.')
            {
                number.push_back(*(i++));
            }

            ans.push_back(number);

            if (i == equation.end())
            {
                break;
            }
        }

        // Atverošas iekavas tiek pievienotas operandu kaudzei.
        if (*i == '(')
        {
            op_stack.push(*i);
        }
        // Aizverošas iekavas izraisa operandu kaudzes iztukšošanu līdz tiek
        // sasniegtas atverošas iekavas.
        else if (*i == ')')
        {
            while (true)
            {
                // Ja atverošas iekavas netiek atrastas ievadīta izteiksme
                // ir nekorekta.
                if (op_stack.empty())
                {
                    cout << "Iekavu neatbilstība!" << endl;
                    return list<string>({"0"});
                }
                else if (op_stack.top() == '(')
                {
                    op_stack.pop();
                    break;
                }

                ans.push_back({op_stack.top()});
                op_stack.pop();
            }
        }
        // Operātori tiek ievietoti kaudzē, bet vispirms no tās tiek izņemti
        // tie kuriem, kuriem ir augstāka prioritāte vai vienāda prioritāte
        // un kreisā associvitāte, lai darbības tiktu pārveitotas uz pareizu
        // secību
        else if (op_precedence.count(*i))
        {
            while (!op_stack.empty() && (op_precedence[*i] < op_precedence[op_stack.top()] ||
                                         (op_precedence[*i] == op_precedence[op_stack.top()] &&
                                          op_associativity[*i])))
            {
                ans.push_back({op_stack.top()});
                op_stack.pop();
            }
            op_stack.push(*i);
        }
    }

    // Beigās operātoru kaudze tiek iztukšota.
    while (!op_stack.empty())
    {
        ans.push_back({op_stack.top()});
        op_stack.pop();
    }

    return ans;
}

double evaluateReversePolishNotation(const list<string> &equation)
{
    stack<double> operand_stack;

    for (const auto &i : equation)
    {
        // Ja elements ir skaitlis tas tiek pievienots operandu kaudzei
        char *end = nullptr;
        double val = strtod(i.c_str(), &end);
        if (end != i.c_str() && *end == '\0' && val != HUGE_VAL)
        {
            operand_stack.push(val);
            continue;
        }

        // Ja operandu kaudzē nav vismaz divi elementi, tad darbība nevar
        // tikt izpildīta un ir tikusi ievadīta nekorekta izteiksme.
        if (operand_stack.size() < 2)
        {
            cout << "Nekorekta izteiksme!" << endl;
            return 0;
        }

        // Uz diviem augšejajiem kaudzes elementiem tiek izpildīta darbiba
        // un rezultāts ielikts atpakaļ kaudzē.
        double a, b, ab;
        b = operand_stack.top();
        operand_stack.pop();
        a = operand_stack.top();
        operand_stack.pop();

        switch ((int)i[0])
        {
        case '+':
        {
            ab = a + b;
            break;
        }
        case '-':
        {
            ab = a - b;
            break;
        }
        case '*':
        {
            ab = a * b;
            break;
        }
        case '/':
        {
            if (b == 0)
            {
                cout << "Dalīšana ar nulli!" << endl;
                return 0;
            }
            ab = a / b;
            break;
        }
        case '^':
        {
            ab = pow(a, b);
            break;
        }
        }
        operand_stack.push(ab);
    }

    return operand_stack.top();
}

//               Ievads | Izvads
// ---------------------|-----------------------------------------------------
//                ((1)) | 1
//                      | 1
// ---------------------|-----------------------------------------------------
//        5 + 7 / 2 ^ 2 | 5 7 2 2 ^ / +
//                      | 6.75
// ---------------------|-----------------------------------------------------
//          3.5 + 4 * 2 | 3.5 4 2 * +
//                      | 11.5
// ---------------------|-----------------------------------------------------
//                5 / 0 | 5 0 /
//                      | Dalīšana ar nulli!
// ---------------------|-----------------------------------------------------
//             (5 + 3)) | Iekavu neatbilstība!
// ---------------------|-----------------------------------------------------
//                + 3 3 | + 3 3
//                      | Nekorekta izteiksme
