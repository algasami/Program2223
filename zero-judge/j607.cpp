#include <bits/stdc++.h>

using namespace std;

char raw[10007], priority[1007];
int len;

inline int64_t operate(int64_t a, int64_t b, char op)
{
    int64_t result = 0;
    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '*':
        result = a * b;
        break;
    default:
        break;
    }
    return result;
}

template <typename T> inline pair<T, T> pop2(stack<T> &stk)
{
    T tmp, tmp2;
    tmp = stk.top();
    stk.pop();
    tmp2 = stk.top();
    stk.pop();
    return make_pair(tmp, tmp2);
}

// forward declaration
int64_t eval(int *, int);
int64_t eval_function(int *);

int64_t eval_function(int *index_ptr) // start (return finish after function read!!!)
{
    int64_t max_num = 0, min_num = INT64_MAX - 1;
    *index_ptr += 1;
    do
    {
        char ch = raw[*index_ptr];
        if (ch == ')')
            break;
        if (ch == ',' || ch == ' ' || ch == '(')
        {
            (*index_ptr)++;
            continue;
        }
        int64_t result = eval(index_ptr, len); // should make index_ptr equal ','
        max_num = max(max_num, result);
        min_num = min(min_num, result);
    } while (1);
    if (max_num - min_num < 0)
        return 0;

    return max_num - min_num; // temporary
}

int64_t eval(int *index_ptr, int f) // f is not included
{
    stack<int64_t> value_stk;
    stack<char> op_stk;
    int64_t number = 0;
    do
    {
        char ch = raw[*index_ptr];
        if (ch == ',' || ch == ')')
            break;
        if (ch == ' ')
        {
            (*index_ptr)++;
            continue;
        }

        if (isdigit(ch))
        {
            if (ch == '0' && number == 0)
                value_stk.push(0);
            else
                number = 10 * number + (ch - '0');
        }
        else
        {
            // append operand first
            // (so no seg-fault when dealing with 1+2+3 // forgot to append 2)
            if (number)
            {
                value_stk.push(number);
                number = 0;
            }
            int p;
            if (p = priority[ch])
            {
                // this is an operator
                if (!op_stk.empty())
                {
                    char top_op = op_stk.top();
                    if (priority[top_op] >= p)
                    { // top has higher priority
                        op_stk.pop();
                        auto value_pair = pop2(value_stk);
                        int64_t result = operate(value_pair.second, value_pair.first, top_op);
                        value_stk.push(result);
                    }
                }

                op_stk.push(ch);
            }
            else if (ch == 'f')
            {
                // this is a function move i to this position after evaluation
                value_stk.push(eval_function(index_ptr));
            }
        }
        (*index_ptr)++;
    } while (*index_ptr < f);
    if (number)
        value_stk.push(number);

    while (!op_stk.empty())
    {
        auto value_pair = pop2(value_stk);
        char top_op = op_stk.top();
        int64_t result = operate(value_pair.second, value_pair.first, top_op);
        value_stk.push(result);
        op_stk.pop();
    }

    int64_t tmp = value_stk.top();
    value_stk.pop();
    return tmp;
}

int main()
{
    memset(priority, 0, sizeof(priority));
    priority['+'] = 2;
    priority['*'] = 1;
    scanf("%s", raw);
    len = strlen(raw);
    int point = 0;
    int64_t result = eval(&point, len);
    printf("%lld\n", result);

    return 0;
}