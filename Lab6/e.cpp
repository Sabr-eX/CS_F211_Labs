#include <iostream>
#include <deque>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    deque<long long> window[k];
    deque<long long> max[k];
    max->push_front(a[0]);
    for (int i = 0; i < k - 1; i++)
    {

        if (window->size() == k)
        {
            window->pop_back();
        }
        if (max->size() == k)
        {
            max->pop_back();
        }
        window->push_front(a[i]);
        if (a[i] <= max->front())
        {
            max->push_front(a[i]);
        }
        else if (a[i] > max->back())
        {
            max->clear();
            max->push_front(a[i]);
        }
        else
        {
            for (auto j = max->begin(); j != max->end(); j++)
            {
                if (*j <= a[i])
                {
                    max->erase(j);
                }
                else
                {
                    max->emplace_front(a[i]);
                }
            }
        }
    }

    for (int i = k - 1; i < n; i++)
    {
        if (window->size() == k)
        {
            window->pop_back();
        }
        window->push_front(a[i]);
        if (max->size() == k)
        {
            max->pop_back();
        }
        if (a[i] < max->front())
        {
            max->push_front(a[i]);
        }
        else if (a[i] >= max->back())
        {
            max->clear();
            max->push_front(a[i]);
        }
        else
        {
            for (auto j = max->begin(); j != max->end(); j++)
            {
                if (*j <= a[i])
                {
                    max->erase(j);
                }
                else
                {
                    max->emplace_front(a[i]);
                }
            }
        }
        cout << max->back() << " ";
    }
    return 0;
}